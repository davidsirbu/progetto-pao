#include <QApplication>
#include <QDateTime> // <-- Cambiato in QDateTime!

// I tuoi header (verifica che i percorsi siano giusti)
#include "controller/controller.h"
#include "view/main_window.h"
#include "model/gestore.h"
#include "model/classi/scadenza.h"
#include "controller/controller.h" 

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    gestore mio_gestore;

    controller mio_controller(&mio_gestore);

    main_window m(&mio_controller);

    mio_controller.assegna_main_window(&m);

    m.show();
    return app.exec();
}