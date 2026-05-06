#ifndef DETAIL_VIEW_H
#define DETAIL_VIEW_H

#include <QWidget>
#include "../../extra/dto.h"

class detail_header;
class display_astratto;
class QVBoxLayout;

class detail_view: public QWidget {
    Q_OBJECT

    private:
        QVBoxLayout* layout;
        detail_header* header;
        display_astratto* display_attuale = nullptr;

    public:
        detail_view(QWidget* parent = nullptr);
        ~detail_view() = default;

        void carica_dettagli_impegno(const dati_impegno& i);
        void carica_dettagli_scadenza(const dati_scadenza& s);
        void carica_dettagli_routine(const dati_routine& r);

    signals:
        void segnale_indietro();
        void segnale_modifica(const QString& id, bool stato = true);
    
    public slots:
        void torna_indietro();
        void inoltra_segnale_modifica();
};

#endif