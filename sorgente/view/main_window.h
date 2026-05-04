#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "../extra/dto.h"
#include <vector>
#include <QMainWindow>
#include <QStackedLayout>

class impegno;
class scadenza;
class routine;
class controller;
class home_view;
class detail_view;
class form_view;

class main_window : public QWidget {
    Q_OBJECT

    private:
        controller* control;
        QStackedLayout* stacked_layout;
        home_view* home_window;
        detail_view* detail_window;
        form_view* form_window;

    public:
        main_window(controller* c, QWidget* parent = nullptr);
        ~main_window() = default;

        void passa_liste(const std::vector<dati_impegno>& i, const std::vector<dati_scadenza>& s, const std::vector<dati_routine>& r) const;

    public slots:
        void torna_indietro();
        void crea_attivita();
        
        void passa_dati_impegno(const dati_impegno& i, bool stato);
        void passa_dati_scadenza(const dati_scadenza& s, bool stato);
        void passa_dati_routine(const dati_routine& r, bool stato);
};

#endif