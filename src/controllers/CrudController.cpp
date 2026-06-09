#include "controllers/CrudController.hpp"
#include "repositories/AvionDAO.hpp"
#include "repositories/PisteDAO.hpp"
#include <QDebug>

namespace Controllers {

CrudController::CrudController(QObject* parent) : QObject(parent) {
    chargerDonnees(); // On charge les données dès le début
}

void CrudController::chargerDonnees() {
    m_listeAvions.clear();
    m_listePistes.clear();

    // 1. Charger les avions
    QList<Models::Avion*> avions = Repositories::AvionDAO::getAllAvions();
    for (Models::Avion* a : avions) {
        // On crée une chaîne lisible pour l'affichage QML
        m_listeAvions.append(QString("ID: %1 | Alt: %2m | Vmax: %3kt")
                             .arg(a->getAvionId()).arg(a->getY()).arg(a->getVitesseX()));
    }
    qDeleteAll(avions); // Libération mémoire des pointeurs temporaires

    // 2. Charger les pistes
    QList<Models::Piste*> pistes = Repositories::PisteDAO::getAllPistes();
    for (Models::Piste* p : pistes) {
        m_listePistes.append(QString("ID: %1 | Longueur: %2m")
                             .arg(p->getPisteId()).arg(p->getLongueur()));
    }
    qDeleteAll(pistes);

    emit listeAvionsChangee();
    emit listePistesChangee();
}

bool CrudController::creerAvion(int id, double x, double y, 
                                double ax, double ay, 
                                double vx, double vy, double vd, 
                                double fmax_x, double fmax_y, 
                                double pasfx, double pasfy, 
                                double dPiste) {
    Models::Avion nouvelAvion;
    nouvelAvion.setAvionId(id);
    nouvelAvion.setX(x);
    nouvelAvion.setY(y);
    nouvelAvion.setAccelerationX(ax);
    nouvelAvion.setAccelerationY(ay);
    nouvelAvion.setVitesseX(vx);
    nouvelAvion.setVitesseY(vy);
    nouvelAvion.setVitesseD(vd);
    nouvelAvion.setFreinageMX(fmax_x);
    nouvelAvion.setFreinageMY(fmax_y);
    nouvelAvion.setPasFreinageX(pasfx);
    nouvelAvion.setPasFreinageY(pasfy);
    nouvelAvion.setDistancePiste(dPiste);

    bool ok = Repositories::AvionDAO::insertAvion(nouvelAvion);
    if (ok) chargerDonnees(); 
    return ok;
}

bool CrudController::supprimerAvion(int id) {
    bool ok = Repositories::AvionDAO::deleteAvion(id);
    if (ok) chargerDonnees();
    return ok;
}

bool CrudController::creerPiste(int id, double longueur, double debutX, double finX) {
    Models::Piste nouvellePiste(id, longueur, debutX);
    nouvellePiste.setFinX(finX);

    bool ok = Repositories::PisteDAO::insertPiste(nouvellePiste);
    if (ok) chargerDonnees();
    return ok;
}

bool CrudController::supprimerPiste(int id) {
    bool ok = Repositories::PisteDAO::deletePiste(id);
    if (ok) chargerDonnees();
    return ok;
}

}