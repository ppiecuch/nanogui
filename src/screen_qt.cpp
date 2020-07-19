/*
    src/screen_qt.cpp -- Top-level widget and interface between NanoGUI and Qt

    A significant redesign of this code was contributed by Christian Schueller.
    A significant redesign of this code was contributed by Pawel Piecuch.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/screen.h>
#include <nanogui/theme.h>
#include <nanogui/opengl.h>
#include <nanogui/window.h>
#include <nanogui/popup.h>
#include <nanogui/metal.h>
#include <map>
#include <iostream>

/* Allow enforcing the GL2 implementation of NanoVG */

#if defined(NANOGUI_USE_OPENGL) || defined(NANOGUI_USE_GLES)
#  if defined(NANOGUI_USE_OPENGL)
#    define NANOVG_GL2_IMPLEMENTATION
#  elif defined(NANOGUI_USE_GLES)
#    define NANOVG_GLES2_IMPLEMENTATION
#  endif
#  include <nanovg_gl.h>
#  include "opengl_check.h"
#elif defined(NANOGUI_USE_METAL)
#  include <nanovg_mtl.h>
#endif

#if !defined(GL_RGBA_FLOAT_MODE)
#  define GL_RGBA_FLOAT_MODE 0x8820
#endif

#include <map>
#include <iostream>

#include <qtapp.h>
#include <qcursor.h>
#include <qclipboard.h>


NAMESPACE_BEGIN(nanogui)

std::map<QWindow*, Screen *> __nanogui_screens;

Screen::Screen()
    : Widget(nullptr), m_qt_dispatch(new QtDispatch), m_qt_window(nullptr), m_nvg_context(nullptr),
      m_background(0.3f, 0.3f, 0.32f, 1.f),
      m_shutdown_qt(false), m_fullscreen(false) {
    m_timer.start();
}
Screen::Screen(const Vector2i &size, const std::string &caption, bool resizable,
               bool fullscreen, bool depth_buffer, bool stencil_buffer,
               bool float_buffer, unsigned int gl_major, unsigned int gl_minor)
    : Widget(nullptr), m_qt_dispatch(new QtDispatch), m_qt_window(nullptr), m_nvg_context(nullptr),
      m_cursor(Cursor::Arrow), m_background(0.3f, 0.3f, 0.32f, 1.f), m_caption(caption),
      m_shutdown_qt(false), m_fullscreen(fullscreen), m_depth_buffer(depth_buffer),
      m_stencil_buffer(stencil_buffer), m_float_buffer(float_buffer), m_redraw(false) {

    m_timer.start();

    m_qt_window = new QNGuiWindow(this);
    m_qt_window->resize(size.x(), size.y());
    m_qt_window->show();

    while(!QOpenGLContext::currentContext())
        qApp->processEvents();

    qInfo() << "Context ready. Initialize screen";
    QObject::connect(m_qt_dispatch, SIGNAL(requestUpdate()), m_qt_window, SLOT(renderLater()));
    QObject::connect(m_qt_dispatch, SIGNAL(requestResize(int,int)), m_qt_window, SLOT(resizeLater(int,int)));
    QObject::connect(m_qt_window, SIGNAL(notifyShouldClose(bool)), m_qt_dispatch, SLOT(changeShouldClose(bool)));

    initialize(m_qt_window, false);

    __nanogui_screens[m_qt_window] = this;
}

Screen::~Screen() {
    if (m_qt_dispatch) delete m_qt_dispatch;
}

void Screen::set_visible(bool visible) {
    if (m_visible != visible)
        m_visible = visible;
}

void Screen::set_caption(const std::string &caption) {
    if (caption != m_caption)
        m_caption = caption;
}

void Screen::set_size(const Vector2i &size) {
    Widget::set_size(size);
}

void Screen::clear() {
#if defined(NANOGUI_USE_OPENGL) || defined(NANOGUI_USE_GLES)
    CHK(glClearColor(m_background[0], m_background[1], m_background[2], m_background[3]));
    CHK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
#elif defined(NANOGUI_USE_METAL)
    mnvgClearWithColor(m_nvg_context, m_background);
#endif
}

void Screen::draw_contents() {
    clear();
}

void Screen::draw_setup() {
}

void Screen::draw_teardown() {
}

void Screen::nvg_flush() {
    NVGparams *params = nvgInternalParams(m_nvg_context);
    params->renderFlush(params->userPtr);
    params->renderViewport(params->userPtr, m_size[0], m_size[1], m_pixel_ratio);
}

