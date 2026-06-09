#pragma once

#include "models/Avion.hpp"
#include "models/Piste.hpp"

namespace Services {
    class AvionService {
        public:
            AvionService();

            void nouvelleVitesse(Avion& avion, double dt);
            void nouvellePosition(Avion& avion, double dt);
            void evolutionDansTemps(Avion& avion, double dt);
            void distancePiste(Avion& avion, Piste& piste)
    };
}