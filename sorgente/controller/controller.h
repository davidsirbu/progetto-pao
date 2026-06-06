#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "visitor_filtro.h"
#include "visitor_ricerca.h"
#include "../extra/dto.h"

#include <QObject>

class gestore;
class main_view;

class controller: public QObject {
    Q_OBJECT

    private:
        gestore* gestore_attivita;
        main_view* main_window;
        visitor_filtro filtratore;
        visitor_ricerca ricercatore;
        QString percorso_salvataggio_attuale;

        Gruppo converti_stringa_in_enum(const QString& s) const;

        // Tramite il visitor_filtro, prende i dati grezzi dalle attività,
        // li separa in apposite liste e li passa alla GUI
        void passa_liste(const std::vector<dati_impegno>& i, 
                         const std::vector<dati_scadenza>& s, 
                         const std::vector<dati_routine>& r) const;
        
    public:
        controller(gestore* g, main_view* v);
        ~controller() = default;

        // Sincronizza GUI e model
        void refresh();

        // Crea l'attività a partire dai dati grezzi
        void crea_attivita(const dati_impegno& i);
        void crea_attivita(const dati_scadenza& s);
        void crea_attivita(const dati_routine& r);

        // Modifica l'attività a partire dai dati grezzi
        void modifica_attivita(const dati_impegno& i);
        void modifica_attivita(const dati_scadenza& s);
        void modifica_attivita(const dati_routine& r);

        void elimina_attivita(const QString& id);

    public slots:
        // Riceve i dati dalla GUI e decide se creare o modificare
        // l'attività (se id == 0, crea, altrimenti modifica)
        void importa_e_smista_impegno(const dati_impegno& i);
        void importa_e_smista_scadenza(const dati_scadenza& s);
        void importa_e_smista_routine(const dati_routine& r);

        // Tramite il visitor_ricerca, raccoglie i dati dell'attività
        // richiesta e li inoltra alla GUI
        // (Il flag "modifica" decide se in sola lettura o anche modifica)
        void esporta_a_gui(const QString& id, bool modifica);

        void salva_su_file(bool manuale);
        void carica_da_file();

        void completa_attivita(const QString& id);
};

#endif