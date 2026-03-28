#include "main_window.h"

#include <QStackedLayout>

main_window::main_window(QWidget* parent): QWidget(parent) {

    stacked_layout = new QStackedLayout(this);
    home_window = new home_view(this);
    detail_window = new detail_view(this);

    stacked_layout -> addWidget(home_window);
    stacked_layout -> addWidget(detail_window);
    stacked_layout -> setCurrentIndex(0);

}