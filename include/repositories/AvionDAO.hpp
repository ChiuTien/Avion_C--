#pragma once
#include <QList>
#include <QString>
#include "models/Avion.hpp"

namespace Repositories {

    class AvionDAO {
        public:
            static const QString FILE_NAME;

            // ➕ Create : Ajouter un avion
            static bool insertAvion(const Models::Avion& avion);

            // 🔍 Read : Récupérer tous les avions
            static QList<Models::Avion*> getAllAvions();

            // 🔄 Update : Modifier un avion existant (recherche par ID)
            static bool updateAvion(const Models::Avion& avionModifie);

            // ❌ Delete : Supprimer un avion (recherche par ID)
            static bool deleteAvion(int id);
    };
    
}