// src/views/MainWindow.cpp
#include "views/MainWindow.hpp"

namespace Views {

    // Constructeur : on passe le parent à la classe de base QMainWindow
    MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
        // C'est ici qu'on va configurer les options de la fenêtre
        this->setWindowTitle("Simulateur de Vol");
        this->resize(800, 600); // Taille initiale de la fenêtre 📐
    }

    // Destructeur
    MainWindow::~MainWindow() {
        // Rien à libérer pour le moment 🧹
    }

}