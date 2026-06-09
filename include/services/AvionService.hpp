#pragma once

#include "models/Avion.hpp"
#include "models/Piste.hpp"

namespace Services {
    class AvionService {
        public:
            AvionService();

            void nouvelleVitesse(Models::Avion& avion, double dt);
            void nouvellePosition(Models::Avion& avion, double dt);
            void evolutionDansTemps(Models::Avion& avion, Models::Piste& piste, double dt);
            void distancePiste(Models::Avion& avion, Models::Piste& piste);
            void atterrissage(Models::Avion& avion);
    };
}