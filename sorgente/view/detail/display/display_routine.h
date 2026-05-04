#ifndef DISPLAY_ROUTINE_H
#define DISPLAY_ROUTINE_H

#include "display_astratto.h"

class display_routine: public display_astratto {
    private:
        QLabel* etichetta_inizio;
        QLabel* etichetta_intervallo;
    public:
        display_routine(const dati_routine& dto, const QDateTime& l, const int n);
        ~display_routine() = default;
};
#endif