#ifndef ATTIVITA_H
#define ATTIVITA_H

#include "../../extra/enums.h"

#include <QString>
#include <QUuid>
#include <QDateTime>
#include <QJsonObject>

class visitor;

class attivita {
    private:
        const QString id;
        QString nome;
        QString descrizione;
        Gruppo categoria = Gruppo::Nessuno;

    public:
        attivita() = default;
        attivita(const QString& n, const QString& d, const Gruppo c);
        virtual ~attivita() = 0;

        QString get_id() const;
        QString get_nome() const;
        QString get_descrizione() const;
        Gruppo get_categoria() const;

        void set_nome(const QString& n);
        void set_descrizione(const QString& d);
        void set_categoria(const Gruppo c);

        virtual Fase calcola_stato() const = 0;
        virtual void esegui_completamento() = 0;
        virtual QDateTime valore_ordinamento() const = 0;

        // Funzione usata dai visitor per far determinare a quest'ultimi
        // il tipo dinamico di attività
        virtual void accetta(visitor& v) = 0;
        
        virtual void carica_da_json(const QJsonObject& oggetto_json) = 0;
        virtual QJsonObject salva_in_json() const = 0;
};

#endif