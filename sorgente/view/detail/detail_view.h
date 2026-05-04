#ifndef DETAIL_VIEW_H
#define DETAIL_VIEW_H

#include <QWidget>
#include "../../extra/dto.h"

class detail_header;
class detail_corpo;

class detail_view: public QWidget {
    Q_OBJECT

    private:
        detail_header* header;
        detail_corpo* corpo;

    public:
        detail_view(QWidget* parent = nullptr);
        ~detail_view() = default;

        void inoltra_dettagli_impegno(const dati_impegno& i);
        void inoltra_dettagli_scadenza(const dati_scadenza& s);
        void inoltra_dettagli_routine(const dati_routine& r);

    signals:
        void torna_indietro();
};

#endif