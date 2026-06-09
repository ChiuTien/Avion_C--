#pragma once
#include <QList>
#include <QString>
#include "models/Piste.hpp"

namespace Repositories {

class PisteDAO {
public:
    static const QString FILE_NAME;

    // ➕ Create : Ajouter une piste
    static bool insertPiste(const Models::Piste& piste);

    // 🔍 Read : Récupérer toutes les pistes
    static QList<Models::Piste*> getAllPistes();

    // 🔄 Update : Modifier une piste existante (recherche par ID)
    static bool updatePiste(const Models::Piste& pisteModifiee);

    // ❌ Delete : Supprimer une piste (recherche par ID)
    static bool deletePiste(int id);
};

} 