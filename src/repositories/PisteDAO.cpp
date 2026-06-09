#include "repositories/PisteDAO.hpp"
#include <QFile>
#include <QTextStream>
#include <QDebug>

namespace Repositories {

const QString PisteDAO::FILE_NAME = "pistes.csv";

// ➕ CREATE
bool PisteDAO::insertPiste(const Models::Piste& piste) {
    QFile file(FILE_NAME);
    bool exists = file.exists();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Erreur d'ouverture pour insertion:" << FILE_NAME;
        return false;
    }

    QTextStream out(&file);
    
    // Si le fichier est tout neuf, on met le header
    if (!exists || file.size() == 0) {
        out << "id,longueur,debutX,finX\n";
    }

    // Écriture des données de la piste
    out << piste.getPisteId() << ","
        << piste.getLongueur() << ","
        << piste.getDebutX() << ","
        << piste.getFinX() << "\n";

    file.close();
    return true;
}

// 🔍 READ ALL
QList<Models::Piste*> PisteDAO::getAllPistes() {
    QList<Models::Piste*> liste;
    QFile file(FILE_NAME);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return liste; // On retourne une liste vide si le fichier n'existe pas
    }

    QTextStream in(&file);
    
    // Sauter l'en-tête
    if (!in.atEnd()) {
        in.readLine();
    }

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.trimmed().isEmpty()) continue;

        QStringList tokens = line.split(',');

        // On vérifie qu'on a bien nos 4 colonnes
        if (tokens.size() == 4) {
            Models::Piste* piste = new Models::Piste();
            
            piste->setPisteId(tokens[0].toInt());
            piste->setLongueur(tokens[1].toDouble());
            piste->setDebutX(tokens[2].toDouble());
            piste->setFinX(tokens[3].toDouble());

            liste.append(piste);
        }
    }

    file.close();
    return liste;
}

// 🔄 UPDATE
bool PisteDAO::updatePiste(const Models::Piste& pisteModifiee) {
    QList<Models::Piste*> liste = getAllPistes();
    bool trouve = false;

    for (int i = 0; i < liste.size(); ++i) {
        if (liste[i]->getPisteId() == pisteModifiee.getPisteId()) {
            *liste[i] = pisteModifiee;
            trouve = true;
            break;
        }
    }

    if (!trouve) {
        qDeleteAll(liste);
        return false;
    }

    QFile file(FILE_NAME);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        qDeleteAll(liste);
        return false;
    }

    QTextStream out(&file);
    out << "id,longueur,debutX,finX\n";

    for (Models::Piste* p : liste) {
        out << p->getPisteId() << ","
            << p->getLongueur() << ","
            << p->getDebutX() << ","
            << p->getFinX() << "\n";
    }

    file.close();
    qDeleteAll(liste);
    return true;
}

// ❌ DELETE
bool PisteDAO::deletePiste(int id) {
    QList<Models::Piste*> liste = getAllPistes();
    bool supprime = false;

    QFile file(FILE_NAME);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        qDeleteAll(liste);
        return false;
    }

    QTextStream out(&file);
    out << "id,longueur,debutX,finX\n";

    for (Models::Piste* p : liste) {
        if (p->getPisteId() == id) {
            supprime = true;
        } else {
            out << p->getPisteId() << ","
                << p->getLongueur() << ","
                << p->getDebutX() << ","
                << p->getFinX() << "\n";
        }
    }

    file.close();
    qDeleteAll(liste);
    return supprime;
}

} // namespace Database