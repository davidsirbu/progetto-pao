TEMPLATE = app
TARGET = test_gestore
INCLUDEPATH += .
QT += \
        widgets \
        core

CONFIG += c++17 console
CONFIG -= app_bundle

DESTDIR = $$PWD

# Definisci il nome della cartella
TEMP_DIR = .temp

# Reindirizza i file generati
OBJECTS_DIR = $$TEMP_DIR/obj
MOC_DIR     = $$TEMP_DIR/moc
RCC_DIR     = $$TEMP_DIR/rcc
UI_DIR      = $$TEMP_DIR/ui

HEADERS += \
        extra/enums.h \
        model/attivita.h \
        model/impegno.h \
        model/scadenza.h \
        model/routine.h \
        controller/gestore.h \
        view/main_window.h \
        view/home/home_view.h \
        view/home/home_header.h \
        view/home/home_corpo.h \
        view/detail/detail_view.h \

SOURCES += \
        main.cpp \
        model/attivita.cpp \
        model/impegno.cpp \
        model/scadenza.cpp \
        model/routine.cpp \
        controller/gestore.cpp \
        view/main_window.cpp \
        view/home/home_view.cpp \
        view/home/home_header.cpp \
        view/home/home_corpo.cpp \
        view/detail/detail_view.cpp \
