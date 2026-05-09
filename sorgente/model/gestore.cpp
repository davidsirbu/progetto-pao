#include "gestore.h"
#include "gestore_file.h"
#include "visitor.h"
#include "classi/impegno.h"
#include "classi/scadenza.h"
#include "classi/routine.h"

#include <QJsonArray>
#include <QJsonDocument>

gestore::gestore() {}

gestore::~gestore() {
    svuota_lista();
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

void gestore::svuota_lista() {
    for (auto it = gestore_attivita.begin(); it != gestore_attivita.end(); ++it) delete *it;
    gestore_attivita.clear();
}

attivita* gestore::cerca_attivita(const QString& id_c) const {
    auto it = gestore_attivita.begin();
    while ((it != gestore_attivita.end()) && ((*it) -> get_id() != id_c)) it++;
    if (it == gestore_attivita.end()) return nullptr;
    return *it;
}

void gestore::accetta_visitatore(visitor& v) {
    for (auto it = gestore_attivita.begin(); it != gestore_attivita.end(); ++it) {
        (**it).accetta(v);
    }
}

void gestore::salva_dati(const QString& percorso) {
    QJsonArray lista_json;
    for (auto it = gestore_attivita.begin(); it != gestore_attivita.end(); ++it) {
        lista_json.append((*it) -> salva_in_json());
    }

    QJsonDocument pacco_finale(lista_json);

    gestore_file corriere;
    corriere.scrivi_file(percorso, pacco_finale);
}

bool gestore::importa_dati(const QString& percorso) {
    gestore_file corriere;
    QJsonDocument documento = corriere.leggi_file(percorso);

    if (documento.isNull() || !documento.isArray()) return false;

    svuota_lista(); 

    QJsonArray array_attivita = documento.array();

    for (auto it = array_attivita.begin(); it != array_attivita.end(); ++it) {
        QJsonObject obj = (*it).toObject();
        QString tipo = obj["tipo"].toString();

        attivita* nuova_attivita = nullptr;

        if (tipo == "impegno") nuova_attivita = new impegno();
        else if (tipo == "scadenza") nuova_attivita = new scadenza();
        else if (tipo == "routine") nuova_attivita = new routine();

        if (nuova_attivita) {
            nuova_attivita -> carica_da_json(obj);
            gestore_attivita.push_back(nuova_attivita);
        }
    }
    return true;
}