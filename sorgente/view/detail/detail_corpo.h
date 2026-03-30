#ifndef DETAIL_CORPO_H
#define DETAIL_CORPO_H

#include <QWidget>
#include <QListWidget>

class detail_corpo: public QWidget {
    Q_OBJECT

    private:
        QListWidget* lista;

    public:
        detail_corpo(QWidget* parent);
        ~detail_corpo() = default;
};

#endif