#ifndef ATTIVITA_H
#define ATTIVITA_H

#include "../../extra/enums.h"
#include <QString>
#include <QUuid>
#include <QDateTime>

class visitor;


class attivita {
    private:
        const QString id;
        QString nome;
        QString descrizione;
        Gruppo categoria;

    public:
        attivita(const QString& n, const QString& d, const Gruppo c);
        virtual ~attivita() = default;

        QString get_id() const;
        QString get_nome() const;
        QString get_descrizione() const;
        Gruppo get_categoria() const;

        void set_nome(const QString& n);
        void set_descrizione(const QString& d);
        void set_categoria(const Gruppo c);

        virtual Fase calcola_stato() const = 0;
        virtual void accetta(visitor& v) = 0;
};

#endif