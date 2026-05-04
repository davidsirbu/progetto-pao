#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "visitor_filtro.h"
#include "visitor_ricerca.h"
#include "../extra/dto.h"
#include <QObject>

class gestore;
class main_window;

class controller: public QObject {
    Q_OBJECT

    private:
        gestore* gestore_attivita;
        main_window* m_window;
        visitor_filtro smistatore;
        visitor_ricerca ricercatore;

        void passa_liste(const std::vector<dati_impegno>& i, const std::vector<dati_scadenza>& s, const std::vector<dati_routine>& r) const;
        Gruppo converti_stringa_a_enum(const QString& s) const;

    public:
        controller(gestore* g);
        ~controller() = default;

        void assegna_main_window(main_window* m);

        void refresh();

        void importa_e_smista_impegno(const dati_impegno& i);
        void importa_e_smista_scadenza(const dati_scadenza& s);
        void importa_e_smista_routine(const dati_routine& r);
        
        void crea_impegno(const dati_impegno& i);
        void crea_scadenza(const dati_scadenza& s);
        void crea_routine(const dati_routine& r);

        void modifica_impegno(const dati_impegno& i);
        void modifica_scadenza(const dati_scadenza& s);
        void modifica_routine(const dati_routine& r);

        void esporta_per_modifica(const QString& id, bool modifica);
        void elimina_attivita(const QString& id);
};

#endif