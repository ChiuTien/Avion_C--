#include <iostream>
#include "models/Avion.hpp"
#include "models/Piste.hpp"
#include "services/AvionService.hpp"

int main() {
    // 1. Création de la piste (ID: 1, Longueur: 1000m, Début à X = 500m)
    // Donc finX devrait être à 1500m. 
    Models::Piste piste(1, 1000.0, 500.0);
    piste.setFinX(1500.0); // On s'assure que finX est bien initialisé

    // 2. Création de l'avion en vol
    // Position initiale : X = 400m, Y = 50m (légèrement avant la piste)
    // Vitesse initiale : Vx = 80m/s, Vy = -5m/s (il descend)
    // Vitesse de décrochage (Vd) = 60m/s
    // Accélérations : Ax = 0, Ay = 0
    Models::Avion avion(1, 400.0, 80.0, -5.0, 50.0, 60.0, 10.0, 10.0, 1.0, 1.0, 0.0, 0.0, 0.0);

    Services::AvionService service;
    double dt = 1.0; // Pas de temps de 1 seconde
    int secondes = 0;

    std::cout << "--- Début de la simulation d'atterrissage ---" << std::endl;

    // 3. Boucle de simulation (max 30 secondes pour le test)
    while (secondes < 30) {
        std::cout << "[t = " << secondes << "s] "
                  << "Position: (" << avion.getX() << ", " << avion.getY() << ") | "
                  << "Vitesse Vx: " << avion.getVitesseX() << " m/s | "
                  << "Distance Piste: " << avion.getDistancePiste() << "m" << std::endl;

        // Sauvegarde de l'état avant évolution pour détecter un arrêt/crash
        double ancienne_Y = avion.getY();
        double ancienne_Vx = avion.getVitesseX();
        double ancienne_X = avion.getX();

        // Évolution de l'avion
        service.evolutionDansTemps(avion, piste, dt);

        // --- Vérification des conditions d'arrêt ---
        
        // Cas 1: Décrochage en vol
        if (ancienne_Y > 0 && avion.getY() > 0 && avion.getVitesseX() <= avion.getVitesseD()) {
            std::cout << "❌ CRASH : L'avion a décroché en vol (vitesse trop basse) !" << std::endl;
            break;
        }

        // Cas 2: Crash au sol (hors piste ou sortie de piste)
        if (avion.getY() <= 0) {
            if (ancienne_X < piste.getDebutX() || ancienne_X > piste.getFinX()) {
                std::cout << "❌ CRASH : L'avion a touché le sol en dehors de la piste !" << std::endl;
                break;
            }
            if (avion.getX() > piste.getFinX()) {
                std::cout << "❌ CRASH : L'avion est sorti de la piste en roulant !" << std::endl;
                break;
            }
            if (avion.getVitesseX() <= 0) {
                std::cout << "🎉 SUCCÈS : L'avion s'est arrêté en sécurité sur la piste !" << std::endl;
                break;
            }
            
            // Simulation du freinage par l'utilisateur une fois au sol
            // On applique une accélération négative pour simuler les freins
            avion.setAccelerationX(-5.0); 
        }

        secondes++;
    }

    std::cout << "--- Fin de la simulation ---" << std::endl;
    return 0;
}