CONFIG += debug ngui_with_nfd ngui_with_enoki
SOURCES += ../src/$${TARGET}.cpp
RESOURCES += resources.qrc

CONFIG(ngui_with_enoki): {
    MATH = -enoki
    CONFIG += c++17
} else:CONFIG(ngui_with_eigen): MATH = -eigen

CONFIG(c++17): CXX = -c17
else:CONFIG(c++14): CXX = -c14
else:CONFIG(c++11): CXX = -c11
CONFIG(debug, debug|release): DBG = dbg
else: DBG = rel

T=$$lower($$TARGET)

DESTDIR = $$PWD/build-$$[QMAKE_SPEC]$$CXX$$MATH
OBJECTS_DIR = $$DESTDIR/$$DBG/obj
MOC_DIR = $$DESTDIR/$$DBG/ui
UI_DIR = $$DESTDIR/$$DBG/ui
RCC_DIR = $$DESTDIR/$$DBG/rcc

COMPANY = KomSoft
BUNDLE_PREFIX = com.komsoft

include("nanogui.pri")
