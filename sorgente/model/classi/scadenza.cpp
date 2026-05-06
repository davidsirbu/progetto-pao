#include "scadenza.h"
#include "../visitor.h"

scadenza::scadenza(const QString& n, const QString& d, const Gruppo c, const QDateTime& t) : attivita(n, d, c), completato(false), tempo_limite(t) {}

QDateTime scadenza::get_limite() const {
    return tempo_limite;
}

QDateTime scadenza::get_tempo_completamento() const {
    return tempo_completamento;
}

void scadenza::set_limite(const QDateTime& l) {
    tempo_limite = l;
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

void scadenza::accetta(visitor& v) {
    v.visit(*this);
}

QJsonObject scadenza::salva_in_json() const {
    QJsonObject oggetto_json;

    oggetto_json["tipo"] = "scadenza";
    oggetto_json["id"] = get_id();
    oggetto_json["nome"] = get_nome();
    oggetto_json["categoria"] = static_cast<int>(get_categoria());
    oggetto_json["completato"] = completato;
    oggetto_json["tempo_limite"] = tempo_limite.toString();
    if (completato) oggetto_json["tempo_completamento"] = tempo_completamento.toString();

    return oggetto_json;
}