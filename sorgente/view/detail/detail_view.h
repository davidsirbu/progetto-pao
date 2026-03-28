#ifndef DETAIL_VIEW_H
#define DETAIL_VIEW_H

#include <QWidget>

class detail_view: public QWidget {
    Q_OBJECT

    private:

    public:
        detail_view(QWidget* parent = nullptr);
        ~detail_view() = default;
};

#endif