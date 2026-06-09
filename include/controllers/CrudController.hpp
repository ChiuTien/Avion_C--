#pragma once
#include <QObject>
#include <QStringList>
#include <QVariantList>

namespace Controllers {

class CrudController : public QObject {
    Q_OBJECT
    
    // Propriétés dynamiques pour que le QML puisse lire les listes à tout moment
    Q_PROPERTY(QStringList listeAvions READ getListeAvions NOTIFY listeAvionsChangee)
    Q_PROPERTY(QStringList listePistes READ getListePistes NOTIFY listePistesChangee)

public:
    explicit CrudController(QObject* parent = nullptr);

    // 👇 Ajoute ces deux getters pour que le QML puisse lire les variables privées
    QStringList getListeAvions() const { return m_listeAvions; }
    QStringList getListePistes() const { return m_listePistes; }

    // --- Fonctions Invokables depuis le QML ---
    
    // Rafraîchir les listes en mémoire depuis le CSV
    Q_INVOKABLE void chargerDonnees();

    // Avion CRUD
    Q_INVOKABLE bool creerAvion(int id, double x, double y, 
                            double ax, double ay, 
                            double vx, double vy, double vd, 
                            double fmax_x, double fmax_y, 
                            double pasfx, double pasfy, 
                            double dPiste);
    Q_INVOKABLE bool supprimerAvion(int id);

    // Piste CRUD
    Q_INVOKABLE bool creerPiste(int id, double longueur, double debutX, double finX);
    Q_INVOKABLE bool supprimerPiste(int id);

signals:
    void listeAvionsChangee();
    void listePistesChangee();

private:
    QStringList m_listeAvions;
    QStringList m_listePistes;
};

} 