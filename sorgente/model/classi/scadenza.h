#ifndef SCADENZA_H
#define SCADENZA_H

#include "attivita.h"
#include <QDateTime>
#include <QString>

class scadenza : public attivita {
    private:
        bool completato;
        QDateTime tempo_limite;
        QDateTime tempo_completamento;

        
    public:
        scadenza(const QString& n, const QString& d, const Gruppo c, const QDateTime& t);
        ~scadenza() = default;

        dati_scadenza get_dati() const;
        void set_dati(dati_scadenza& s);

        void segna_completato();
        Fase calcola_stato() const override;
        void accetta(visitor& v) override;
};

#endif