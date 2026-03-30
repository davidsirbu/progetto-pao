#include "gestore.h"

gestore::gestore() {}

gestore::~gestore() {
    for (auto it = gestore_attivita.begin(); it != gestore_attivita.end(); ++it) {
        delete *it;
    }
    gestore_attivita.clear();
}

void gestore::aggiungi_attivita(attivita* a) {
    gestore_attivita.push_back(a);
}

void gestore::rimuovi_attivita(const QString& id_r) {
    auto it = gestore_attivita.begin();
    while ((it != gestore_attivita.end()) && ((*it) -> get_id() != id_r)) it++;
    if (it == gestore_attivita.end()) return;
    delete *it;
    gestore_attivita.erase(it);
}

attivita* gestore::cerca_attivita(const QString& id_c) const {
    auto it = gestore_attivita.begin();
    while ((it != gestore_attivita.end()) && ((*it) -> get_id() != id_c)) it++;
    if (it == gestore_attivita.end()) return nullptr;
    return *it;
}