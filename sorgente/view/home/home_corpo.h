#ifndef HOME_CORPO_H
#define HOME_CORPO_H

#include "../../extra/enums.h"
#include "../../extra/dto.h"

#include <vector>
#include <QWidget>

class impegno;
class scadenza;
class routine;
class QListWidget;
class QListWidgetItem;
class QVBoxLayout;

class home_corpo: public QWidget {
    Q_OBJECT

    private:
        QListWidget* lista_impegni;
        QListWidget* lista_scadenze;
        QListWidget* lista_routine;
    
        // Funzioni di utilità per creare le liste della home_view
        QListWidget* setup_lista();
        QVBoxLayout* crea_colonna(const QString& nome_attivita, QListWidget* lista);

        void carica_impegni(const std::vector<dati_impegno>& i) const;
        void carica_scadenze(const std::vector<dati_scadenza>& s) const;
        void carica_routine(const std::vector<dati_routine>& r) const;

        void aggiorna_stato_pulsanti();

    public:
        home_corpo(QWidget* parent = nullptr);
        ~home_corpo() = default;

        void aggiorna_liste(const std::vector<dati_impegno>& i, 
                            const std::vector<dati_scadenza>& s, 
                            const std::vector<dati_routine>& r) const;

        QString get_id_selezionato() const;

    signals:
        // FLUSSO home_view <-- home_corpo
        void cambio_selezione(); // Emesso da aggiorna_stato_pulsanti()
        void doppio_click_su_attivita(); // Connesso in setup_lista()
        void segnale_attivita_completata(const QString id); // Emesso da attivita_completata()

    public slots:
        // Impediscono il click di più attività contemporaneamente
        void impegno_cliccato();
        void scadenza_cliccata();
        void routine_cliccata();

        void filtra_liste(const QString& s);
        void attivita_completata(QListWidgetItem* item);

};

#endif