// include/views/ChronometreWidget.hpp
#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTimer>


namespace Views {

    class ChronometreWidget : public QObject {
        Q_OBJECT

        Q_PROPERTY(QString tempsAffiche READ getTempsAffiche NOTIFY tempsChange)
        private:
            // Notre moteur de temps
            QTimer* minuteur;
            int tempsEcoule; // En secondes ou millisecondes
            QString tempsAffiche;

            void mettreAjourAffichage();

        signals:
            void tempsChange();

        public:
            ChronometreWidget(QObject* parent = nullptr);
            ~ChronometreWidget();

            QString getTempsAffiche() const {return tempsAffiche; }

            Q_INVOKABLE void provoquerPause();
    };

}