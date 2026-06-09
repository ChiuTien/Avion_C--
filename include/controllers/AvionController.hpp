#pragma once

#include "models/Avion.hpp"
#include "views/InterfaceVueSimulation.hpp"

namespace Controllers {
    class AvionController {
        private:
            Models::Avion& avion;
            Views::InterfaceVueSimulation* vue;
        public:
            AvionController(Models::Avion& avion);

            void accelererX();
            void accelererY();
            void freinerX();
            void freinerY();
            void pause();
    };
}