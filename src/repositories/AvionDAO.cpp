#include "repositories/AvionDAO.hpp"
#include <QFile>
#include <QTextStream>
#include <QDebug>

namespace Repositories {

    const QString AvionDAO::FILE_NAME = "avions.csv";

    // ➕ CREATE
    bool AvionDAO::insertAvion(const Models::Avion& avion) {
        QFile file(FILE_NAME);
        bool exists = file.exists();

        // Ouverture en mode Append (écriture à la fin)
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            qDebug() << "Erreur d'ouverture pour insertion:" << FILE_NAME;
            return false;
        }

        QTextStream out(&file);
    
        // Si le fichier vient d'être créé, on écrit l'en-tête
        if (!exists || file.size() == 0) {
            out << "id,x,y,ax,ay,vx,vy,vd,fmax_x,fmax_y,pasfx,pasfy,dPiste\n";
        }

        // Écriture des données de l'avion
        out << avion.getAvionId() << ","
            << avion.getX() << ","
            << avion.getY() << ","
            << avion.getAccelerationX() << ","
            << avion.getAccelerationY() << ","
            << avion.getVitesseX() << ","
            << avion.getVitesseY() << ","
            << avion.getVitesseD() << ","
            << avion.getFreinageMX() << ","
            << avion.getFreinageMY() << ","
            << avion.getPasFreinageX() << ","
            << avion.getPasFreinageY() << ","
            << avion.getDistancePiste() << "\n";

        file.close();
        return true;
    }

    // 🔍 READ ALL
    QList<Models::Avion*> AvionDAO::getAllAvions() {
        QList<Models::Avion*> liste;
        QFile file(FILE_NAME);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Si le fichier n'existe pas encore, on renvoie une liste vide tranquillement
            return liste;
        }

        QTextStream in(&file);
    
        // Sauter la ligne d'en-tête
        if (!in.atEnd()) {
            in.readLine();
        }

        // Lecture ligne par ligne
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.trimmed().isEmpty()) continue;

            QStringList tokens = line.split(',');

            // On vérifie qu'on a bien nos 13 colonnes
            if (tokens.size() == 13) {
                Models::Avion* avion = new Models::Avion();
            
                avion->setAvionId(tokens[0].toInt());
                avion->setX(tokens[1].toDouble());
                avion->setY(tokens[2].toDouble());
                avion->setAccelerationX(tokens[3].toDouble());
                avion->setAccelerationY(tokens[4].toDouble());
                avion->setVitesseX(tokens[5].toDouble());
                avion->setVitesseY(tokens[6].toDouble());
                avion->setVitesseD(tokens[7].toDouble());
                avion->setFreinageMX(tokens[8].toDouble());
                avion->setFreinageMY(tokens[9].toDouble());
                avion->setPasFreinageX(tokens[10].toDouble());
                avion->setPasFreinageY(tokens[11].toDouble());
                avion->setDistancePiste(tokens[12].toDouble());

                liste.append(avion);
            }
        }

        file.close();
        return liste;
    }

    // 🔄 UPDATE
    bool AvionDAO::updateAvion(const Models::Avion& avionModifie) {
        // 1. On charge tout en mémoire
        QList<Models::Avion*> liste = getAllAvions();
        bool trouve = false;

        // 2. On cherche l'avion et on applique les modifications
        for (int i = 0; i < liste.size(); ++i) {
            if (liste[i]->getAvionId() == avionModifie.getAvionId()) {
                *liste[i] = avionModifie; // Copie des données
                trouve = true;
                break;
            }
        }

        // Si on n'a rien trouvé, inutile de réécrire le fichier
        if (!trouve) {
            qDeleteAll(liste);
            return false;
        }

        // 3. On écrase le fichier et on réécrit la liste mise à jour
        QFile file(FILE_NAME);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
            qDeleteAll(liste);
            return false;
        }

        QTextStream out(&file);
        out << "id,x,y,ax,ay,vx,vy,vd,fmax_x,fmax_y,pasfx,pasfy,dPiste\n";

        for (Models::Avion* a : liste) {
            out << a->getAvionId() << "," << a->getX() << "," << a->getY() << ","
                << a->getAccelerationX() << "," << a->getAccelerationY() << ","
                << a->getVitesseX() << "," << a->getVitesseY() << "," << a->getVitesseD() << ","
                << a->getFreinageMX() << "," << a->getFreinageMY() << ","
                << a->getPasFreinageX() << "," << a->getPasFreinageY() << ","
                << a->getDistancePiste() << "\n";
        }

        file.close();
        qDeleteAll(liste); // Nettoyage de la mémoire
        return true;
    }

    // ❌ DELETE
    bool AvionDAO::deleteAvion(int id) {
        QList<Models::Avion*> liste = getAllAvions();
        bool supprime = false;

        QFile file(FILE_NAME);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
            qDeleteAll(liste);
            return false;
        }

        QTextStream out(&file);
        out << "id,x,y,ax,ay,vx,vy,vd,fmax_x,fmax_y,pasfx,pasfy,dPiste\n";

        for (Models::Avion* a : liste) {
            // Si l'ID correspond, on ne le réécrit pas dans le fichier
            if (a->getAvionId() == id) {
                supprime = true;
            } else {
                out << a->getAvionId() << "," << a->getX() << "," << a->getY() << ","
                    << a->getAccelerationX() << "," << a->getAccelerationY() << ","
                    << a->getVitesseX() << "," << a->getVitesseY() << "," << a->getVitesseD() << ","
                    << a->getFreinageMX() << "," << a->getFreinageMY() << ","
                    << a->getPasFreinageX() << "," << a->getPasFreinageY() << ","
                    << a->getDistancePiste() << "\n";
            }
        }

        file.close();
        qDeleteAll(liste);
        return supprime;
    }

} 