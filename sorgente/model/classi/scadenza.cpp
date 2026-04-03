#include "scadenza.h"
#include "../visitor.h"

scadenza::scadenza(const QString& n, const QString& d, const Gruppo c, const QDateTime& t) : attivita(n, d, c), completato(false), tempo_limite(t) {}

dati_scadenza scadenza::get_dati() const {
    dati_scadenza s;
    s.nome = get_nome();
    s.descrizione = get_descrizione();
    s.categoria = get_categoria();
    s.limite = tempo_limite;
}

void scadenza::set_dati(dati_scadenza& s) {
    set_nome(s.nome);
    set_descrizione(s.descrizione);
    set_categoria(s.categoria);
    tempo_limite = s.limite;
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