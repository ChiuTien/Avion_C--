#include "controllers/SimulationController.hpp"
#include "repositories/AvionDAO.hpp"
#include "repositories/PisteDAO.hpp"
#include "views/ChronometreWidget.hpp"
#include <QDebug>

namespace Controllers {

SimulationController::SimulationController(QObject* parent)
    : QObject(parent), m_avionActif(nullptr), m_pisteActive(nullptr), m_chrono(nullptr) {
    chargerOptions();
}

SimulationController::~SimulationController() {
    nettoyerListesCaches();
    if (m_avionActif) delete m_avionActif;
    if (m_pisteActive) delete m_pisteActive;
}

void SimulationController::setChronometre(Views::ChronometreWidget* chrono) {
    m_chrono = chrono;
    if (m_chrono) {
        connect(m_chrono, &Views::ChronometreWidget::tickPhysique, this, &SimulationController::mettreAJourPhysique);
    }
}

// Implementations des Getters liés aux propriétés QML
double SimulationController::getAvionX() const { return m_avionActif ? m_avionActif->getX() : 0.0; }
double SimulationController::getAvionY() const { return m_avionActif ? m_avionActif->getY() : 0.0; }
double SimulationController::getVitesseX() const { return m_avionActif ? m_avionActif->getVitesseX() : 0.0; }
double SimulationController::getVitesseY() const { return m_avionActif ? m_avionActif->getVitesseY() : 0.0; }
double SimulationController::getAccelerationX() const { return m_avionActif ? m_avionActif->getAccelerationX() : 0.0; }
double SimulationController::getAccelerationY() const { return m_avionActif ? m_avionActif->getAccelerationY() : 0.0; }
double SimulationController::getDistancePiste() const { return m_avionActif ? m_avionActif->getDistancePiste() : 0.0; }
double SimulationController::getVitesseDecrochage() const { return m_avionActif ? m_avionActif->getVitesseD() : 0.0; }

void SimulationController::nettoyerListesCaches() {
    qDeleteAll(m_listeAvionsFull);
    qDeleteAll(m_listePistesFull);
    m_listeAvionsFull.clear();
    m_listePistesFull.clear();
}

void SimulationController::chargerOptions() {
    nettoyerListesCaches();
    m_modelesAvions.clear();
    m_modelesPistes.clear();

    m_listeAvionsFull = Repositories::AvionDAO::getAllAvions();
    for (Models::Avion* a : m_listeAvionsFull) {
        m_modelesAvions.append(QString("ID: %1 | Initial X: %2m, Y: %3m")
                               .arg(a->getAvionId()).arg(a->getX()).arg(a->getY()));
    }

    m_listePistesFull = Repositories::PisteDAO::getAllPistes();
    for (Models::Piste* p : m_listePistesFull) {
        m_modelesPistes.append(QString("Piste ID: %1 (Longueur: %2 m)")
                               .arg(p->getPisteId()).arg(p->getLongueur()));
    }

    emit listesSelectionChangees();
}

bool SimulationController::selectionnerConfiguration(int indexAvion, int indexPiste) {
    if (indexAvion < 0 || indexAvion >= m_listeAvionsFull.size() ||
        indexPiste < 0 || indexPiste >= m_listePistesFull.size()) {
        return false;
    }

    if (m_avionActif) delete m_avionActif;
    if (m_pisteActive) delete m_pisteActive;

    // Récupération stricte de l'état initial décrit par ton CSV
    m_avionActif = new Models::Avion(*m_listeAvionsFull[indexAvion]);
    m_pisteActive = new Models::Piste(*m_listePistesFull[indexPiste]);

    qDebug() << "✈️ Vol initialisé aux coordonnées CSV. X:" << m_avionActif->getX() << "Y:" << m_avionActif->getY();

    emit positionChangee(); 
    emit simulationPrete();
    return true;
}

// ⚙️ Gestion dynamique des commandes depuis l'IHM
void SimulationController::accelererX() {
    if (!m_avionActif) return;
    m_avionActif->setAccelerationX(m_avionActif->getAccelerationX() - m_avionActif->getPasFreinageX());
    emit positionChangee();
}

void SimulationController::freinerX() {
    if (!m_avionActif) return;
    double nouvelleAcceleration = m_avionActif->getAccelerationX() + m_avionActif->getPasFreinageX();
    if(m_avionActif->getFreinageMX() <= nouvelleAcceleration) {
        m_avionActif->setAccelerationX(nouvelleAcceleration);
    }
    emit positionChangee();
}

void SimulationController::accelererY() {
    if (!m_avionActif) return;
    m_avionActif->setAccelerationY(m_avionActif->getAccelerationY() - m_avionActif->getPasFreinageY());
    emit positionChangee();
}

void SimulationController::freinerY() {
    if (!m_avionActif) return;
    double nouvelleAcceleration = m_avionActif->getAccelerationY() + m_avionActif->getPasFreinageY();
    if(m_avionActif->getFreinageMY() <= nouvelleAcceleration) {
        m_avionActif->setAccelerationY(nouvelleAcceleration);
    }
    emit positionChangee();
}

void SimulationController::mettreAJourPhysique() {
    if (!m_avionActif || !m_pisteActive || !m_chrono) return;

    double dt = m_chrono->getChronoDt();
    Services::AvionService avionService;

    // Calculs métiers
    avionService.evolutionDansTemps(*m_avionActif, *m_pisteActive, dt);

    // Rafraîchissement global des compteurs et de la position
    emit positionChangee();
}

} // namespace Controllers