#ifndef ROUTINE_H
#define ROUTINE_H

#include "attivita.h"
#include <QDateTime>

class routine : public attivita {
    private:
        QDateTime inizio;
        QDateTime prossima_volta;
        int intervallo_giorni = 0;
        int conta_puntuale = 0;
        int conta_ritardo = 0;

    public:
        routine() = default;
        routine(const QString& n, const QString& d, const Gruppo c, const QDateTime& i, const int g);
        ~routine() = default;

        QDateTime get_inizio() const;
        QDateTime get_prossima_volta() const;
        int get_intervallo() const;
        int get_puntuale() const;
        int get_ritardo() const;

        void set_inizio(const QDateTime& d);
        void set_intervallo(const int i);

        void avanza_progressi();

        Fase calcola_stato() const override;
        void accetta(visitor& v) override;
        QJsonObject salva_in_json() const override;
        void carica_da_json(const QJsonObject& oggetto_json) override;
};

#endif