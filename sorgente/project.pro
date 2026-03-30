TEMPLATE = app
TARGET = progetto_agenda
INCLUDEPATH += .
QT += \
        widgets \
        core

CONFIG += c++17 console
CONFIG -= app_bundle

DESTDIR = $$PWD

HEADERS += \
        extra/enums.h \
        model/classi/attivita.h \
        model/classi/impegno.h \
        model/classi/scadenza.h \
        model/classi/routine.h \
        model/gestore.h \
        view/main_window.h \
        view/home/home_view.h \
        view/home/home_header.h \
        view/home/home_corpo.h \
        view/detail/detail_view.h \
        view/detail/detail_header.h \
        view/detail/detail_corpo.h \
        view/detail/display/display_view.h \
        view/detail/display/display_variabile.h \
        view/form/form_view.h \
        view/form/form_scelta.h \
        view/form/form_parte_variabile.h \

SOURCES += \
        main.cpp \
        model/classi/attivita.cpp \
        model/classi/impegno.cpp \
        model/classi/scadenza.cpp \
        model/classi/routine.cpp \
        model/gestore.cpp \
        view/main_window.cpp \
        view/home/home_view.cpp \
        view/home/home_header.cpp \
        view/home/home_corpo.cpp \
        view/detail/detail_view.cpp \
        view/detail/detail_header.cpp \
        view/detail/detail_corpo.cpp \
        view/detail/display/display_view.cpp \
        view/detail/display/display_variabile.cpp \
        view/form/form_view.cpp \
        view/form/form_scelta.cpp \
        view/form/form_parte_variabile.cpp \