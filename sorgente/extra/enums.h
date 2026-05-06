#ifndef ENUMS_H
#define ENUMS_H

#include <QString>

enum class Gruppo {
    Nessuno = 0,
    Studio,
    Lavoro,
    Hobby,
    Altro
};

enum class Fase {
    Nessuna = 0,
    DaFare,
    InCorso,
    Completato,
    CompletatoInRitardo,
    Scaduto
};

#endif