// src/main.cpp
#include <QApplication>
#include "views/MainWindow.hpp"

int main(int argc, char *argv[]) {
    // 1. Initialise l'application Qt
    QApplication app(argc, argv);

    // 2. Crée l'instance de notre fenêtre
    Views::MainWindow fenetre;

    // 3. Demande à la fenêtre de s'afficher
    fenetre.show();

    // 4. Lance la boucle d'événements de Qt
    return app.exec();
}