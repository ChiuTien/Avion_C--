#pragma once

#include <QObject>
#include <QStringList>
#include <QList>

#include "models/Avion.hpp"
#include "models/Piste.hpp"
#include "services/AvionService.hpp"

namespace Views {
    class ChronometreWidget;
}

namespace Controllers {

class SimulationController : public QObject {
    Q_OBJECT

    // 🔗 Propriétés de Positionnement (Zone Ciel)
    Q_PROPERTY(double avionX READ getAvionX NOTIFY positionChangee)
    Q_PROPERTY(double avionY READ getAvionY NOTIFY positionChangee)

    // 🔗 Propriétés pour le Tableau de Bord (Zone Gauche)
    Q_PROPERTY(double vitesseX READ getVitesseX NOTIFY positionChangee)
    Q_PROPERTY(double vitesseY READ getVitesseY NOTIFY positionChangee)
    Q_PROPERTY(double accelerationX READ getAccelerationX NOTIFY positionChangee)
    Q_PROPERTY(double accelerationY READ getAccelerationY NOTIFY positionChangee)
    Q_PROPERTY(double distancePiste READ getDistancePiste NOTIFY positionChangee)
    Q_PROPERTY(double vitesseDecrochage READ getVitesseDecrochage NOTIFY positionChangee)

    // 🔗 Propriétés pour l'Écran de Sélection (ComboBox)
    Q_PROPERTY(QStringList modelesAvions READ getModelesAvions NOTIFY listesSelectionChangees)
    Q_PROPERTY(QStringList modelesPistes READ getModelesPistes NOTIFY listesSelectionChangees)

public:
    explicit SimulationController(QObject* parent = nullptr);
    ~SimulationController();

    void setChronometre(Views::ChronometreWidget* chrono);

    // Getters pour l'IHM QML
    double getAvionX() const;
    double getAvionY() const;
    double getVitesseX() const;
    double getVitesseY() const;
    double getAccelerationX() const;
    double getAccelerationY() const;
    double getDistancePiste() const;
    double getVitesseDecrochage() const;

    QStringList getModelesAvions() const { return m_modelesAvions; }
    QStringList getModelesPistes() const { return m_modelesPistes; }

    // --- MÉTHODES INVOQUABLES DEPUIS LE QML ---
    Q_INVOKABLE void chargerOptions();
    Q_INVOKABLE bool selectionnerConfiguration(int indexAvion, int indexPiste);

    // ⚙️ Commandes de vol appelées par tes boutons + et -
    Q_INVOKABLE void accelererX();
    Q_INVOKABLE void freinerX();
    Q_INVOKABLE void accelererY();
    Q_INVOKABLE void freinerY();

signals:
    void positionChangee();
    void listesSelectionChangees();
    void simulationPrete();

private slots:
    void mettreAJourPhysique();

private:
    QStringList m_modelesAvions;
    QStringList m_modelesPistes;

    QList<Models::Avion*> m_listeAvionsFull;
    QList<Models::Piste*> m_listePistesFull;

    Models::Avion* m_avionActif;
    Models::Piste* m_pisteActive;

    Views::ChronometreWidget* m_chrono;

    void nettoyerListesCaches();
};

} // namespace Controllers