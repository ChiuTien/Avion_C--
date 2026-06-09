#include <iostream>
#include <cassert>
#include "models/Avion.hpp"  
#include "models/Piste.hpp"

int main() {
    std::cout << "⏳ Début des tests unitaires..." << std::endl;

    // 1. Test du modèle Piste 🗺️
    // Supposons un constructeur Piste(double debutX, double longueur)
    Models::Piste maPiste(1, 500.0, 0.0);
    assert(maPiste.getDebutX() == 0.0);
    assert(maPiste.getLongueur() == 500.0);
    std::cout << "✅ Classe Piste : Initialisation réussie !" << std::endl;

    // 2. Test du modèle Avion ✈️
    // Paramètres : id, dPiste, vx, vy, altitude, vd, fmax_x, fmax_y, pasfx, pasfy
    Models::Avion monAvion(1, 1000.0, 250.0, 0.0, 1500.0, 100.0, 50.0, 30.0, 5.0, 2.0);

    assert(monAvion.getAvionId() == 1);
    assert(monAvion.getDistancePiste() == 1000.0);
    assert(monAvion.getVitesseX() == 250.0);
    assert(monAvion.getVitesseY() == 0.0);
    assert(monAvion.getAltitude() == 1500.0);
    assert(monAvion.getVitesseD() == 100.0);
    assert(monAvion.getFreinageMX() == 50.0);
    assert(monAvion.getFreinageMY() == 30.0);
    assert(monAvion.getPasFreinageX() == 5.0);
    assert(monAvion.getPasFreinageY() == 2.0);
    
    std::cout << "✅ Classe Avion : Initialisation réussie !" << std::endl;

    std::cout << "🎉 Tous les tests initiaux sont passés avec succès !" << std::endl;
    return 0;
}