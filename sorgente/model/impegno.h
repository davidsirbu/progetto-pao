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
        // Costruttore e distruttore
        impegno(const QString& n, const QString& d, const Gruppo c, const QDateTime& i, const QDateTime& f, const QString& l);
        ~impegno() = default;

        // Getter
        QDateTime get_inizio() const;
        QDateTime get_fine() const;
        QString get_luogo() const;

        // Setter
        void set_inizio(const QDateTime& i);
        void set_fine(const QDateTime& f);
        void set_luogo(const QString& l);

        // Altro
        QString calcolo_durata() const;
        Fase calcola_stato() const override;
};


#endif