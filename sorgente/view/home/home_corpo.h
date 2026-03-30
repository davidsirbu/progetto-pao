#ifndef HOME_CORPO_H
#define HOME_CORPO_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>

class home_corpo: public QWidget {
    Q_OBJECT

    private:
        QListWidget* lista_eventi;
        QListWidget* lista_scadenze;
        QListWidget* lista_routine;
    
        QVBoxLayout* crea_colonna(const QString& nome_attivita, QListWidget* lista);

    public:
        home_corpo(QWidget* parent = nullptr);
        ~home_corpo() = default;
};

#endif