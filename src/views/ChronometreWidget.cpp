#include "views/ChronometreWidget.hpp"

namespace Views {

    ChronometreWidget::ChronometreWidget(QObject* parent)
        : QObject(parent), m_millisecondesEcoulees(0), m_dt(0.016), m_tempsAffiche("00:00.00") {
    
        m_timerInterne = new QTimer(this);
    
        // On connecte le timeout du timer à notre fonction d'incrémentation
        connect(m_timerInterne, &QTimer::timeout, this, &ChronometreWidget::incrementerTemps);
    }

    void ChronometreWidget::start() {
        if (!m_timerInterne->isActive()) {
            // 16 ms d'intervalle pour coller au dt de 0.016s (~60Hz)
            m_timerInterne->start(16); 
            emit simulationDemarree();
        }
    }

    void ChronometreWidget::stop() {
        if (m_timerInterne->isActive()) {
            m_timerInterne->stop();
            emit simulationArretee();
        }
    }

    void ChronometreWidget::reset() {
        m_timerInterne->stop();
        m_millisecondesEcoulees = 0;
        m_tempsAffiche = "00:00.00";
    
        emit tempsMisAJour();
        emit tickPhysique(); // On force un tick pour réinitialiser la physique à l'état initial
        emit simulationArretee();
    }

    void ChronometreWidget::incrementerTemps() {
        // On ajoute 16 millisecondes à chaque tick du QTimer
        m_millisecondesEcoulees += 16;

        // --- FORMATAGE DU TEMPS POUR L'AFFICHAGE QML ---
        int minutes = (m_millisecondesEcoulees / 60000) % 60;
        int secondes = (m_millisecondesEcoulees / 1000) % 60;
        int centiemes = (m_millisecondesEcoulees % 1000) / 10;

        // Construit une chaîne comme "01:23.45"
        m_tempsAffiche = QString("%1:%2.%3")
                            .arg(minutes, 2, 10, QChar('0'))
                            .arg(secondes, 2, 10, QChar('0'))
                            .arg(centiemes, 2, 10, QChar('0'));

        // On avertit le QML de rafraîchir l'affichage du texte
        emit tempsMisAJour();

        // 🚀 ON CORRÈLE LA PHYSIQUE : on signale au SimulationController de calculer le pas suivant
        emit tickPhysique();
}
}