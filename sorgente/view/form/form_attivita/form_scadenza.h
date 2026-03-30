#ifndef FORM_SCADENZA_H
#define FORM_SCADENZA_H

#include <QWidget>
#include <QCheckBox>
#include <QDateTimeEdit>

class form_scadenza: public QWidget {
    Q_OBJECT

    private:
        QDateTimeEdit* selettore_tempo_limite;
        QCheckBox* casella_completamento;
        
    public:
        form_scadenza(QWidget* parent);
        ~form_scadenza() = default;

};

#endif