#include "gestore_file.h"
#include <QFile>
#include <QByteArray>

bool gestore_file::scrivi_file(const QString& percorso, const QJsonDocument& documento) const {
    QFile file(percorso);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;

    file.write(documento.toJson());
    file.close();

    return true;
}

QJsonDocument gestore_file::leggi_file(const QString& percorso) const {
    QFile file(percorso);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return QJsonDocument();

    QByteArray dati_grezzi = file.readAll();
    file.close();
    
    return QJsonDocument::fromJson(dati_grezzi);
}