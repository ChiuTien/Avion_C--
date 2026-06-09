#pragma once

#include "models/Avion.hpp"

namespace Controllers {
    class AvionController {
        private:
            Models::Avion& avion;
        public:
            AvionController(Models::Avion& avion);

            void accelererX();
            void accelererY();
            void freinerX();
            void freinerY();
            void pause();
    };
}