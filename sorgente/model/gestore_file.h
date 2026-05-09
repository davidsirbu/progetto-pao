#ifndef GESTORE_FILE_H
#define GESTORE_FILE_H

#include <QString>
#include <QJsonDocument>

class gestore_file {
    public:
        gestore_file() = default;

        bool scrivi_file(const QString& percorso, const QJsonDocument& documento) const;

        QJsonDocument leggi_file(const QString& percorso) const;
};

#endif