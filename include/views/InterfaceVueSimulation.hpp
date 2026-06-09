#pragma once

namespace Views {
    class InterfaceVueSimulation {
        public:
            // Un destructeur virtuel est obligatoire pour la sécurité en mémoire
            virtual ~InterfaceVueSimulation() = default;
            
            // Le "= 0" signifie que la fonction est virtuelle pure (le contrat)
            virtual void provoquerPause() = 0; 
    };
}