#include "services/AvionService.hpp"

namespace Services {
    //Constructeur
    AvionService::AvionService() {}

    //Calcule nouvelle vitesse
    void AvionService::nouvelleVitesse(Models::Avion& avion, double dt) {
        double vitesseActuelleX = avion.getVitesseX();
        avion.setVitesseX(avion.getAccelerationX()*dt + vitesseActuelleX);

        double vitesseActuelleY = avion.getVitesseY();
        avion.setVitesseY(avion.getAccelerationY()*dt + vitesseActuelleY);
    }

    //Calcule nouvelle position
    void AvionService::nouvellePosition(Models::Avion& avion, double dt) {
        double positionActuelleX = avion.getX();
        double nouvellePositionX =  0.5*avion.getAccelerationX()*(dt*dt) + avion.getVitesseX()*dt + positionActuelleX;

        double positionActuelleY = avion.getY();
        double nouvellePositionY =  0.5*avion.getAccelerationY()*(dt*dt) + avion.getVitesseY()*dt + positionActuelleY;

        avion.setX(nouvellePositionX);
        avion.setY(nouvellePositionY);
    }

    //Calcule distance par rapport a la piste
    void AvionService::distancePiste(Models::Avion& avion, Models::Piste& piste) {
        avion.setDistancePiste(avion.getX()-piste.getDebutX());
    }

    //Atterrissage avion
    void AvionService::atterrissage(Models::Avion& avion) {
        avion.setAccelerationY(0);
        avion.setVitesseY(0);
        avion.setY(0);
    }

    //Amelioration globale
    void AvionService::evolutionDansTemps(Models::Avion& avion, Models::Piste& piste, double dt) {

        if(avion.getY() > 0) {

            if(avion.getVitesseX() <= avion.getVitesseD()) {
                //crash
                return;
            } 

            nouvellePosition(avion,dt);
            distancePiste(avion,piste);
            nouvelleVitesse(avion,dt);

        } else if(avion.getY() <= 0) {

            atterrissage(avion);
            nouvellePosition(avion,dt);
            nouvelleVitesse(avion,dt);

            if(avion.getX() < piste.getDebutX()) {
                //crash
                return;
            }

            if(avion.getX() > piste.getFinX()) {
                //crash
                return;
            }

            if(avion.getVitesseX() <= 0) {
                //atterrissage reussi
                return;
            }
        }
    }
}