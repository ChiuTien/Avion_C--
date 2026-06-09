// src/views/ChronometreWidget.cpp
#include "views/ChronometreWidget.hpp"

namespace Views {

    ChronometreWidget::ChronometreWidget(QObject* parent) 
        : QObject(parent), tempsEcoule(0), tempsAffiche("00:00:00") {
        
        minuteur = new QTimer(this);
        
        // 🔗 On connecte le tic du timer à notre fonction de mise à jour
        connect(minuteur, &QTimer::timeout, this, &ChronometreWidget::mettreAjourAffichage);
    }

    void ChronometreWidget::provoquerPause() {
        if (minuteur->isActive()) {
            minuteur->stop();
        } else {
            minuteur->start(1000);
        }
    
        // 📢 On émet le signal pour avertir la vue (QML) que l'état a changé
        emit tempsChange(); 
    }

    void ChronometreWidget::mettreAjourAffichage() {
        // 1. On augmente le compteur de secondes 📈
        tempsEcoule++;

        // 2. On extrait les heures, les minutes et les secondes
        int heures = tempsEcoule / 3600;
        int minutes = (tempsEcoule % 3600) / 60;
        int secondes = tempsEcoule % 60;

        // 3. On formate en "00:00:00" avec des zéros de remplissage 📝
        tempsAffiche = QString("%1:%2:%3")
                        .arg(heures, 2, 10, QChar('0'))
                        .arg(minutes, 2, 10, QChar('0'))
                        .arg(secondes, 2, 10, QChar('0'));

        // 4. 📢 On crie au QML que le texte a changé !
        emit tempsChange();
    }

    ChronometreWidget::~ChronometreWidget() {}
}