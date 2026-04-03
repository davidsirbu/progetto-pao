#ifndef FORM_PARTE_VARIABILE_H
#define FORM_PARTE_VARIABILE_H

#include "../../extra/dto.h"
#include <QWidget>
#include <QDateTime>
#include <QString>

class QDateTimeEdit;
class QCheckBox;
class QSpinBox;
class QLineEdit;

class form_impegno: public QWidget {
    Q_OBJECT

    private:
        QDateTimeEdit* selettore_inizio;
        QDateTimeEdit* selettore_fine;
        QLineEdit* etichetta_luogo;

    public:
        form_impegno(QWidget* parent);
        ~form_impegno() = default;

        mini_dto_impegno salva_dati() const;
    
        void reset();
};

///////////////////////////////////////////////////////

class form_scadenza: public QWidget {
    Q_OBJECT

    private:
        QDateTimeEdit* selettore_tempo_limite;
        
    public:
        form_scadenza(QWidget* parent);
        ~form_scadenza() = default;

        mini_dto_scadenza salva_dati() const;

        void reset();
};

///////////////////////////////////////////////////////

class form_routine: public QWidget {
    Q_OBJECT

    private:
        QDateTimeEdit* selettore_inizio;
        QSpinBox* selettore_intervallo;

    public:
        form_routine(QWidget* parent);
        ~form_routine() = default;

        mini_dto_routine salva_dati() const;

        void reset();
};

#endif