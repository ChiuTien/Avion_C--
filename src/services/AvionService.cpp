#include "services/AvionService.hpp"

namespace Services {
    //Constructeur
    AvionService::AvionService() {}

    //Calcule nouvelle vitesse
    void AvionService::nouvelleVitesse(Avion& avion, double dt) {
        double vitesseActuelleX = avion.getVitesseX();
        avion.setVitesseX(avion.getAccelerationX()*dt + vitesseActuelleX);

        double vitesseActuelleY = avion.getVitesseY();
        avion.setVitesseY(avion.getAccelerationY()*dt + vitesseActuelleY);
    }

    //Calcule nouvelle position
    void AvionService::nouvellePosition(Avion& avion, double dt) {
        double positionActuelleX = avion.getX();
        double nouvellePositionX =  0.5*avion.getAccelerationX()*(dt*dt) + avion.getVitesseX()*dt + positionActuelleX;

        double positionActuelleY = avion.getY();
        double nouvellePositionY =  0.5*avion.getAccelerationY()*(dt*dt) + avion.getVitesseY()*dt + positionActuelleY;

        avion.setX(nouvellePositionX);
        avion.setY(nouvellePositionY);
    }

    //Calcule distance par rapport a la piste
    void AvionService::distancePiste(Avion& avion, Piste& piste) {
        avion.setDistancePiste(avion.getX()-piste.getDebutX());
    }

    //Amelioration globale
    void AvionService::evolutionDansTemps(Avion& avion, Piste& piste, double dt) {
        nouvellePosition(avion,dt);
        
        distancePiste(avion,piste);

        nouvelleVitesse(avion,dt);
    }
}