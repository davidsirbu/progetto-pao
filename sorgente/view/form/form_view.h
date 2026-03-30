#ifndef FORM_VIEW_H
#define FORM_VIEW_H

#include "form_scelta.h"
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>

class form_view: public QWidget {
    Q_OBJECT

    private:
        QLineEdit* etichetta_titolo;
        QComboBox* menu_gruppo;
        form_scelta* parte_scelta;
        QTextEdit* etichetta_descrizione;
        QPushButton* pulsante_salva;
        QPushButton* pulsante_annulla;

    public:
        form_view(QWidget* parent = nullptr);
        ~form_view() = default;






    };

#endif