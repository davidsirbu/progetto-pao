#include <QCoreApplication>
#include <QDebug>
#include "controller/gestore.h"
#include "model/impegno.h"
#include "model/scadenza.h"
#include "model/routine.h"

#include <iostream>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv); // Necessario se usi classi Qt come QDateTime
    
    std::cout << "--- INIZIO TEST GESTORE ---";

    // 1. Creazione del Gestore
    gestore mio_gestore;

    // 2. Creazione Polimorfa (Il test del Modello)
    std::cout << "\nCreazione attivita...";
    attivita* a1 = new impegno("Palestra", "Allenamento gambe", Gruppo::Hobby, QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(3600), "Gym");
    attivita* a2 = new routine("Piante", "Annaffiare il ficus", Gruppo::Altro, QDateTime::currentDateTime(), 3);
    
    // 3. Aggiunta al Gestore
    mio_gestore.aggiungi_attivita(a1);
    mio_gestore.aggiungi_attivita(a2);

    // 4. Test della Ricerca (Quella col while magico)
    std::cout << "\nTest Ricerca...";
    QString id_da_cercare = a1->get_id(); // Prendo l'ID del primo per essere sicuro che esista
    attivita* trovato = mio_gestore.cerca_attivita(id_da_cercare);
    
    if (trovato != nullptr) {
        std::cout << "SUCCESSO! Trovato:" << trovato->get_nome().toStdString(); // Assumendo tu abbia un get_nome()
    } else {
        std::cout << "FALLIMENTO! Non ha trovato l'ID.";
    }

    // 5. Test della Ricerca a Vuoto (Per vedere se crasha!)
    std::cout << "\nTest Ricerca di un ID inesistente...";
    attivita* fantasma = mio_gestore.cerca_attivita("ID_CHE_NON_ESISTE_123");
    if (fantasma == nullptr) {
        std::cout << "SUCCESSO! Non ha trovato l'ID inventato e non è crashato.";
    }

    // 6. Test della Rimozione e della Memoria
    std::cout << "\nTest Rimozione...";
    mio_gestore.rimuovi_attivita(id_da_cercare);

    std::cout << "\n--- FINE TEST ---";
    // Quando il main finisce, il distruttore di mio_gestore partirà in automatico 
    // ripulendo a2 (l'unico rimasto). Se non ci sono Segmentation Fault qui, hai preso 30!

    return 0; // Se vuoi chiudere subito la console senza far partire il loop di Qt
}