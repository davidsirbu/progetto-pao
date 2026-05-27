#ifndef DETAIL_VIEW_H
#define DETAIL_VIEW_H

#include "../../extra/dto.h"

#include <QWidget>

class detail_header;
class display_astratto;
class QVBoxLayout;

class detail_view: public QWidget {
    Q_OBJECT

    private:
        QVBoxLayout* layout = nullptr;
        detail_header* header = nullptr;
        display_astratto* display_attuale = nullptr;

    public:
        detail_view(QWidget* parent = nullptr);
        ~detail_view() = default;

        // FLUSSO: detail_view --> display_impegno/scadenza/routine
        void inoltra_dettagli(const dati_impegno& i);
        void inoltra_dettagli(const dati_scadenza& s);
        void inoltra_dettagli(const dati_routine& r);

    signals:
        // FLUSSO: main_window <-- detail_view (emessi dagli slot corrispondenti)
        void segnale_indietro();
        void segnale_modifica(const QString& id, bool stato = true);
    
    public slots:
        // Distruggono il display corrente ed emettono il segnale corrispondente
        // (slot invocati da detail_header)
        void torna_indietro();
        void inoltra_segnale_modifica();
};

#endif