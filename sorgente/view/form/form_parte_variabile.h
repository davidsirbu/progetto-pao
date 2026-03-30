#ifndef FORM_PARTE_VARIABILE_H
#define FORM_PARTE_VARIABILE_H

#include <QWidget>
#include <QDateTimeEdit>
#include <QCheckBox>
#include <QSpinBox>

class form_impegno: public QWidget {
    Q_OBJECT

    private:
    QDateTimeEdit* selettore_inizio;
    QDateTimeEdit* selettore_fine;
    QLineEdit* etichetta_luogo;

    public:
        form_impegno(QWidget* parent);
        ~form_impegno() = default;

    
};

class form_scadenza: public QWidget {
    Q_OBJECT

    private:
        QDateTimeEdit* selettore_tempo_limite;
        QCheckBox* casella_completamento;
        
    public:
        form_scadenza(QWidget* parent);
        ~form_scadenza() = default;

};

class form_routine: public QWidget {
    Q_OBJECT

    private:
        QDateTimeEdit* selettore_inizio;
        QSpinBox* selettore_intervallo;

    public:
        form_routine(QWidget* parent);
        ~form_routine() = default;

};

#endif