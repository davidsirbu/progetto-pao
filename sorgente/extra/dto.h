#ifndef DTO_H
#define DTO_H

#include "enums.h"
#include <QString>
#include <QDateTime>


struct dati_impegno {
    QString id;
    QString nome;
    QString categoria;
    QString fase;
    QString descrizione;
    QDateTime inizio;
    QDateTime fine;
    QString durata;
    QString luogo;
};

struct dati_scadenza {
    QString id;
    QString nome;
    QString categoria;
    QString fase;
    QString descrizione;
    QDateTime limite;
};

struct dati_routine {
    QString id;
    QString nome;
    QString categoria;
    QString fase;
    QString descrizione;
    QDateTime inizio;
    QDateTime prossima_volta;
    int intervallo;
};

struct mini_dto_impegno {
    QDateTime inizio;
    QDateTime fine;
    QString luogo;
};

struct mini_dto_scadenza {
    QDateTime limite;
};

struct mini_dto_routine {
    QDateTime inizio;
    int intervallo;
};

#endif