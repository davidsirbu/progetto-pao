#ifndef FORM_SCELTA_H
#define FORM_SCELTA_H

#include <QWidget>
#include "form_parte_variabile.h"

class QPushButton;
class QStackedLayout;


class form_scelta: public QWidget {
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
        form_scelta(QWidget* parent);
        ~form_scelta() = default;

        form_impegno* salva_dati_impegno();
        form_scadenza* salva_dati_scadenza();
        form_routine* salva_dati_routine();
        int stato_stacked();

        void reset();

    public slots:
        void cambia_in_impegno();
        void cambia_in_scadenza();
        void cambia_in_routine();
};

#endif