#ifndef FORM_SCELTA_H
#define FORM_SCELTA_H

#include <QWidget>
#include "../../extra/dto.h"
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

        mini_dto_impegno ricevi_dati_impegno() const;
        mini_dto_scadenza ricevi_dati_scadenza() const;
        mini_dto_routine ricevi_dati_routine() const;
        
        void inoltra_dati_impegno(const dati_impegno& i);
        void inoltra_dati_scadenza(const dati_scadenza& s);
        void inoltra_dati_routine(const dati_routine& r);

        int stato_stacked();

        void reset();

    public slots:
        void cambia_in_impegno();
        void cambia_in_scadenza();
        void cambia_in_routine();
};

#endif