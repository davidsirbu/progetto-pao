#ifndef FORM_PARTE_VARIABILE_H
#define FORM_PARTE_VARIABILE_H

#include "../../extra/dto.h"

#include <QWidget>
#include <QDateTime>
#include <QString>

class QDateEdit;
class QDateTimeEdit;
class QCheckBox;
class QSpinBox;
class QLineEdit;

class form_impegno: public QWidget {
    Q_OBJECT

    private:
        QDateTimeEdit* selettore_inizio = nullptr;
        QDateTimeEdit* selettore_fine = nullptr;
        QLineEdit* etichetta_luogo = nullptr;

        void controlla_coerenza_orari(const QDateTime& nuovo_inizio);

    public:
        form_impegno(QWidget* parent);
        ~form_impegno() = default;

        mini_dto_impegno salva_dati() const;
        void set_dati(const dati_impegno& i);
    
        void reset();
};

class form_scadenza: public QWidget {
    Q_OBJECT

    private:
        QDateTimeEdit* selettore_tempo_limite = nullptr;
        
    public:
        form_scadenza(QWidget* parent);
        ~form_scadenza() = default;

        mini_dto_scadenza salva_dati() const;
        void set_dati(const dati_scadenza& s);

        void reset();
};

class form_routine: public QWidget {
    Q_OBJECT

    private:
        QDateEdit* selettore_inizio = nullptr;
        QSpinBox* selettore_intervallo = nullptr;
        QCheckBox* selettore_tutto_il_giorno = nullptr;

    public:
        form_routine(QWidget* parent);
        ~form_routine() = default;

        mini_dto_routine salva_dati() const;
        void set_dati(const dati_routine& r);

        void reset();
};

#endif