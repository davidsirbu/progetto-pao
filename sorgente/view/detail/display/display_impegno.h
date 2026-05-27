#ifndef DISPLAY_IMPEGNO_H
#define DISPLAY_IMPEGNO_H

#include "display_astratto.h"

class display_impegno: public display_astratto {
    private:
        QLabel* etichetta_inizio = nullptr;
        QLabel* etichetta_fine = nullptr;
        QLabel* etichetta_luogo = nullptr;

    public:
        display_impegno(const dati_impegno& dto);
        ~display_impegno() = default;
};
#endif