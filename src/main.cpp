#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "views/ChronometreWidget.hpp"
#include "controllers/CrudController.hpp"
#include "controllers/SimulationController.hpp" // 👈 1. Ajout de l'en-tête du contrôleur de simulation

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // Créer le moteur QML
    QQmlApplicationEngine engine;

    // Instanciation de nos composants de logique C++
    Controllers::CrudController crudController;
    Views::ChronometreWidget chrono; // 👀 (Vérifie si ta classe est dans un namespace Views:: ou global, adapte si besoin)
    
    Controllers::SimulationController simulationController; // 👈 2. Instanciation du SimulationController

    // 🔗 3. BRANCHEMENT BACK-END : On relie le chronomètre au contrôleur de simulation
    simulationController.setChronometre(&chrono);

    // 🔗 4. RENDRE LE C++ ACCESSIBLE AU QML
    engine.rootContext()->setContextProperty("monCrudController", &crudController);
    engine.rootContext()->setContextProperty("monChrono", &chrono);
    engine.rootContext()->setContextProperty("monSimulationController", &simulationController); // 👈 Exposition au QML

    // Charger le fichier visuel QML
    const QUrl url(QStringLiteral("qrc:/resources/main.qml"));
    engine.load(url);

    return app.exec();
}