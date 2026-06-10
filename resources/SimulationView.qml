import QtQuick
import QtQuick.Controls

import QtQuick
import QtQuick.Controls

Item {
    id: simulationView

    // 📐 CONFIGURATION DE L'ÉCHELLE VISUELLE
    // Ces propriétés permettent d'adapter les mètres physiques aux pixels de l'écran.
    // Ajuste ces valeurs selon la taille de ton fichier CSV pour un meilleur rendu.
    property double metreEnPixelX: 0.5  // 1 mètre physique = 0.5 pixel horizontal
    property double metreEnPixelY: 1.2  // 1 mètre physique = 1.2 pixels verticaux (pour bien voir l'altitude)

    // 🌤️ 1. ZONE SUPÉRIEURE : Vue extérieure / Ciel
    Rectangle {
        id: zoneCiel
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: tableauDeBord.top
        color: "#87CEEB"
        clip: true

        // 🛣️ La Piste d'atterrissage dynamique
        Rectangle {
            id: pisteGraphique
            width: 400; height: 15; color: "#7F8C8D"
            anchors.bottom: parent.bottom
        
            // 🔗 LA MAGIE EST ICI : 
            // Au lieu d'être fixe, la piste se déplace vers la gauche 
            // en fonction de la distance restante calculée par le C++.
            // Quand distancePiste vaut 0, la piste arrive pile sous l'avion !
            x: parent.width - 200 - (monSimulationController.distancePiste * 0.2)
        }

        // ✈️ L'Avion Graphique (Version Débug sécurisée)
        Rectangle {
            id: avionGraphique
            width: 40; height: 20
            color: "#FF3366" // 🔴 Mis en rouge flash pour le repérer tout de suite !
            radius: 5
    
            // Position horizontale fixe au premier tiers
            x: parent.width / 3 
    
            // --- 🔗 POSITION VERTICALE SÉCURISÉE ---
            y: {
                // 1. On récupère l'altitude réelle du C++
                let altitudePhysique = monSimulationController.avionY;
        
                // 2. On applique un multiplicateur (échelle) pour tasser l'altitude.
                // Si l'avion est à 500m, il ne montera que de 150 pixels (500 * 0.3).
                let altitudeEnPixels = altitudePhysique * 0.3;
        
                // 3. On calcule la position Y théorique à l'écran
                let yTheorique = (zoneCiel.height - height - 15) - altitudeEnPixels;
        
                // 4. SÉCURITÉ : On force la valeur à rester ENTRE le haut (0) et le bas de l'écran
                // Comme ça, même si l'avion est trop haut ou trop bas, il reste visible sur les bords !
                return Math.max(10, Math.min(yTheorique, zoneCiel.height - height - 15));
            }
    
            Text { 
                text: "✈️"
                anchors.centerIn: parent
                font.pointSize: 14
            }

            // Petit indicateur textuel collé à l'avion pour voir ses coordonnées en temps réel
            Text {
                text: "Y pixel: " + Math.round(parent.y) + "\nY math: " + Math.round(monSimulationController.avionY)
                color: "black"
                font.pointSize: 9
                anchors.left: parent.right
                anchors.leftMargin: 5
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
    // 📊 2. ZONE INFÉRIEURE GAUCHE : Instruments de Vol
    // (Le code reste le même, il affichera les vraies valeurs en mètres)
    Rectangle {
        id: tableauDeBord
        width: parent.width / 3; height: 200
        anchors.bottom: parent.bottom; anchors.left: parent.left
        color: "#2C3E50"; border.color: "#34495E"; border.width: 2

        Grid {
            columns: 2; spacing: 12; anchors.centerIn: parent
            Text { text: "Vitesse X :"; color: "white"; font.bold: true }
            Text { text: monSimulationController.vitesseX.toFixed(1) + " m/s"; color: "#2ECC71" }
            Text { text: "Vitesse Y :"; color: "white"; font.bold: true }
            Text { text: monSimulationController.vitesseY.toFixed(1) + " m/s"; color: "#2ECC71" }
            Text { text: "Altitude :"; color: "white"; font.bold: true }
            Text { text: Math.round(monSimulationController.avionY) + " m"; color: "#2ECC71" }
            Text { text: "Distance Piste :"; color: "white"; font.bold: true }
            Text { text: Math.round(monSimulationController.distancePiste) + " m"; color: "#2ECC71" }
            Text { text: "V. Décrochage :"; color: "#E74C3C"; font.bold: true }
            Text { text: monSimulationController.vitesseDecrochage.toFixed(1) + " m/s"; color: "#E74C3C" }
        }
    }

    // ⚙️ 3. ZONE INFÉRIEURE MILIEU : Contrôle des Accélérations
    Rectangle {
        id: zoneControle
        width: parent.width / 3; height: 200
        anchors.bottom: parent.bottom; anchors.left: tableauDeBord.right
        color: "#34495E"; border.color: "#2C3E50"; border.width: 2

        Row {
            anchors.centerIn: parent; spacing: 30

            Column {
                spacing: 10
                Text { text: "Accélération X"; color: "white"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Text { text: monSimulationController.accelerationX.toFixed(2) + " m/s²"; color: "#F1C40F"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Row {
                    spacing: 8
                    // 🔗 Connecté aux méthodes du nouveau contrôleur
                    Button { text: "+"; width: 40; onClicked: monSimulationController.accelererX() }
                    Button { text: "-"; width: 40; onClicked: monSimulationController.freinerX() }
                }
            }

            Column {
                spacing: 10
                Text { text: "Accélération Y"; color: "white"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Text { text: monSimulationController.accelerationY.toFixed(2) + " m/s²"; color: "#F1C40F"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Row {
                    spacing: 8
                    Button { text: "+"; width: 40; onClicked: monSimulationController.accelererY() }
                    Button { text: "-"; width: 40; onClicked: monSimulationController.freinerY() }
                }
            }
        }
    }

    // ⏱️ 4. ZONE INFÉRIEURE DROITE : Le Chronomètre
    Rectangle {
        id: zoneChrono
        width: parent.width / 3; height: 200
        anchors.bottom: parent.bottom; anchors.right: parent.right
        color: "#1A1A1A"; border.color: "#34495E"; border.width: 2

        Column {
            anchors.centerIn: parent; spacing: 15
            Text {
                text: monChrono.tempsAffiche 
                font.pointSize: 26
                color: "white"
            }

            Button {
                text: "START ▶"
                onClicked: monChrono.start() 
            }

            Button {
                text: "STOP ⏸"
                onClicked: monChrono.stop()  
            }
        }
    }
}