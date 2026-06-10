import QtQuick
import QtQuick.Controls
import QtQuick.Shapes

Item {
    id: vueArriereView
    width: 1020
    height: 720
    
    // ========== PROPRIÉTÉS ==========
    property double altitudeMax: 3000
    property double distanceApparitionPiste: 2500
    
    // ========== FOND BLANC DE SÉCURITÉ ==========
    Rectangle {
        anchors.fill: parent
        color: "white"
    }
    
    // ========== ZONE CIEL ==========
    Rectangle {
        id: zoneCiel
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 520
        color: "#9AD1E4" 
        clip: true
        
        // ========== SOLEIL ==========
        Rectangle {
            id: soleil
            width: 70
            height: 70
            radius: 35
            color: "#FFF275"
            x: 880; y: 40 
            opacity: 0.9
        }
        
        // Nuages style BD
        Rectangle { x: 100; y: 80; width: 140; height: 45; radius: 22; color: "white"; opacity: 0.9 }
        Rectangle { x: 450; y: 110; width: 100; height: 35; radius: 17; color: "white"; opacity: 0.9 }
        Rectangle { x: 750; y: 130; width: 130; height: 42; radius: 21; color: "white"; opacity: 0.8 }
        
        // ========== SOL VERT ==========
        // Il fait le tiers inférieur de la zone de visualisation
        Rectangle {
            id: sol
            width: parent.width
            height: 180 
            color: "#5CB835" 
            anchors.bottom: parent.bottom
        }
        
        // ========== PISTE EN VRAIE PERSPECTIVE VECTORIELLE ==========
        // Elle est placée par-dessus le sol et remonte jusqu'à la ligne d'horizon
        Shape {
            id: pistePerspective
            width: parent.width
            height: sol.height
            anchors.bottom: parent.bottom
            layer.enabled: true
            layer.samples: 4 

            // Calcul de la progression de la taille de la piste (0.0 au début, 1.0 à la fin)
            property double progression: {
                if (monSimulationController && monSimulationController.distancePiste !== undefined) {
                    if (monSimulationController.distancePiste <= distanceApparitionPiste) {
                        return 1.0 - (monSimulationController.distancePiste / distanceApparitionPiste)
                    }
                    return 0.0 // Invisible si trop loin
                }
                return 1.0 // Valeur test par défaut si pas de contrôleur connecté
            }

            // L'opacité augmente à mesure qu'on approche
            opacity: progression > 0 ? 0.2 + (progression * 0.8) : 0.0

            // Dessin du trapèze gris de la piste
            ShapePath {
                fillColor: "#7F8C8D" // Gris asphalte
                strokeColor: "#BDC3C7"
                strokeWidth: 2

                // Point 1 : Haut Gauche (A l'horizon, très serré au centre)
                // Au début de l'apparition, la piste est un fil (largeur 10px). À la fin, elle s'élargit un peu à l'horizon (50px).
                startX: (pistePerspective.width / 2) - (5 + pistePerspective.progression * 20)
                startY: 0

                // Point 2 : Haut Droit (À l'horizon)
                PathLine { 
                    x: (pistePerspective.width / 2) + (5 + pistePerspective.progression * 20)
                    y: 0 
                }
                
                // Point 3 : Bas Droit (Au bas de l'écran, s'évase énormément jusqu'à 350px du centre)
                PathLine { 
                    x: (pistePerspective.width / 2) + (15 + pistePerspective.progression * 350)
                    y: pistePerspective.height 
                }
                
                // Point 4 : Bas Gauche (Au bas de l'écran)
                PathLine { 
                    x: (pistePerspective.width / 2) - (15 + pistePerspective.progression * 350)
                    y: pistePerspective.height 
                }
                
                // Fermeture du tracé vers le Point 1
                PathLine { 
                    x: (pistePerspective.width / 2) - (5 + pistePerspective.progression * 20)
                    y: 0 
                }
            }

            // Ligne blanche centrale en perspective pointillée
            ShapePath {
                fillColor: "transparent"
                strokeColor: "white"
                strokeWidth: 3
                strokeStyle: ShapePath.DashLine
                dashPattern: [8, 15]

                startX: pistePerspective.width / 2
                startY: 0
                PathLine { x: pistePerspective.width / 2; y: pistePerspective.height }
            }
        }
        
        // ========== AVION (Vue arrière, centré) ==========
        Item {
            id: avionContainer
            width: 160
            height: 100
            anchors.horizontalCenter: parent.horizontalCenter
            
            // Calcul vertical strict basé sur l'altitude
            y: {
                if (!monSimulationController || monSimulationController.avionY === undefined) {
                    return zoneCiel.height - 220 // Position de test au milieu
                }
                let alt = Math.max(0, monSimulationController.avionY)
                let altNormalisee = Math.min(alt / altitudeMax, 1)
                
                let yMin = 40  // Altitude maximale (haut du ciel)
                let yMax = zoneCiel.height - 130 // Altitude 0 (posé sur la piste)
                
                return yMax - (altNormalisee * (yMax - yMin))
            }
            
            // Les Grandes Ailes Rouges horizontales
            Rectangle {
                width: 140; height: 10
                radius: 3
                color: "red"
                anchors.centerIn: parent
            }

            // Moteurs ronds sous les ailes
            Rectangle { width: 14; height: 14; radius: 7; color: "#3A3A3A"; x: 42; y: 48 }
            Rectangle { width: 14; height: 14; radius: 7; color: "#3A3A3A"; x: 104; y: 48 }

            // Fuselage central (Rond vu de dos)
            Rectangle {
                id: corpsAvion
                width: 36; height: 36
                radius: 18
                color: "red"
                anchors.centerIn: parent
                border.color: "darkred"
                border.width: 1

                // Tuyère noire
                Rectangle {
                    width: 12; height: 12; radius: 6; color: "#1A1A1A"
                    anchors.centerIn: parent
                }
            }
            
            // Dérive verticale (Aileron du haut)
            Rectangle {
                width: 8; height: 32
                radius: 2
                color: "red"
                anchors.bottom: corpsAvion.top
                anchors.bottomMargin: -4
                anchors.horizontalCenter: corpsAvion.horizontalCenter
            }
            
            // Stabilisateurs horizontaux arrière
            Rectangle { width: 25; height: 6; radius: 2; color: "red"; anchors.right: corpsAvion.left; anchors.rightMargin: -4; y: 40 }
            Rectangle { width: 25; height: 6; radius: 2; color: "red"; anchors.left: corpsAvion.right; anchors.leftMargin: -4; y: 40 }
            
            // Bulle d'infos de vol (HUD)
            Rectangle {
                anchors.left: parent.right
                anchors.leftMargin: 25
                anchors.verticalCenter: parent.verticalCenter
                width: 130; height: 45
                color: "#1E293B"
                opacity: 0.8
                radius: 5
                visible: monSimulationController && monSimulationController.distancePiste > 0
                
                Text {
                    text: "ALT : " + Math.round(monSimulationController?.avionY || 0) + " m\nDIST: " + Math.round(monSimulationController?.distancePiste || 0) + " m"
                    color: "#0EA5E9"
                    font.pixelSize: 10
                    font.bold: true
                    font.family: "monospace"
                    anchors.centerIn: parent
                }
            }
        }
    }
    
    // ========== TABLEAU DE BORD (Bas Gauche) ==========
    Rectangle {
        id: tableauDeBord
        width: parent.width / 3; height: 200
        anchors.bottom: parent.bottom; anchors.left: parent.left
        color: "#2C3E50"; border.color: "#34495E"; border.width: 2
        
        Grid {
            columns: 2; spacing: 12; anchors.centerIn: parent
            Text { text: "Vitesse X :"; color: "white"; font.bold: true }
            Text { text: (monSimulationController ? (monSimulationController.vitesseX || 0).toFixed(1) : "0") + " m/s"; color: "#2ECC71" }
            Text { text: "Vitesse Y :"; color: "white"; font.bold: true }
            Text { text: (monSimulationController ? (monSimulationController.vitesseY || 0).toFixed(1) : "0") + " m/s"; color: "#2ECC71" }
            Text { text: "Altitude :"; color: "white"; font.bold: true }
            Text { text: (monSimulationController ? Math.round(monSimulationController.avionY || 0) : 0) + " m"; color: "#2ECC71" }
            Text { text: "Distance Piste :"; color: "white"; font.bold: true }
            Text { text: (monSimulationController ? Math.round(monSimulationController.distancePiste || 0) : 0) + " m"; color: "#2ECC71" }
            Text { text: "V. Décrochage :"; color: "#E74C3C"; font.bold: true }
            Text { text: (monSimulationController ? (monSimulationController.vitesseDecrochage || 0).toFixed(1) : "0") + " m/s"; color: "#E74C3C" }
        }
    }
    
    // ========== ZONE DE CONTRÔLES (Bas Milieu) ==========
    Rectangle {
        id: zoneControle
        width: parent.width / 3; height: 200
        anchors.bottom: parent.bottom; anchors.left: tableauDeBord.right
        color: "#34495E"; border.color: "#2C3E50"; border.width: 2
        
        Row {
            anchors.centerIn: parent; spacing: 30
            Column {
                spacing: 10; padding: 5
                Text { text: "Accélération X"; color: "white"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Text { text: (monSimulationController ? (monSimulationController.accelerationX || 0).toFixed(2) : "0") + " m/s²"; color: "#F1C40F"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Row {
                    spacing: 8
                    Button { text: "+"; width: 45; onClicked: { if(monSimulationController?.accelererX) monSimulationController.accelererX() } }
                    Button { text: "-"; width: 45; onClicked: { if(monSimulationController?.freinerX) monSimulationController.freinerX() } }
                }
            }
            Column {
                spacing: 10; padding: 5
                Text { text: "Accélération Y"; color: "white"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Text { text: (monSimulationController ? (monSimulationController.accelerationY || 0).toFixed(2) : "0") + " m/s²"; color: "#F1C40F"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Row {
                    spacing: 8
                    Button { text: "+"; width: 45; onClicked: { if(monSimulationController?.accelererY) monSimulationController.accelererY() } }
                    Button { text: "-"; width: 45; onClicked: { if(monSimulationController?.freinerY) monSimulationController.freinerY() } }
                }
            }
        }
    }
    
    // ========== CHRONOMÈTRE (Bas Droite) ==========
    Rectangle {
        id: zoneChrono
        width: parent.width / 3; height: 200
        anchors.bottom: parent.bottom; anchors.right: parent.right
        color: "#1A1A1A"; border.color: "#34495E"; border.width: 2
        
        Column {
            anchors.centerIn: parent; spacing: 15
            Text {
                text: monChrono && monChrono.tempsAffiche ? monChrono.tempsAffiche : "00:00"
                font.pixelSize: 28; font.bold: true; color: "white"; font.family: "monospace"
            }
            Row {
                spacing: 12
                Button { text: "START ▶"; onClicked: { if(monChrono?.start) monChrono.start() } }
                Button { text: "STOP ⏸"; onClicked: { if(monChrono?.stop) monChrono.stop() } }
            }
        }
    }
    
    // ========== NAVIGATION INTER-VUES ==========
    Row {
        anchors.top: parent.top; anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 10; spacing: 10
        Button { text: "Profil Droit"; width: 110; onClicked: { if(stackNavigation) stackNavigation.push("SimulationView.qml") } }
        Button { text: "Profil Gauche"; width: 110; onClicked: { if(stackNavigation) stackNavigation.push("ProfilGaucheView.qml") } }
        Button { text: "Vue Arrière"; width: 110; enabled: false }
    }
    
    Button {
        text: "← Retour"; anchors.top: parent.top; anchors.left: parent.left; anchors.margins: 10
        onClicked: { if(stackNavigation) stackNavigation.pop() }
    }
}