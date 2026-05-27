#ifndef HOME_HEADER_H
#define HOME_HEADER_H

#include <QWidget>

class QPushButton;
class QLineEdit;

class home_header: public QWidget {
    Q_OBJECT

    private:
        QPushButton* pulsante_nuova_attivita = nullptr;
        QPushButton* pulsante_modifica_attivita = nullptr;
        QPushButton* pulsante_elimina_attivita = nullptr;
        QPushButton* pulsante_salvataggio_automatico = nullptr;
        QPushButton* pulsante_salvataggio_manuale = nullptr;
        QPushButton* pulsante_caricamento_dati = nullptr;
        QLineEdit* barra_ricerca = nullptr;
        
    public:
        home_header(QWidget* parent = nullptr);
        ~home_header() = default;

        void attiva_pulsanti();
        void disattiva_pulsanti();

        void abilita_salvataggio_automatico();

    signals:
        // FLUSSO: home_view <-- home_header
        // (Connessi tutti nel costruttore)
        void crea_attivita();
        void modifica_attivita();
        void elimina_attivita();
        void carica_dati();
        void barra_cambiata(const QString& s);

        // FLUSSO: home_view <-- home_corpo
        // (Emesso dagli slots di salvataggio. Il flag
        // dipende da quale funzione emette)
        void segnale_salvataggio(bool manuale);

    public slots:
        // Connessi nel costruttore
        void salvataggio_automatico();
        void salvataggio_manuale();
};

#endif