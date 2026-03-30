#ifndef FORM_ROUTINE_H
#define FORM_ROUTINE_H

#include <QWidget>
#include <QDateTimeEdit>
#include <QSpinBox>

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