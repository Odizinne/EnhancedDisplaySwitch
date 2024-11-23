TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        EnhancedDisplaySwitch.cpp \
        main.cpp

HEADERS += \
        EnhancedDisplaySwitch.h

LIBS += -luser32 -ladvapi32

QMAKE_CXXFLAGS += -DUNICODE -D_UNICODE
