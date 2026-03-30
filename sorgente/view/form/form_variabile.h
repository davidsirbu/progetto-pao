#ifndef FORM_VARIABILE_H
#define FORM_VARIABILE_H

#include "form_attivita/form_impegno.h"
#include "form_attivita/form_scadenza.h"
#include "form_attivita/form_routine.h"
#include <QPushButton>
#include <QWidget>
#include <QStackedLayout>

class form_variabile: public QWidget {
    Q_OBJECT

    private:
        QPushButton* pulsante_impegno;
        QPushButton* pulsante_scadenza;
        QPushButton* pulsante_routine;
        QStackedLayout* stacked_layout;
        form_impegno* impegno_window;
        form_scadenza* scadenza_window;
        form_routine* routine_window;
        

    public:
        form_variabile(QWidget* parent);
        ~form_variabile() = default;

    public slots:
        void cambia_in_impegno();
        void cambia_in_scadenza();
        void cambia_in_routine();
};

#endif