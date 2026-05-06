#include "routine.h"
#include "../visitor.h"

routine::routine(const QString& n, const QString& d, const Gruppo c, const QDateTime& i, const int g) : attivita(n, d, c), inizio(i), prossima_volta(i), intervallo_giorni(g), conta_puntuale(0), conta_ritardo(0) {}

QDateTime routine::get_inizio() const {
    return inizio;
}

QDateTime routine::get_prossima_volta() const {
    return prossima_volta;
}

int routine::get_intervallo() const {
    return intervallo_giorni;
}

int routine::get_puntuale() const {
    return conta_puntuale;
}

int routine::get_ritardo() const {
    return conta_ritardo;
}

void routine::set_inizio(const QDateTime& d) {
    inizio = d;
}

void routine::set_intervallo(const int i) {
    intervallo_giorni = i;
}

void routine::avanza_progressi() {
    QDateTime attuale = QDateTime::currentDateTime();
    if (attuale < prossima_volta) {
        prossima_volta = prossima_volta.addDays(intervallo_giorni);
        conta_puntuale++;
    }
    else {
        prossima_volta = attuale.addDays(intervallo_giorni);
        conta_ritardo++;
    }
}

Fase routine::calcola_stato() const {
    QDateTime attuale = QDateTime::currentDateTime();
    if (attuale < prossima_volta) return Fase::DaFare;
    return Fase::Scaduto;
}

void routine::accetta(visitor& v) {
    v.visit(*this);
}

QJsonObject routine::salva_in_json() const {
    QJsonObject oggetto_json;

    oggetto_json["tipo"] = "routine";
    oggetto_json["id"] = get_id();
    oggetto_json["nome"] = get_nome();
    oggetto_json["categoria"] = static_cast<int>(get_categoria());
    oggetto_json["inizio"] = inizio.toString();
    oggetto_json["prossima_volta"] = prossima_volta.toString();
    oggetto_json["intervallo_giorni"] = intervallo_giorni;
    oggetto_json["conta_puntuale"] = conta_puntuale;
    oggetto_json["conta_ritardo"] = conta_ritardo;

    return oggetto_json;
}