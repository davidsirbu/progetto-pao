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
        extra/dto.h \
        model/classi/attivita.h \
        model/classi/impegno.h \
        model/classi/scadenza.h \
        model/classi/routine.h \
        model/visitor.h \
        model/gestore.h \
        controller/controller.h \
        controller/visitor_filtro.h \
        controller/visitor_ricerca.h \
        view/main_window.h \
        view/home/home_view.h \
        view/home/home_header.h \
        view/home/home_corpo.h \
        view/detail/detail_view.h \
        view/detail/detail_header.h \
        view/detail/detail_corpo.h \
        view/detail/display/display_astratto.h \
        view/detail/display/display_impegno.h \
        view/detail/display/display_scadenza.h \
        view/detail/display/display_routine.h \
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
        controller/controller.cpp \
        controller/visitor_filtro.cpp \
        controller/visitor_ricerca.cpp \
        view/main_window.cpp \
        view/home/home_view.cpp \
        view/home/home_header.cpp \
        view/home/home_corpo.cpp \
        view/detail/detail_view.cpp \
        view/detail/detail_header.cpp \
        view/detail/detail_corpo.cpp \
        view/detail/display/display_astratto.cpp \
        view/detail/display/display_impegno.cpp \
        view/detail/display/display_scadenza.cpp \
        view/detail/display/display_routine.cpp \
        view/form/form_view.cpp \
        view/form/form_scelta.cpp \
        view/form/form_parte_variabile.cpp \