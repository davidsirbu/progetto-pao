#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

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

        void passa_liste(const std::vector<impegno*>& i, const std::vector<scadenza*>& s, const std::vector<routine*>& r) const;

    public slots:
        void crea_attivita();
        void torna_indietro();
};

#endif