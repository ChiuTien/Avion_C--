#pragma once
#include <string>

namespace Models {

    class Avion {
        private:
            int avion_id;
            double x;
            double y;
            double ax;
            double ay;
            double vx;
            double vy;
            double vd;
            double fmax_x;
            double fmax_y;
            double pasfx;
            double pasfy;
            double dPiste;
        public:
            Avion(int id, double x, double v_x, double v_y, double y,
            double v_d, double fmax_x, double fmax_y, double pasf_x, 
            double pasf_y, double a_x, double a_y, double d_p);
            Avion();

            void setAvionId(int id);
            void setX(double x);
            void setY(double y);
            void setAccelerationX(double a);
            void setAccelerationY(double a);
            void setVitesseX(double vitesse);
            void setVitesseY(double vitesse);
            void setVitesseD(double vitesse);
            void setFreinageMX(double freinage);
            void setFreinageMY(double freinage);
            void setPasFreinageX(double pas);
            void setPasFreinageY(double pas);
            void setDistancePiste(double d_p);

            int getAvionId() const;
            double getX() const;
            double getY() const;
            double getAccelerationX() const;
            double getAccelerationY() const;
            double getVitesseX() const;
            double getVitesseY() const;
            double getVitesseD() const;
            double getFreinageMX() const;
            double getFreinageMY() const;
            double getPasFreinageX() const;
            double getPasFreinageY() const;
            double getDistancePiste() const;
    };
} 
