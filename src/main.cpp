// src/main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "views/ChronometreWidget.hpp"
#include "controllers/CrudController.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // 1. Créer le moteur QML
    QQmlApplicationEngine engine;

    Controllers::CrudController crudController;

    // 2. Créer notre composant de logique C++
    Views::ChronometreWidget chrono;

    // 3. 🔗 RENDRE LE C++ ACCESSIBLE AU QML
    // On donne un nom ("monChronoCplusplus") que le QML utilisera pour appeler le C++
    engine.rootContext()->setContextProperty("monCrudController", &crudController);
    engine.rootContext()->setContextProperty("monChronoCplusplus", &chrono);

    // 4. Charger le fichier visuel QML
    const QUrl url(QStringLiteral("qrc:/resources/main.qml"));
    engine.load(url);

    return app.exec();
}