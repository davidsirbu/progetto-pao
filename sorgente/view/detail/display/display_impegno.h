#ifndef DISPLAY_IMPEGNO_H
#define DISPLAY_IMPEGNO_H

#include "display_astratto.h"

class display_impegno: public display_astratto {
    private:
        QLabel* etichetta_inizio;
        QLabel* etichetta_fine;
        QLabel* etichetta_luogo;

    public:
        display_impegno(const dati_impegno& dto, QWidget* parent = nullptr);
        ~display_impegno() = default;
};
#endif