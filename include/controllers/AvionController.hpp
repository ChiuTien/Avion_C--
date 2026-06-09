#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

#include "models/Avion.hpp"

namespace Controllers {

    class AvionController : public QObject {
        Q_OBJECT

        private:
            Models::Avion& avion;
        public:
            explicit AvionController(Models::Avion& m_avion, QObject* parent = nullptr);

            Q_INVOKABLE void accelererX();
            Q_INVOKABLE void accelererY();
            Q_INVOKABLE void freinerX();
            Q_INVOKABLE void freinerY();
    };

}