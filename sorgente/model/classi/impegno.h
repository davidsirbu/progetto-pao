#ifndef IMPEGNO_H
#define IMPEGNO_H

#include "attivita.h"
#include <QDateTime>

class impegno : public attivita {
    private:
        QDateTime inizio;
        QDateTime fine;
        QString luogo;

    public:
        impegno(const QString& n, const QString& d, const Gruppo c, const QDateTime& i, const QDateTime& f, const QString& l);
        ~impegno() = default;

        dati_impegno get_dati() const;
        void set_dati(dati_impegno&);

        QString calcolo_durata() const;
        Fase calcola_stato() const override;
        void accetta(visitor& v) override;
};

#endif