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
        view/detail/detail_header.h \
        view/detail/detail_corpo.h \
        view/form/form_view.h \
        view/form/form_variabile.h \
        view/form/form_attivita/form_impegno.h \
        view/form/form_attivita/form_scadenza.h \
        view/form/form_attivita/form_routine.h \

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
        view/detail/detail_header.cpp \
        view/detail/detail_corpo.cpp \
        view/form/form_view.cpp \
        view/form/form_variabile.cpp \
        view/form/form_attivita/form_impegno.cpp \
        view/form/form_attivita/form_scadenza.cpp \
        view/form/form_attivita/form_routine.cpp \