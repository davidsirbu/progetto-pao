#ifndef GESTORE_H
#define GESTORE_H

#include <vector>
#include <QString>

class attivita;
class visitor;

class gestore {
    private:
        std::vector<attivita*> gestore_attivita;

    public:
        gestore();
        ~gestore();

        // Blocco della copia, dato che,
        // ad ogni esecuzione, il gestore è unico.
        gestore(const gestore& copia) = delete;
        gestore& operator=(const gestore& copia) = delete;

        void svuota_lista();

        void aggiungi_attivita(attivita* a);
        void rimuovi_attivita(const QString& id);
        attivita* cerca_attivita(const QString& id) const;

        // Itera la visita su tutte le attività
        void accetta(visitor& v);

        void salva_dati(const QString& percorso);
        bool importa_dati(const QString& percorso);
};

#endif