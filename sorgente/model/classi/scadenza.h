#ifndef SCADENZA_H
#define SCADENZA_H

#include "attivita.h"

#include <QDateTime>
#include <QString>

class scadenza : public attivita {
    private:
        bool completato = false;
        QDateTime tempo_limite;
        QDateTime tempo_completamento;
       
    public:
        scadenza() = default;
        scadenza(const QString& n, const QString& d, const Gruppo c, const QDateTime& t);
        ~scadenza() = default;

        QDateTime get_limite() const;
        QDateTime get_tempo_completamento() const;
        bool get_completato();

        void set_limite(const QDateTime& l);

        Fase calcola_stato() const override;
        void esegui_completamento() override;
        void accetta(visitor& v) override;
        QJsonObject salva_in_json() const override;
        void carica_da_json(const QJsonObject& oggetto_json) override;
};

#endif