#ifndef FORM_SCELTA_H
#define FORM_SCELTA_H

#include "../../extra/dto.h"
#include "form_parte_variabile.h"

#include <QWidget>

class QPushButton;
class QStackedLayout;

class form_scelta: public QWidget {
    Q_OBJECT

    private:
        QPushButton* pulsante_impegno = nullptr;
        QPushButton* pulsante_scadenza = nullptr;
        QPushButton* pulsante_routine = nullptr;
        QStackedLayout* stacked_layout = nullptr;
        form_impegno* impegno_window = nullptr;
        form_scadenza* scadenza_window = nullptr;
        form_routine* routine_window = nullptr;
        
    public:
        form_scelta(QWidget* parent);
        ~form_scelta() = default;

        int stato_stacked();
        void attiva_pulsanti();
        void disattiva_pulsanti();
        void reset();

        // Riceve i dati dipendenti dal tipo di attività
        // dal form_parte_variabile corretto
        mini_dto_impegno ricevi_dati_impegno() const;
        mini_dto_scadenza ricevi_dati_scadenza() const;
        mini_dto_routine ricevi_dati_routine() const;
        
        // Carica i dati dipendenti dal tipo di attività
        // nel form_parte_variabile corretto
        void inoltra_dati(const dati_impegno& i);
        void inoltra_dati(const dati_scadenza& s);
        void inoltra_dati(const dati_routine& r);

    public slots:
        // Imposta il form_parte_variabile corretto
        void cambia_in_impegno();
        void cambia_in_scadenza();
        void cambia_in_routine();
};

#endif