#pragma once

#include <QObject>
#include <QTimer>
#include <QString>

namespace Views {
    
    class ChronometreWidget : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString tempsAffiche READ getTempsAffiche NOTIFY tempsMisAJour)

    public:
        explicit ChronometreWidget(QObject* parent = nullptr);

        Q_INVOKABLE void start();
        Q_INVOKABLE void stop();
        Q_INVOKABLE void reset();

        QString getTempsAffiche() const { return m_tempsAffiche; }
        double getChronoDt() const { return m_dt; } // Retourne le pas de temps (ex: 0.016s)

    signals:
        void tempsMisAJour();
        void tickPhysique(); // 🔄 Émis à chaque milliseconde écoulée pour recalculer la physique
        void simulationDemarree();
        void simulationArretee();

    private slots:
        void incrementerTemps();

    private:
        QTimer* m_timerInterne;
        int m_millisecondesEcoulees;
        double m_dt; // Pas de temps en secondes
        QString m_tempsAffiche;
    };
}