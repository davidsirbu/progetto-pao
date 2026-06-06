#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include "../extra/dto.h"

#include <vector>
#include <QMainWindow>
#include <QStackedLayout>
#include <QMessageBox>

class impegno;
class scadenza;
class routine;
class home_view;
class detail_view;
class form_view;

class main_view : public QWidget {
    Q_OBJECT

    private:
        QStackedLayout* stacked_layout;
        home_view* home_window;
        detail_view* detail_window;
        form_view* form_window;

        bool chiusura_autorizzata = false;

    public:
        main_view(QWidget* parent = nullptr);
        ~main_view() = default;

        // Inoltra le liste a home_view
        void passa_liste(const std::vector<dati_impegno>& i, 
                         const std::vector<dati_scadenza>& s, 
                         const std::vector<dati_routine>& r) const;

        QString chiedi_percorso_salvataggio();
        QString chiedi_percorso_caricamento();

        QMessageBox::StandardButton mostra_popup_salvataggio();
        void autorizza_chiusura();

        void closeEvent(QCloseEvent* event) override;

    signals:
        // FLUSSO: controller <-- main_view
        // (Connessi nel costruttore, emessi da home_view)
        void segnale_salvataggio(bool manuale);
        void segnale_caricamento();
        void segnale_elimina_attivita(const QString& id);
        void attivita_completata(const QString& id);

        // FLUSSO: controller <-- main_view
        // (Connesso nel costruttore, emesso sia da home_view
        //  che da detail_view)
        void segnale_richiesta_dati(const QString& id, bool modifica);

        // FLUSSO: controller <-- main_view
        // (Connessi nel costruttore, emessi da form_view)
        void invia_dati_impegno(const dati_impegno& i);
        void invia_dati_scadenza(const dati_scadenza& s);
        void invia_dati_routine(const dati_routine& r);

        void segnale_chiusura_finestra();

    public slots:
        // Emesso da home_view
        void crea_attivita();

        // Emesso da detail_view
        void torna_indietro();

        // Connesso nel costruttore nel controller, emesso da
        // visitor_ricerca
        void passa_dati_impegno(const dati_impegno& i, bool stato);
        void passa_dati_scadenza(const dati_scadenza& s, bool stato);
        void passa_dati_routine(const dati_routine& r, bool stato);
};

#endif