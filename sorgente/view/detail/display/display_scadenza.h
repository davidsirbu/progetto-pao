#ifndef DISPLAY_SCADENZA_H
#define DISPLAY_SCADENZA_H

#include "display_astratto.h"

class display_scadenza: public display_astratto {
    private:
        QLabel* etichetta_limite;
    public:
        display_scadenza(const dati_scadenza& dto, const QDateTime& l);
        ~display_scadenza() = default;
};
#endif