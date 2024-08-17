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

# Add this to your .pro file to link against Shell32.lib
LIBS += -lShell32

# Ensure to include necessary configurations for Unicode if not already set
QMAKE_CXXFLAGS += -DUNICODE -D_UNICODE
