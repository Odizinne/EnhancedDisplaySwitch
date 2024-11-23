TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
        src/EnhancedDisplaySwitch

SOURCES += \
        src/EnhancedDisplaySwitch/EnhancedDisplaySwitch.cpp \
        src/main.cpp

HEADERS += \
        src/EnhancedDisplaySwitch/EnhancedDisplaySwitch.h

LIBS += -luser32

QMAKE_CXXFLAGS += -DUNICODE -D_UNICODE
