#ifndef DTO_H
#define DTO_H

#include "enums.h"
#include <QString>
#include <QDateTime>


struct dati_impegno {
    QString nome;
    Gruppo categoria;
    QString descrizione;
    QDateTime inizio;
    QDateTime fine;
    QString luogo;
};

struct dati_scadenza {
    QString nome;
    Gruppo categoria;
    QString descrizione;
    QDateTime limite;
};

struct dati_routine {
    QString nome;
    Gruppo categoria;
    QString descrizione;
    QDateTime inizio;
    int intervallo;
    int puntuale;
    int ritardo;
};

#endif