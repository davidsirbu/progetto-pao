#include "scadenza.h"

scadenza::scadenza(const QString& n, const QString& d, const Gruppo c, const QDateTime& t) : attivita(n, d, c), completato(false), tempo_limite(t) {}

bool scadenza::get_completato() const {
    return completato;
}

QDateTime scadenza::get_tempo_limite() const {
    return tempo_limite;
}

QDateTime scadenza::get_tempo_completamento() const {
    return tempo_completamento;
}

void scadenza::set_tempo_limite(const QDateTime& t) {
    tempo_limite = t;
}

void scadenza::segna_completato() {
    completato = true;
    tempo_completamento = QDateTime::currentDateTime();
}

Fase scadenza::calcola_stato() const {
    if (completato) {
        if (tempo_completamento <= tempo_limite) return Fase::Completato;
        return Fase::CompletatoInRitardo;
    }
    QDateTime attuale = QDateTime::currentDateTime();
    if (attuale <= tempo_limite) return Fase::DaFare;
    return Fase::Scaduto;    
}