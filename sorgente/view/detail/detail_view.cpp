#include "detail_view.h"
#include "detail_header.h"
#include "detail_corpo.h"
#include <QVBoxLayout>

detail_view::detail_view(QWidget* parent): QWidget(parent) {

    QVBoxLayout* detail_layout = new QVBoxLayout(this);
    header = new detail_header(this);
    corpo = new detail_corpo(this);

    detail_layout -> addWidget(header);
    detail_layout -> addWidget(corpo);

    setLayout(detail_layout);

    connect(header, &detail_header::torna_indietro, this, detail_view::torna_indietro);
}