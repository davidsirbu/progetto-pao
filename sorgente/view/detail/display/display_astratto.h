#ifndef DISPLAY_ASTRATTO_H
#define DISPLAY_ASTRATTO_H

#include "../../../extra/dto.h"
#include <QWidget>

class QFormLayout;
class QLabel;
class QTextBrowser;

class display_astratto: public QWidget {
    Q_OBJECT;

    private:
        QFormLayout* layout;
        const QString id;
        QLabel* etichetta_titolo;
        QTextBrowser* etichetta_descrizione;
        QLabel* etichetta_categoria;
    
    public:
        display_astratto(const QString id, const QString& titolo, const QString& categoria, const QString& descrizione, QWidget* parent = nullptr);
        virtual ~display_astratto() = 0;

        void aggiungi_riga_al_form(const QString& categoria, const QString& etichetta);

        const QString& get_id_attuale() const;
};

#endif