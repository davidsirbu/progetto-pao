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

        QDateTime get_inizio() const;
        QDateTime get_fine() const;
        QString get_luogo() const;

        void set_inizio(QDateTime& i);
        void set_fine(QDateTime& f);
        void set_luogo(QString& l);

        QString calcolo_durata() const;
        Fase calcola_stato() const override;
        void accetta(visitor& v) override;
};

#endif