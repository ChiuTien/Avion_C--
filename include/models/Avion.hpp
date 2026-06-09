#pragma once
#include <string>

namespace Models {

    class Avion {
        private:
            int avion_id;
            double dPiste;
            double altitude;
            double ax;
            double ay;
            double vx;
            double vy;
            double vd;
            double fmax_x;
            double fmax_y;
            double pasfx;
            double pasfy;
        public:
            Avion(int id, double dP, double v_x, double v_y, double a,
            double v_d, double fmax_x, double fmax_y, double pasf_x, 
            double pasf_y, double a_x, double a_y);
            Avion();

            void setAvionId(int id);
            void setDistancePiste(double distance);
            void setAltitude(double altitude);
            void setAccelerationX(double a);
            void setAccelerationY(double a);
            void setVitesseX(double vitesse);
            void setVitesseY(double vitesse);
            void setVitesseD(double vitesse);
            void setFreinageMX(double freinage);
            void setFreinageMY(double freinage);
            void setPasFreinageX(double pas);
            void setPasFreinageY(double pas);

            int getAvionId() const;
            double getDistancePiste() const;
            double getAltitude() const;
            double getAccelerationX() const;
            double getAccelerationY() const;
            double getVitesseX() const;
            double getVitesseY() const;
            double getVitesseD() const;
            double getFreinageMX() const;
            double getFreinageMY() const;
            double getPasFreinageX() const;
            double getPasFreinageY() const;
    };
} 
