#include "models/Piste.hpp"

namespace Models {
    //Constructeur
    Piste::Piste() {}
    Piste::Piste(int id, double l, double d) :
        piste_id(id), longueur(l), debutX(d){
            finX = debutX+longueur;
        }


    // Setters
    void Piste::setPisteId(int id) {
        piste_id = id;
    }
    void Piste::setLongueur(double l) {
        longueur = l;
    }
    void Piste::setDebutX(double x) {
        debutX = x;
    }
    void Piste::setFinX(double x) {
        finX = x;
    }

    // Getters
    int Piste::getPisteId() const {
        return piste_id;
    }
    double Piste::getLongueur() const {
        return longueur;
    }
    double Piste::getDebutX() const {
        return debutX;
    }
    double Piste::getFinX() const {
        return finX;
    }
} 
