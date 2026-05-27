#ifndef DISPLAY_ROUTINE_H
#define DISPLAY_ROUTINE_H

#include "display_astratto.h"

class display_routine: public display_astratto {
    private:
        QLabel* etichetta_inizio = nullptr;
        QLabel* etichetta_intervallo = nullptr;
        
    public:
        display_routine(const dati_routine& dto);
        ~display_routine() = default;
};
#endif