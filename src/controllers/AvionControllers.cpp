#include "controllers/AvionController.hpp"

namespace Controllers {
    //Constructeur
    AvionController::AvionController(Models::Avion& m_avion) : avion(M_avion) {}

    //Accelere en x
    void AvionController::accelererX() {
        avion.setAccelerationX(avion.getAccelerationX()-avion.getPasFreinageX());
    }
    //Accelere en y
    void AvionController::accelererY() {
        avion.setAccelerationY(avion.getAccelerationY()-avion.getPasFreinageY());
    }
    //Freiner en x
    void AvionController::freinerX() {
        double nouvelleAcceleration = avion.getAccelerationX()+avion.getPasFreinageX();
        if(avion.getFreinageMX()<=nouvelleAcceleration) {
            avion.setAccelerationX(nouvelleAcceleration);
        }
    }
    //Freiner en y
    void AvionController::freinerY() {
        double nouvelleAcceleration = avion.getAccelerationY()+avion.getPasFreinageY();
        if(avion.getFreinageMY()<=nouvelleAcceleration) {
            avion.setAccelerationY(nouvelleAcceleration);
        }
    }
    //Mettre toute la simulation en pause
    void AvionController::pause() {
        //je ne sais pas encore
    }
} 
