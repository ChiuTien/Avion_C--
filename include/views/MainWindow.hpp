// include/views/MainWindow.hpp
#pragma once

#include <QMainWindow>

namespace Views {

    class MainWindow : public QMainWindow {
        Q_OBJECT // Macro obligatoire pour que Qt gère la fenêtre

        public:
            // Le constructeur pour initialiser la fenêtre
            MainWindow(QWidget* parent = nullptr);
            
            // Le destructeur pour nettoyer la mémoire
            ~MainWindow();
    };

}