void Screen::draw_widgets() {
    if (!m_visible)
        return;

    nvgBeginFrame(m_nvg_context, m_size[0], m_size[1], m_pixel_ratio);

    draw(m_nvg_context);

    double elapsed = sys_get_time() - m_last_interaction;

    if (elapsed > 0.5f) {
        /* Draw tooltips */
        const Widget *widget = find_widget(m_mouse_pos);
        if (widget && !widget->tooltip().empty()) {
            int tooltipWidth = 150;

            float bounds[4];
            nvgFontFace(m_nvg_context, "sans");
            nvgFontSize(m_nvg_context, 15.0f);
            nvgTextAlign(m_nvg_context, NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
            nvgTextLineHeight(m_nvg_context, 1.1f);
            Vector2i pos = widget->absolute_position() +
                           Vector2i(widget->width() / 2, widget->height() + 10);

            nvgTextBounds(m_nvg_context, pos.x(), pos.y(),
                            widget->tooltip().c_str(), nullptr, bounds);
            int h = (bounds[2] - bounds[0]) / 2;
            if (h > tooltipWidth / 2) {
                nvgTextAlign(m_nvg_context, NVG_ALIGN_CENTER | NVG_ALIGN_TOP);
                nvgTextBoxBounds(m_nvg_context, pos.x(), pos.y(), tooltipWidth,
                                widget->tooltip().c_str(), nullptr, bounds);

                h = (bounds[2] - bounds[0]) / 2;
            }
            nvgGlobalAlpha(m_nvg_context,
                           std::min(1.0, 2 * (elapsed - 0.5f)) * 0.8);

            nvgBeginPath(m_nvg_context);
            nvgFillColor(m_nvg_context, Color(0, 255));
            nvgRoundedRect(m_nvg_context, bounds[0] - 4 - h, bounds[1] - 4,
                           (int) (bounds[2] - bounds[0]) + 8,
                           (int) (bounds[3] - bounds[1]) + 8, 3);

            int px = (int) ((bounds[2] + bounds[0]) / 2) - h;
            nvgMoveTo(m_nvg_context, px, bounds[1] - 10);
            nvgLineTo(m_nvg_context, px + 7, bounds[1] + 1);
            nvgLineTo(m_nvg_context, px - 7, bounds[1] + 1);
            nvgFill(m_nvg_context);

            nvgFillColor(m_nvg_context, Color(255, 255));
            nvgFontBlur(m_nvg_context, 0.0f);
            nvgTextBox(m_nvg_context, pos.x() - h, pos.y(), tooltipWidth,
                       widget->tooltip().c_str(), nullptr);
        }
    }

    nvgEndFrame(m_nvg_context);
}

bool Screen::keyboard_event(int key, int scancode, int action, int modifiers) {
    if (m_focus_path.size() > 0) {
        for (auto it = m_focus_path.rbegin() + 1; it != m_focus_path.rend(); ++it)
            if ((*it)->focused() && (*it)->keyboard_event(key, scancode, action, modifiers))
                return true;
    }

    return false;
}

bool Screen::keyboard_character_event(unsigned int codepoint) {
    if (m_focus_path.size() > 0) {
        for (auto it = m_focus_path.rbegin() + 1; it != m_focus_path.rend(); ++it)
            if ((*it)->focused() && (*it)->keyboard_character_event(codepoint))
                return true;
    }
    return false;
}

bool Screen::resize_event(const Vector2i& size) {
    if (m_resize_callback) {
        m_resize_callback(size);
        return true;
    }
    return false;
}

void Screen::redraw() {
    if (!m_redraw) {
        m_redraw = true;
        #if !defined(EMSCRIPTEN)
            m_qt_dispatch->emitRequestUpdate();
        #endif
    }
}

void Screen::cursor_pos_callback_event(double x, double y) {
    Vector2i p((int) x, (int) y);

#if defined(_WIN32) || defined(__linux__) || defined(EMSCRIPTEN)
    p = Vector2i(Vector2f(p) / m_pixel_ratio);
#endif

    bool ret = false;
    m_last_interaction = sys_get_time();
    try {
        p -= Vector2i(1, 2);

        if (!m_drag_active) {
            Widget *widget = find_widget(p);
            if (widget != nullptr && widget->cursor() != m_cursor) {
                m_cursor = widget->cursor();
                set_cursor(m_cursor);
            }
        } else {
            ret = m_drag_widget->mouse_drag_event(
                p - m_drag_widget->parent()->absolute_position(), p - m_mouse_pos,
                m_mouse_state, m_modifiers);
        }

        if (!ret)
            ret = mouse_motion_event(p, p - m_mouse_pos, m_mouse_state, m_modifiers);

        m_mouse_pos = p;
        m_redraw |= ret;
    } catch (const std::exception &e) {
        std::cerr << "Caught exception in event handler: " << e.what() << std::endl;
    }
}

void Screen::mouse_button_callback_event(int button, int action, int modifiers) {
    m_modifiers = modifiers;
    m_last_interaction = sys_get_time();
    try {
        if (m_focus_path.size() > 1) {
            const Window *window =
                dynamic_cast<Window *>(m_focus_path[m_focus_path.size() - 2]);
            if (window && window->modal()) {
                if (!window->contains(m_mouse_pos))
                    return;
            }
        }

        if (action == NGUI_PRESS)
            m_mouse_state |= 1 << button;
        else
            m_mouse_state &= ~(1 << button);

        auto drop_widget = find_widget(m_mouse_pos);
        if (m_drag_active && action == NGUI_RELEASE &&
            drop_widget != m_drag_widget)
            m_drag_widget->mouse_button_event(
                m_mouse_pos - m_drag_widget->parent()->absolute_position(), button,
                false, m_modifiers);

        if (drop_widget != nullptr && drop_widget->cursor() != m_cursor) {
            m_cursor = drop_widget->cursor();
            set_cursor(m_cursor);
        }

        if (action == NGUI_PRESS && (button == NGUI_MOUSE_BUTTON_1 || button == NGUI_MOUSE_BUTTON_2)) {
            m_drag_widget = find_widget(m_mouse_pos);
            if (m_drag_widget == this)
                m_drag_widget = nullptr;
            m_drag_active = m_drag_widget != nullptr;
            if (!m_drag_active)
                update_focus(nullptr);
        } else {
            m_drag_active = false;
            m_drag_widget = nullptr;
        }

        mouse_button_event(m_mouse_pos, button, action == NGUI_PRESS, m_modifiers);
    } catch (const std::exception &e) {
        std::cerr << "Caught exception in event handler: " << e.what() << std::endl;
    }
}

void Screen::key_callback_event(int key, int scancode, int action, int mods) {
    m_last_interaction = sys_get_time();
    try {
        keyboard_event(key, scancode, action, mods);
    } catch (const std::exception &e) {
        std::cerr << "Caught exception in event handler: " << e.what() << std::endl;
    }
}

void Screen::char_callback_event(unsigned int codepoint) {
    m_last_interaction = sys_get_time();
    try {
        keyboard_character_event(codepoint);
    } catch (const std::exception &e) {
        std::cerr << "Caught exception in event handler: " << e.what()
                  << std::endl;
    }
}

void Screen::drop_callback_event(int count, const char **filenames) {
    std::vector<std::string> arg(count);
    for (int i = 0; i < count; ++i)
        arg[i] = filenames[i];
    drop_event(arg);
}

void Screen::scroll_callback_event(double x, double y) {
    m_last_interaction = sys_get_time();
    try {
        if (m_focus_path.size() > 1) {
            const Window *window =
                dynamic_cast<Window *>(m_focus_path[m_focus_path.size() - 2]);
            if (window && window->modal()) {
                if (!window->contains(m_mouse_pos))
                    return;
            }
        }
        scroll_event(m_mouse_pos, Vector2f(x, y));
    } catch (const std::exception &e) {
        std::cerr << "Caught exception in event handler: " << e.what()
                  << std::endl;
    }
}

void Screen::resize_callback_event(int w, int h) {

    Vector2i size(w, h);

    #if defined(_WIN32) || defined(__linux__) || defined(EMSCRIPTEN)
    size = Vector2i(Vector2f(size) / m_pixel_ratio);
#endif

    if (size == m_size && m_pixel_ratio == m_qt_window->devicePixelRatio())
        return;

    m_size = size;
    m_pixel_ratio = m_qt_window->devicePixelRatio();

    if (size == Vector2i(0, 0))
        return;

    m_last_interaction = sys_get_time();

    try {
        resize_event(m_size);
    } catch (const std::exception &e) {
        std::cerr << "Caught exception in event handler: " << e.what()
                  << std::endl;
    }
}

void Screen::update_focus(Widget *widget) {
    for (auto w: m_focus_path) {
        if (!w->focused())
            continue;
        w->focus_event(false);
    }
    m_focus_path.clear();
    Widget *window = nullptr;
    while (widget) {
        m_focus_path.push_back(widget);
        if (dynamic_cast<Window *>(widget))
            window = widget;
        widget = widget->parent();
    }
    for (auto it = m_focus_path.rbegin(); it != m_focus_path.rend(); ++it)
        (*it)->focus_event(true);

    if (window)
        move_window_to_front((Window *) window);
}

void Screen::dispose_window(Window *window) {
    if (std::find(m_focus_path.begin(), m_focus_path.end(), window) != m_focus_path.end())
        m_focus_path.clear();
    if (m_drag_widget == window)
        m_drag_widget = nullptr;
    remove_child(window);
}

void Screen::center_window(Window *window) {
    if (window->size() == Vector2i(0,0)) {
        window->set_size(window->preferred_size(m_nvg_context));
        window->perform_layout(m_nvg_context);
    }
    window->set_position((m_size - window->size()) / 2);
}

void Screen::move_window_to_front(Window *window) {
    m_children.erase(std::remove(m_children.begin(), m_children.end(), window), m_children.end());
    m_children.push_back(window);
    /* Brute force topological sort (no problem for a few windows..) */
    bool changed = false;
    do {
        size_t baseIndex = 0;
        for (size_t index = 0; index < m_children.size(); ++index)
            if (m_children[index] == window)
                baseIndex = index;
        changed = false;
        for (size_t index = 0; index < m_children.size(); ++index) {
            Popup *pw = dynamic_cast<Popup *>(m_children[index]);
            if (pw && pw->parent_window() == window && index < baseIndex) {
                move_window_to_front(pw);
                changed = true;
                break;
            }
        }
    } while (changed);
}


void Screen::initialize(QWindow *window, bool shutdown_window) {
    m_shutdown_qt = shutdown_window;
    m_pixel_ratio = window->devicePixelRatio();
    m_size = Vector2i(window->width(), window->height());
    m_fbsize = Vector2i(window->width() * m_pixel_ratio, window->height() * m_pixel_ratio);

    /* Detect framebuffer properties and set up compatible NanoVG context */
    const GLint
        nStencilBits = QSurfaceFormat::defaultFormat().stencilBufferSize(),
        nSamples = QSurfaceFormat::defaultFormat().samples();

    int flags = 0;
    if (nStencilBits >= 8)
       flags |= NVG_STENCIL_STROKES;
    if (nSamples <= 1)
       flags |= NVG_ANTIALIAS;
#if !defined(NDEBUG)
    flags |= NVG_DEBUG;
#endif

#if defined(NANOGUI_USE_OPENGL)
    m_nvg_context = nvgCreateGL2(flags);
#elif defined(NANOGUI_USE_GLES)
    m_nvg_context = nvgCreateGLES2(flags);
#endif
    if (m_nvg_context == nullptr)
        throw std::runtime_error("Could not initialize NanoVG!");

    m_visible = true;
    set_theme(new Theme(m_nvg_context));
    m_mouse_pos = Vector2i(0,0);
    m_mouse_state = m_modifiers = 0;
    m_drag_active = false;
    m_last_interaction = sys_get_time();
    m_process_events = true;

    /// Fixes retina display-related font rendering issue (#185)
    nvgBeginFrame(m_nvg_context, m_size[0], m_size[1], m_pixel_ratio);
    nvgEndFrame(m_nvg_context);

    m_qt_window = window;
}

double Screen::sys_get_time() const { return m_timer.elapsed() / 1000.; }

void Screen::draw_all() { m_qt_dispatch->emitRequestUpdate(); }
void Screen::draw_now() {
    if (m_nvg_context) {
        draw_contents();
        draw_widgets();
    }
}

bool Screen::tooltip_fade_in_progress() const {
    double elapsed = sys_get_time() - m_last_interaction;
    if (elapsed < 0.25f || elapsed > 1.25f)
        return false;
    /* Temporarily increase the frame rate to fade in the tooltip */
    const Widget *widget = find_widget(m_mouse_pos);
    return widget && !widget->tooltip().empty();
}

Texture::PixelFormat Screen::pixel_format() const {
#if defined(NANOGUI_USE_METAL)
    if (!m_float_buffer)
        return Texture::PixelFormat::BGRA;
#endif
    return Texture::PixelFormat::RGBA;
}

Texture::ComponentFormat Screen::component_format() const {
    if (m_float_buffer)
        return Texture::ComponentFormat::Float16;
    else
        return Texture::ComponentFormat::UInt8;
}

NAMESPACE_END(nanogui)
