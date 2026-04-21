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
        visitor_ricerca caricatore;

        void passa_liste(const std::vector<impegno*>& i, const std::vector<scadenza*>& s, const std::vector<routine*>& r) const;

    public:
        controller(gestore* g);
        ~controller() = default;

        void assegna_main_window(main_window* m);

        void smistamento();
        
        void crea_impegno(const dati_impegno& i);
        void crea_scadenza(const dati_scadenza& s);
        void crea_routine(const dati_routine& r);

        void modifica_attivita(const QString& id);
        void elimina_attivita(const QString& id);
};

#endif