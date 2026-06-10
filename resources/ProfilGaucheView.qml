import QtQuick
import QtQuick.Controls

Item {
    id: profilGaucheView
    width: 1020
    height: 720
    
    // ========== PROPRIÉTÉS ==========
    property double altitudeMax: 3000
    property double distanceMax: 7000
    property double distanceApparitionPiste: 2000
    
    // ========== FOND BLANC ==========
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
        color: "lightblue"
        clip: true
        
        Rectangle {
            id: sol
            width: parent.width
            height: 20
            color: "green"
            anchors.bottom: parent.bottom
            
            Rectangle {
                width: 100
                height: 3
                color: "white"
                anchors.centerIn: parent
            }
        }
        
        // Piste (vue de profil gauche - vue miroir)
        Rectangle {
            id: pisteGraphique
            width: 200
            height: 15
            color: "gray"
            anchors.bottom: sol.top
            border.color: "darkgray"
            border.width: 1
            radius: 2
            
            opacity: {
                if (monSimulationController && monSimulationController.distancePiste !== undefined) {
                    if (monSimulationController.distancePiste <= distanceApparitionPiste) {
                        return 1 - (monSimulationController.distancePiste / distanceApparitionPiste)
                    }
                }
                return 0
            }
            
            x: {
                if (monSimulationController && monSimulationController.distancePiste !== undefined) {
                    if (monSimulationController.distancePiste <= distanceApparitionPiste) {
                        let progression = 1 - (monSimulationController.distancePiste / distanceApparitionPiste)
                        let xMin = avionGraphique.x - width / 2
                        let xMax = avionGraphique.x + 50
                        return xMin + (progression * (xMax - xMin))
                    }
                }
                return parent.width
            }
            
            Text {
                text: "PISTE"
                anchors.centerIn: parent
                font.pixelSize: 10
                font.bold: true
                color: "white"
            }
        }
        
        // Avion (profil gauche - avion tourné vers la gauche)
        Rectangle {
            id: avionGraphique
            width: 50
            height: 25
            color: "red"
            radius: 5
            x: 80
            
            y: {
                if (!monSimulationController || monSimulationController.avionY === undefined) {
                    return sol.y - height - 10
                }
                
                let alt = Math.max(0, monSimulationController.avionY)
                let altNormalisee = Math.min(alt / altitudeMax, 1)
                
                let yMin = 50
                let yMax = sol.y - height - 10
                
                return yMax - (altNormalisee * (yMax - yMin))
            }
            
            rotation: {
                if (!monSimulationController || monSimulationController.vitesseY === undefined) return 0
                return Math.min(Math.max(-monSimulationController.vitesseY * 0.5, -15), 15)
            }
            
            // Avion orienté à gauche
            Text {
                text: "🠜✈️"
                anchors.centerIn: parent
                font.pixelSize: 20
            }
            
            Rectangle {
                anchors.left: parent.right
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                width: 120
                height: 40
                color: "black"
                opacity: 0.7
                radius: 5
                visible: monSimulationController && monSimulationController.distancePiste > 0
                
                Text {
                    text: {
                        if (!monSimulationController) return "Alt: --m\nDist: --m"
                        return "Alt: " + Math.round(monSimulationController.avionY || 0) + "m\nDist: " + Math.round(monSimulationController.distancePiste || 0) + "m"
                    }
                    color: "white"
                    font.pixelSize: 10
                    anchors.centerIn: parent
                }
            }
        }
        
        Rectangle {
            width: 30
            height: 3
            color: "black"
            opacity: 0.2
            anchors.right: avionGraphique.left
            anchors.rightMargin: 5
            anchors.verticalCenter: avionGraphique.verticalCenter
            visible: monSimulationController && monSimulationController.vitesseX > 50
        }
        
        // Nuages
        Rectangle {
            x: 200; y: 100; width: 80; height: 40; radius: 20; color: "white"; opacity: 0.6
        }
        Rectangle {
            x: 600; y: 150; width: 100; height: 45; radius: 22; color: "white"; opacity: 0.5
        }
        Rectangle {
            x: 400; y: 300; width: 70; height: 35; radius: 17; color: "white"; opacity: 0.4
        }
    }
    
    // ========== TABLEAU DE BORD ==========
    Rectangle {
        id: tableauDeBord
        width: parent.width / 3
        height: 180
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        color: "whitesmoke"
        border.color: "lightgray"
        border.width: 1
        
        Grid {
            columns: 2
            spacing: 15
            anchors.centerIn: parent
            
            Text { text: "Vitesse X:"; font.bold: true; color: "black" }
            Text { text: (monSimulationController ? (monSimulationController.vitesseX || 0).toFixed(1) : "0") + " m/s"; color: "blue"; font.bold: true }
            
            Text { text: "Vitesse Y:"; font.bold: true; color: "black" }
            Text { text: (monSimulationController ? (monSimulationController.vitesseY || 0).toFixed(1) : "0") + " m/s"; color: "blue"; font.bold: true }
            
            Text { text: "Altitude:"; font.bold: true; color: "black" }
            Text { text: (monSimulationController ? Math.round(monSimulationController.avionY || 0) : 0) + " m"; color: "blue"; font.bold: true }
            
            Text { text: "Distance piste:"; font.bold: true; color: "black" }
            Text { text: (monSimulationController ? Math.round(monSimulationController.distancePiste || 0) : 0) + " m"; color: "blue"; font.bold: true }
            
            Text { text: "V. décrochage:"; font.bold: true; color: "red" }
            Text { text: (monSimulationController ? (monSimulationController.vitesseDecrochage || 0).toFixed(1) : "0") + " m/s"; color: "red"; font.bold: true }
        }
    }
    
    // ========== CONTROLES ==========
    Rectangle {
        id: zoneControle
        width: parent.width / 3
        height: 180
        anchors.bottom: parent.bottom
        anchors.left: tableauDeBord.right
        color: "snow"
        border.color: "lightgray"
        border.width: 1
        
        Column {
            anchors.centerIn: parent
            spacing: 20
            
            Row {
                spacing: 20
                
                Column {
                    spacing: 5
                    Text { text: "Accélération X"; font.bold: true; color: "black"; font.pixelSize: 12 }
                    Text { text: (monSimulationController ? (monSimulationController.accelerationX || 0).toFixed(2) : "0") + " m/s²"; color: "orange"; font.bold: true }
                    Row {
                        spacing: 10
                        Button { text: "+"; width: 50; onClicked: { if(monSimulationController && monSimulationController.accelererX) monSimulationController.accelererX() } }
                        Button { text: "-"; width: 50; onClicked: { if(monSimulationController && monSimulationController.freinerX) monSimulationController.freinerX() } }
                    }
                }
                
                Column {
                    spacing: 5
                    Text { text: "Accélération Y"; font.bold: true; color: "black"; font.pixelSize: 12 }
                    Text { text: (monSimulationController ? (monSimulationController.accelerationY || 0).toFixed(2) : "0") + " m/s²"; color: "orange"; font.bold: true }
                    Row {
                        spacing: 10
                        Button { text: "+"; width: 50; onClicked: { if(monSimulationController && monSimulationController.accelererY) monSimulationController.accelererY() } }
                        Button { text: "-"; width: 50; onClicked: { if(monSimulationController && monSimulationController.freinerY) monSimulationController.freinerY() } }
                    }
                }
            }
        }
    }
    
    // ========== CHRONOMÈTRE ==========
    Rectangle {
        id: zoneChrono
        width: parent.width / 3
        height: 180
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        color: "ghostwhite"
        border.color: "lightgray"
        border.width: 1
        
        Column {
            anchors.centerIn: parent
            spacing: 15
            
            Text {
                text: monChrono && monChrono.tempsAffiche ? monChrono.tempsAffiche : "00:00"
                font.pixelSize: 32
                font.bold: true
                color: "black"
                font.family: "monospace"
            }
            
            Row {
                spacing: 15
                Button { text: "START"; width: 80; onClicked: { if(monChrono && monChrono.start) monChrono.start() } }
                Button { text: "STOP"; width: 80; onClicked: { if(monChrono && monChrono.stop) monChrono.stop() } }
            }
        }
    }
    
    // ========== BOUTONS DE NAVIGATION VUE ==========
    Row {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 10
        spacing: 10
        
        Button {
            text: "Profil Droit"
            width: 100
            background: Rectangle {
                color: parent.pressed ? "lightgray" : "whitesmoke"
                border.color: "gray"
                radius: 4
            }
            onClicked: {
                if(stackNavigation) {
                    var profilDroit = stackNavigation.push("ProfilDroitView.qml")
                    profilDroit.monSimulationController = monSimulationController
                    profilDroit.monChrono = monChrono
                }
            }
        }
        
        Button {
            text: "Profil Gauche"
            width: 100
            background: Rectangle {
                color: parent.pressed ? "lightgray" : "lightblue"
                border.color: "gray"
                radius: 4
            }
            enabled: false  // Vue actuelle
        }
        
        Button {
            text: "Vue Arrière"
            width: 100
            background: Rectangle {
                color: parent.pressed ? "lightgray" : "whitesmoke"
                border.color: "gray"
                radius: 4
            }
            onClicked: {
                if(stackNavigation) {
                    var vueArriere = stackNavigation.push("VueArriereView.qml")
                    vueArriere.monSimulationController = monSimulationController
                    vueArriere.monChrono = monChrono
                }
            }
        }
    }
    
    // ========== BOUTON RETOUR ==========
    Button {
        text: "← Retour"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10
        background: Rectangle {
            color: parent.pressed ? "lightgray" : "whitesmoke"
            border.color: "gray"
            radius: 4
        }
        onClicked: {
            if(stackNavigation) stackNavigation.pop()
        }
    }
    
    // ========== MESSAGE D'ATTERRISSAGE ==========
    Rectangle {
        anchors.centerIn: parent
        width: 300
        height: 100
        color: "black"
        opacity: 0.8
        radius: 10
        visible: monSimulationController && 
                 monSimulationController.avionY !== undefined && 
                 monSimulationController.avionY <= 10 &&
                 monSimulationController.distancePiste !== undefined && 
                 monSimulationController.distancePiste <= 10
        z: 10
        
        Column {
            anchors.centerIn: parent
            spacing: 10
            
            Text {
                text: "✈️ ATTERRISSAGE ! ✈️"
                color: "green"
                font.bold: true
                font.pixelSize: 18
                anchors.horizontalCenter: parent.horizontalCenter
            }
            
            Button {
                text: "OK"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    if(stackNavigation) stackNavigation.pop()
                }
            }
        }
    }
}