#ifndef DISPLAY_VIEW_H
#define DISPLAY_VIEW_H

#include "display_variabile.h"
#include <QWidget>
#include <QLabel>
#include <QStackedLayout>

class display_view: public QWidget {
    Q_OBJECT

    private:
        QLabel* etichetta_titolo;
        QLabel* etichetta_categoria;
        QLabel* etichetta_descrizione;

        QStackedLayout* stacked_layout;
        display_impegno* impegno_window;
        display_scadenza* scadenza_window;
        display_routine* routine_window;

    public:
        display_view(QWidget* parent);
        ~display_view() = default;
};

#endif