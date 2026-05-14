#ifndef FORM_VIEW_H
#define FORM_VIEW_H

#include "../../extra/dto.h"
#include <QWidget>

class QLineEdit;
class QComboBox;
class QLabel;
class form_scelta;
class QTextEdit;
class QPushButton;

class form_view: public QWidget {
    Q_OBJECT

    private:
        QString id;
        QLabel* titolo_finestra;
        QLineEdit* etichetta_titolo;
        QComboBox* menu_gruppo;
        form_scelta* parte_scelta;
        QTextEdit* etichetta_descrizione;
        QPushButton* pulsante_salva;
        QPushButton* pulsante_annulla;

        void reset();
        void controlla_stringa(const QString& input);

    public:
        form_view(QWidget* parent = nullptr);
        ~form_view() = default;

        void imposta_titolo_finestra(const QString& titolo);

    signals:
        void torna_indietro();

        void salva_impegno(const dati_impegno& i);
        void salva_scadenza(const dati_scadenza& s);
        void salva_routine(const dati_routine& r);

    public slots:
        void salva();
        void annulla();

        void carica_impegno(const dati_impegno& i);
        void carica_scadenza(const dati_scadenza& s);
        void carica_routine(const dati_routine& r);
};

#endif