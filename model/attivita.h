#ifndef ATTIVITA_H
#define ATTIVITA_H

#include "../utility/enums.h"
#include <QString>
#include <QUuid>


class attivita {
    private:
        const QString id;
        QString nome;
        QString descrizione;
        Gruppo categoria;
        
    public:
        // Costruttore e distruttore
        attivita(const QString& n, const QString& d, const Gruppo c);
        virtual ~attivita() = default;

        // Getter
        QString get_nome() const;
        QString get_descrizione() const;
        Gruppo get_categoria() const;
        QString get_id() const;

        // Setter
        void set_nome(const QString& n);
        void set_descrizione(const QString& d);
        void set_categoria(const Gruppo c);

        // Metodi virtuali
        virtual Fase calcola_stato() const = 0;

};


#endif