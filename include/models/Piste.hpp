#pragma once

namespace Models {
    class Piste {
        private:
            int piste_id;
            double longueur;
            double debutX;
            double finX;
        public:
            Piste();
            Piste(int id, double l, double d);

            void setPisteId(int id);
            void setLongueur(double l);
            void setDebutX(double x);
            void setFinX(double x);

            int getPisteId() const;
            double getLongueur() const;
            double getDebutX() const;
            double getFinX() const;
    };
}