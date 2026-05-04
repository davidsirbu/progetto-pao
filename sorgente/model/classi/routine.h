#ifndef ROUTINE_H
#define ROUTINE_H

#include "attivita.h"
#include <QDateTime>

class routine : public attivita {
    private:
        QDateTime inizio;
        QDateTime prossima_volta;
        int intervallo_giorni;
        int conta_puntuale;
        int conta_ritardo;

    public:
        routine(const QString& n, const QString& d, const Gruppo c, const QDateTime& i, const int g);
        ~routine() = default;

        QDateTime get_inizio() const;
        int get_intervallo() const;
        int get_puntuale() const;
        int get_ritardo() const;

        void set_inizio(const QDateTime& d);
        void set_intervallo(const int i);

        void avanza_progressi();
        Fase calcola_stato() const override;
        void accetta(visitor& v) override;
};

#endif