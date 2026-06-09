#pragma once

#include "Avion.hpp"

namespace Services {
    class AvionService {
        public:
            AvionService();

            void nouvelleVitesse(Avion& avion);
            void nouvellePosition(Avion& avion);
    };
}