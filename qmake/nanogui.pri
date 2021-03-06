
# ngui_with_qtgl   - force to add qtgl.cpp wrappr
# ngui_with_nfd

CONFIG *= c++14

NGUIRT = $$PWD/..

INCLUDEPATH += $$NGUIRT/include $$NGUIRT/resources $$NGUIRT/ext $$NGUIRT/ext/qt

SOURCES += \
  $$NGUIRT/resources/nanogui_resources.cpp \
  $$NGUIRT/src/common.cpp \
  $$NGUIRT/src/traits.cpp \
  $$NGUIRT/src/canvas.cpp \
  $$NGUIRT/src/widget.cpp \
  $$NGUIRT/src/theme.cpp \
  $$NGUIRT/src/layout.cpp \
  $$NGUIRT/src/screen_qt.cpp \
  $$NGUIRT/src/label.cpp \
  $$NGUIRT/src/window.cpp \
  $$NGUIRT/src/popup.cpp \
  $$NGUIRT/src/checkbox.cpp \
  $$NGUIRT/src/button.cpp \
  $$NGUIRT/src/popupbutton.cpp \
  $$NGUIRT/src/combobox.cpp \
  $$NGUIRT/src/progressbar.cpp \
  $$NGUIRT/src/slider.cpp \
  $$NGUIRT/src/messagedialog.cpp \
  $$NGUIRT/src/textbox.cpp \
  $$NGUIRT/src/imagepanel.cpp \
  $$NGUIRT/src/imageview.cpp \
  $$NGUIRT/src/vscrollpanel.cpp \
  $$NGUIRT/src/colorwheel.cpp \
  $$NGUIRT/src/colorpicker.cpp \
  $$NGUIRT/src/graph.cpp \
  $$NGUIRT/src/tabwidget.cpp \
  $$NGUIRT/src/opengl.cpp \
  $$NGUIRT/src/renderpass_gl.cpp \
  $$NGUIRT/src/shader.cpp \
  $$NGUIRT/src/shader_gl.cpp \
  $$NGUIRT/src/texture.cpp \
  $$NGUIRT/src/texture_gl.cpp

macos|ios {
    OBJECTIVE_SOURCES += $$NGUIRT/src/darwin.mm
    LIBS += -framework Foundation -framework AppKit
} else {
    CONFIG(ngui_with_qtgl):!ios:!android {
        HEADERS += $$NGUIRT/include/nanogui/qtgl.h
        SOURCES += $$NGUIRT/src/qtgl.cpp
    }
}

HEADERS += \
    $$NGUIRT/resources/nanogui_resources.h \
    $$NGUIRT/ext/qt/qtapp.h \
    $$NGUIRT/include/nanogui/common.h \
    $$NGUIRT/include/nanogui/traits.h \
    $$NGUIRT/include/nanogui/vector.h \
    $$NGUIRT/include/nanogui/canvas.h \
    $$NGUIRT/include/nanogui/widget.h \
    $$NGUIRT/include/nanogui/theme.h \
    $$NGUIRT/include/nanogui/layout.h \
    $$NGUIRT/include/nanogui/screen.h \
    $$NGUIRT/include/nanogui/label.h \
    $$NGUIRT/include/nanogui/window.h \
    $$NGUIRT/include/nanogui/popup.h \
    $$NGUIRT/include/nanogui/checkbox.h \
    $$NGUIRT/include/nanogui/button.h \
    $$NGUIRT/include/nanogui/popupbutton.h \
    $$NGUIRT/include/nanogui/combobox.h \
    $$NGUIRT/include/nanogui/progressbar.h \
    $$NGUIRT/include/nanogui/slider.h \
    $$NGUIRT/include/nanogui/messagedialog.h \
    $$NGUIRT/include/nanogui/textbox.h \
    $$NGUIRT/include/nanogui/imagepanel.h \
    $$NGUIRT/include/nanogui/imageview.h \
    $$NGUIRT/include/nanogui/vscrollpanel.h \
    $$NGUIRT/include/nanogui/colorwheel.h \
    $$NGUIRT/include/nanogui/colorpicker.h \
    $$NGUIRT/include/nanogui/graph.h \
    $$NGUIRT/include/nanogui/tabwidget.h \
    $$NGUIRT/include/nanogui/formhelper.h \
    $$NGUIRT/include/nanogui/toolbutton.h \
    $$NGUIRT/include/nanogui/shader.h \
    $$NGUIRT/include/nanogui/texture.h \
    $$NGUIRT/include/nanogui/opengl.h \
    $$NGUIRT/include/nanogui/nanogui.h

CONFIG(ngui_with_nfd) {
    HEADERS += \
        $$NGUIRT/ext/nativefiledialog/src/include/nfd.h \
        $$NGUIRT/ext/nativefiledialog/src/common.h \
        $$NGUIRT/ext/nativefiledialog/src/nfd_common.h
    SOURCES += \
        $$NGUIRT/ext/nativefiledialog/src/nfd_common.c
    macos {
        OBJECTIVE_SOURCES += $$NGUIRT/ext/nativefiledialog/src/nfd_cocoa.m
        LIBS += -framework AppKit
    }
    linux: SOURCES += $$NGUIRT/ext/nativefiledialog/src/nfd_linux.cpp
    win32: SOURCES += $$NGUIRT/ext/nativefiledialog/src/nfd_win.cpp
    INCLUDEPATH += $$NGUIRT/ext/nativefiledialog/src/include
    DEFINES += NGUI_NFD
}

ios|android|CONFIG(opengl_gles_bc) {
    DEFINES += NANOGUI_USE_GLES
    CONFIG(ngui_with_gles3): DEFINES += NANOGUI_USE_GLES3 NANOGUI_GLES_VERSION=3
    else: DEFINES += NANOGUI_USE_GLES2 NANOGUI_GLES_VERSION=2
} else {
    DEFINES += NANOGUI_USE_OPENGL
}

isEmpty(COMMON_ROOT) {
    exists($$(HOME)/Private/Projekty/common-src-runtime): COMMON_ROOT = $$(HOME)/Private/Projekty/common-src-runtime
    else:exists($$(HOME)/Private/Projekty/0.shared/common-src-runtime): COMMON_ROOT = $$(HOME)/Private/Projekty/0.shared/common-src-runtime
    else:error("($$TARGET) Missing common runtime path!")
}

include("$$COMMON_ROOT/Gfx/nanovg/qt/nanovg.pri")
