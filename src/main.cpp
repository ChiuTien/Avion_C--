#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "views/ChronometreWidget.hpp"
#include "controllers/CrudController.hpp"
#include "controllers/SimulationController.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // Créer le moteur QML
    QQmlApplicationEngine engine;

    Models::Avion avionUnique;

    // Instanciation de nos composants de logique C++
    Controllers::CrudController crudController;
    Views::ChronometreWidget chrono; 
    
    Controllers::SimulationController simulationController; 

    // 🔗 3. BRANCHEMENT BACK-END : On relie le chronomètre au contrôleur de simulation
    simulationController.setChronometre(&chrono);

    // 🔗 4. RENDRE LE C++ ACCESSIBLE AU QML
    engine.rootContext()->setContextProperty("monCrudController", &crudController);
    engine.rootContext()->setContextProperty("monChrono", &chrono);
    engine.rootContext()->setContextProperty("monSimulationController", &simulationController); 

    // Charger le fichier visuel QML
    const QUrl url(QStringLiteral("qrc:/resources/main.qml"));
    engine.load(url);

    return app.exec();
}