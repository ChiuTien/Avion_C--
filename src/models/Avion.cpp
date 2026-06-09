#include "models/Avion.hpp"

namespace Models {
    Avion::Avion(int id,double dP,double v_x,double v_y,double a,
    double v_d,double fmax_x,double fmax_y,double pasf_x,double pasf_y): 
    avion_id(id),
    dPiste(dP),
    vx(v_x),
    vy(v_y),
    altitude(a),
    vd(v_d),
    fmax_x(fmax_x),
    fmax_y(fmax_y),
    pasfx(pasf_x),
    pasfy(pasf_y){}

    Avion::Avion() {
        avion_id = 0;
        dPiste = 0.0;
        vx = 0.0;
        vy = 0.0;
        vd = 0.0;
        fmax_x = 0.0;
        fmax_y = 0.0;
        pasfx = 0.0;
        pasfy = 0.0;
    }

    // Setters
    void Avion::setAvionId(int id) {
        avion_id = id;
    }
    void Avion::setDistancePiste(double distance) {
        dPiste = distance;
    }
    void Avion::setVitesseX(double vitesse) {
        vx = vitesse;
    }
    void Avion::setVitesseY(double vitesse) {
        vy = vitesse;
    }
    void Avion::setAltitude(double a) {
        altitude = a;
    }
    void Avion::setVitesseD(double vitesse) {
        vd = vitesse;
    }
    void Avion::setFreinageMX(double freinage) {
        fmax_x = freinage;
    }
    void Avion::setFreinageMY(double freinage) {
        fmax_y = freinage;
    }
    void Avion::setPasFreinageX(double pas) {
        pasfx = pas;
    }
    void Avion::setPasFreinageY(double pas) {
        pasfy = pas;
    }

    // Getters
    int Avion::getAvionId() const {
        return avion_id;
    }
    double Avion::getDistancePiste() const {
        return dPiste;
    }
    double Avion::getVitesseX() const {
        return vx;
    }
    double Avion::getVitesseY() const {
        return vy;
    }
    double Avion::getAltitude() const {
        return altitude;
    }
    double Avion::getVitesseD() const {
        return vd;
    }
    double Avion::getFreinageMX() const {
        return fmax_x;
    }
    double Avion::getFreinageMY() const {
        return fmax_y;
    }
    double Avion::getPasFreinageX() const {
        return pasfx;
    }
    double Avion::getPasFreinageY() const {
        return pasfy;
    }
}