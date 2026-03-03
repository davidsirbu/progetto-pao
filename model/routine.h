#ifndef ROUTINE_H
#define ROUTINE_H

#include "attivita.h"
#include <QDateTime>
#include <QString>

class routine : public attivita {
    private:
        QDateTime inizio;
        QDateTime prossima_volta;
        int intervallo_giorni;
        int conta_puntuale;
        int conta_ritardo;

    public:
        // Costruttore e distruttore
        routine(const QString& n, const QString& d, const Gruppo c, const QDateTime& i, const int g);
        ~routine() = default;

        // Getter
        QDateTime get_inizio() const;
        QDateTime get_prossima_volta() const;
        int get_intervallo_giorni() const;
        int get_conta_puntuale() const;
        int get_conta_ritardo() const;

        // Setter
        void set_intervallo_giorni(const int g);

        // Altro
        void avanza_progressi();
        Fase calcola_stato() const override;
};


#endif