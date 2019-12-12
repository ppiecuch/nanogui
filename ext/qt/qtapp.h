#include <qguiapplication.h>
#include <functional>

#include <qdebug.h>
#include <qevent.h>
#include <qtimer.h>
#include <qdiriterator.h>
#include <qelapsedtimer.h>
#include <qwaitcondition.h>
#include <qpainter.h>
#include <qwindow.h>
#include <qopengldebug.h>
#include <qopenglcontext.h>
#include <qopenglpaintdevice.h>
#include <qopenglfunctions.h>
#include <qelapsedtimer.h>
#include <qwindow.h>
#include <qguiapplication.h>

#include <nanogui/opengl.h>
#include <nanogui/screen.h>

class SleepSimulator {
    QMutex localMutex;
    QWaitCondition sleepSimulator;
public:
    SleepSimulator() { localMutex.lock(); }
    void sleep(unsigned long sleepMS) { sleepSimulator.wait(&localMutex, sleepMS); }
    void CancelSleep() { sleepSimulator.wakeAll(); }
};

class QNGuiWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
private:
    bool m_done, m_update_pending, m_resize_pending, m_auto_refresh;
    QOpenGLContext *m_context;
    QElapsedTimer m_timer;
    nanogui::Screen *m_sc;
public:
    QPoint cursorPos;
