#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QStackedLayout>

class home_view;
class detail_view;
class form_view;

class main_window : public QWidget {
    Q_OBJECT

    private:
        QStackedLayout* stacked_layout;
        home_view* home_window;
        detail_view* detail_window;
        form_view* form_window;

    public:
        main_window(QWidget* parent = nullptr);
        ~main_window() = default;

    public slots:
        void crea_attivita();
        void torna_indietro();
        // void entra_dettagli();
};

#endif