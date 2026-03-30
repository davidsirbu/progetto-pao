#ifndef GESTORE_H
#define GESTORE_H

#include "classi/attivita.h"
#include <vector>
#include <QString>

class gestore {
    private:
        std::vector<attivita*> gestore_attivita;

    public:
        gestore();
        ~gestore();

        // Blocco della copia
        gestore(const gestore& copia) = delete;
        gestore& operator=(const gestore& copia) = delete;

        void aggiungi_attivita(attivita* a);
        void rimuovi_attivita(const QString& id);
        attivita* cerca_attivita(const QString& id) const;
};

#endif