public:
    QNGuiWindow(nanogui::Screen *screen, QWindow *parent = 0) : QWindow(parent)
    , m_update_pending(false)
    , m_resize_pending(false)
    , m_auto_refresh(true)
    , m_context(0)
    , m_sc(screen)
    , m_done(false) {
        setSurfaceType(QWindow::OpenGLSurface);
        m_timer.start();
    }
    ~QNGuiWindow() { }
    void setAutoRefresh(bool a) { m_auto_refresh = a; }
    void initialize() {
        QOpenGLDebugLogger *m_logger = new QOpenGLDebugLogger(this);
        connect( m_logger, &QOpenGLDebugLogger::messageLogged, []( QOpenGLDebugMessage message ){
            qWarning() << "[OpenGL]" << message;
        });
        if ( m_logger->initialize() ) {
            m_logger->startLogging( QOpenGLDebugLogger::SynchronousLogging );
            m_logger->enableMessages();
            qDebug() << "QOpenGLDebugLogger initialized.";
        }
        qDebug() << "OpenGL infos with gl functions:";
        qDebug() << "-------------------------------";
        qDebug() << " Renderer:" << (const char*)glGetString(GL_RENDERER);
        qDebug() << " Vendor:" << (const char*)glGetString(GL_VENDOR);
        qDebug() << " OpenGL Version:" << (const char*)glGetString(GL_VERSION);
        qDebug() << " GLSL Version:" << (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
        setTitle(QString("Qt %1 - %2 (%3)").arg(QT_VERSION_STR).arg((const char*)glGetString(GL_VERSION)).arg((const char*)glGetString(GL_RENDERER)));
    }
    void update() { renderLater(); }
    void render() {
        glViewport(0, 0, width()*devicePixelRatio(), height()*devicePixelRatio());
        glClearColor(0.8, 0.8, 0.8, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width(), height(), 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        m_sc->draw_now();
    }
    void mousePressEvent(QMouseEvent *event) {
        cursorPos = QPoint(event->x(), event->y());
        int modifiers;
        if (event->modifiers() & Qt::ShiftModifier) modifiers |= NGUI_MOD_SHIFT;
        if (event->modifiers() & Qt::ControlModifier) modifiers |= NGUI_MOD_CONTROL;
        if (event->modifiers() & Qt::MetaModifier) modifiers |= NGUI_SYSTEM_COMMAND_MOD;
        int button;
        if (event->buttons() & Qt::LeftButton)  button = NGUI_MOUSE_BUTTON_LEFT;
        else if (event->buttons() & Qt::LeftButton)  button = NGUI_MOUSE_BUTTON_RIGHT;
        m_sc->mouse_button_callback_event(button, NGUI_PRESS, modifiers);
    }
    void mouseReleaseEvent(QMouseEvent *event) {
        cursorPos = QPoint(event->x(), event->y());
        int modifiers;
        if (event->modifiers() & Qt::ShiftModifier) modifiers |= NGUI_MOD_SHIFT;
        if (event->modifiers() & Qt::ControlModifier) modifiers |= NGUI_MOD_CONTROL;
        if (event->modifiers() & Qt::MetaModifier) modifiers |= NGUI_SYSTEM_COMMAND_MOD;
        int button;
        if (event->button() == Qt::LeftButton) button = NGUI_MOUSE_BUTTON_LEFT;
        else if (event->button() == Qt::RightButton) button = NGUI_MOUSE_BUTTON_RIGHT;
        m_sc->mouse_button_callback_event(button, NGUI_RELEASE, modifiers);
    }
    void mouseMoveEvent(QMouseEvent *event) {
        cursorPos = QPoint(event->x(), event->y());
        m_sc->cursor_pos_callback_event(event->x(), event->y());
    }
    void wheelEvent(QWheelEvent *event) {

    }
    void keyReleaseEvent(QKeyEvent* event) {
        int modifiers = 0;
        if (event->modifiers() & Qt::ShiftModifier) modifiers |= NGUI_MOD_SHIFT;
        if (event->modifiers() & Qt::ControlModifier) modifiers |= NGUI_MOD_CONTROL;
        if (event->modifiers() & Qt::MetaModifier) modifiers |= NGUI_SYSTEM_COMMAND_MOD;
        switch(event->key()) {
            case Qt::Key_Escape: close(); break;
            default:
                switch(event->key()) {
                    case Qt::Key_A:
                        m_sc->char_callback_event('a'); break;
                    case Qt::Key_C:
                        m_sc->char_callback_event('c'); break;
                    case Qt::Key_F:
                        m_sc->char_callback_event('f'); break;
                    case Qt::Key_V:
                        m_sc->char_callback_event('v'); break;
                    case Qt::Key_Plus:
                        m_sc->char_callback_event('-'); break;
                    case Qt::Key_Minus:
                        m_sc->char_callback_event('-'); break;
                    case Qt::Key_0:
                        m_sc->char_callback_event('0'); break;
                    case Qt::Key_1:
                        m_sc->char_callback_event('1'); break;
                    case Qt::Key_2:
                        m_sc->char_callback_event('2'); break;
                    case Qt::Key_3:
                        m_sc->char_callback_event('3'); break;
                    case Qt::Key_4:
                        m_sc->char_callback_event('4'); break;
                    case Qt::Key_5:
                        m_sc->char_callback_event('5'); break;
                    case Qt::Key_6:
                        m_sc->char_callback_event('6'); break;
                    case Qt::Key_7:
                        m_sc->char_callback_event('7'); break;
                    case Qt::Key_8:
                        m_sc->char_callback_event('8'); break;
                    case Qt::Key_9:
                        m_sc->char_callback_event('9'); break;
                    case Qt::Key_Left:
                        m_sc->key_callback_event(NGUI_KEY_LEFT, NGUI_KEY_LEFT, NGUI_RELEASE, modifiers); break;
                    case Qt::Key_Right:
                        m_sc->key_callback_event(NGUI_KEY_RIGHT, NGUI_KEY_LEFT, NGUI_RELEASE, modifiers); break;
                    case Qt::Key_Up:
                        m_sc->key_callback_event(NGUI_KEY_UP, NGUI_KEY_LEFT, NGUI_RELEASE, modifiers); break;
                    case Qt::Key_Down:
                        m_sc->key_callback_event(NGUI_KEY_DOWN, NGUI_KEY_LEFT, NGUI_RELEASE, modifiers); break;
                    default:
                        event->ignore();
                }
            break;
        }
    }
    void keyPressEvent(QKeyEvent* event) {
        int modifiers = 0;
        if (event->modifiers() & Qt::ShiftModifier) modifiers |= NGUI_MOD_SHIFT;
        if (event->modifiers() & Qt::ControlModifier) modifiers |= NGUI_MOD_CONTROL;
        if (event->modifiers() & Qt::MetaModifier) modifiers |= NGUI_SYSTEM_COMMAND_MOD;
        switch(event->key()) {
            case Qt::Key_Escape: close(); break;
            default:
                switch(event->key()) {
                    case Qt::Key_Left:
                        m_sc->key_callback_event(NGUI_KEY_LEFT, NGUI_KEY_LEFT, NGUI_PRESS, modifiers); break;
                    case Qt::Key_Right:
                        m_sc->key_callback_event(NGUI_KEY_RIGHT, NGUI_KEY_LEFT, NGUI_PRESS, modifiers); break;
                    case Qt::Key_Up:
                        m_sc->key_callback_event(NGUI_KEY_UP, NGUI_KEY_LEFT, NGUI_PRESS, modifiers); break;
                    case Qt::Key_Down:
                        m_sc->key_callback_event(NGUI_KEY_DOWN, NGUI_KEY_LEFT, NGUI_PRESS, modifiers); break;
                    default:
                        event->ignore();
                }
            break;
        }
    }
    void quit() { m_done = true; }
    bool shouldClose() const { return m_done; }
    bool isReady() const { return m_context != 0; }
    qint64 elapsed() { return m_timer.elapsed(); }
protected:
    void closeEvent(QCloseEvent *event) { Q_EMIT notifyShouldClose(true); quit(); }
    bool event(QEvent *event) {
        switch (event->type()) {
            case QEvent::UpdateRequest:
                m_update_pending = false;
                renderNow();
                return true;
            default:
                return QWindow::event(event);
        }
    }
    void exposeEvent(QExposeEvent *event) {
        Q_UNUSED(event);
        if (isExposed()) renderNow();
    }
    void resizeEvent(QResizeEvent *event)
    {
        m_sc->resize_callback_event(event->size().width(), event->size().height());
        renderLater();
    }
public Q_SLOTS:
    void resizeLater(int w, int h) {
        QTimer::singleShot(0, [=](){
            resize(w,h);
        });
    }
    void renderLater() {
        if (!m_update_pending) {
            m_update_pending = true;
            QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
        }
    }
    void renderNow() {
        if (!isExposed()) return;
        bool needsInitialize = false;
        if (!m_context) {
            m_context = new QOpenGLContext(this);
            m_context->setFormat(requestedFormat());
            m_context->create();
            needsInitialize = true;
        }
        m_context->makeCurrent(this);
        if (needsInitialize) {
            initializeOpenGLFunctions();
            initialize();
        }
        render();
        m_context->swapBuffers(this);
        if (m_auto_refresh) renderLater();
    }
Q_SIGNALS:
    void notifyShouldClose(bool);
};


class QNGuiApplication : public QGuiApplication
{
    Q_OBJECT
public:
    QNGuiApplication(int argc, char *argv[]) : QGuiApplication(argc, argv)
    {
        QSurfaceFormat format;
        format.setAlphaBufferSize(8);
        format.setStencilBufferSize(8);
        QSurfaceFormat::setDefaultFormat(format);
    }
    ~QNGuiApplication()
    {
    }
};
