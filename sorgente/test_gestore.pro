TEMPLATE = app
TARGET = test_gestore
INCLUDEPATH += .
QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

DESTDIR = $$PWD

HEADERS += \
        model/attivita.h \
        model/impegno.h \
        model/scadenza.h \
        model/routine.h \
        controller/gestore.h \
        utility/enums.h \

SOURCES += \
        main.cpp \
        model/attivita.cpp \
        model/impegno.cpp \
        model/scadenza.cpp \
        model/routine.cpp \
        controller/gestore.cpp \
