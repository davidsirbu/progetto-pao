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
        const QString id;
        QFormLayout* layout = nullptr;
        QLabel* etichetta_titolo = nullptr;
        QTextBrowser* etichetta_descrizione = nullptr;
        QLabel* etichetta_categoria = nullptr;
    
    public:
        display_astratto(const QString id, const QString& titolo, const QString& categoria, const QString& descrizione, QWidget* parent = nullptr);
        virtual ~display_astratto() = 0;

        void aggiungi_riga_al_form(const QString& categoria, const QString& etichetta);

        const QString& get_id_attuale() const;
};

#endif