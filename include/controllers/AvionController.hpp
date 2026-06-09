#pragma once

#include "models/Avion.hpp"

namespace Controllers {
    class AvionController {
        private:
            Models::Avion& m_avion;
        public:
            AvionController(Models::Avion& avion) : m_avion(avion) {}

            void accelererX();
            void accelererY();
            void freinerX();
            void freinerY();
            void pause();
    };
}