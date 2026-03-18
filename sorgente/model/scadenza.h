#ifndef SCADENZA_H
#define SCADENZA_H


#include "attivita.h"
#include <QDateTime>

class scadenza : public attivita {
    private:
        bool completato;
        QDateTime tempo_limite;
        QDateTime tempo_completamento;
        
    public:
        // Costruttore e distruttore
        scadenza(const QString& n, const QString& d, const Gruppo c, const QDateTime& t);
        ~scadenza() = default;

        // Getter
        bool get_completato() const;
        QDateTime get_tempo_limite() const;
        QDateTime get_tempo_completamento() const;
        
        // Setter
        void set_tempo_limite(const QDateTime& t);

        // Altro
        void segna_completato();
        Fase calcola_stato() const override;

};


#endif