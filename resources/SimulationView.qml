import QtQuick
import QtQuick.Controls

Item {
    anchors.fill: parent

    // 🌤️ 1. ZONE SUPÉRIEURE : Vue extérieure / Ciel
    Rectangle {
        id: zoneCiel
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: tableauDeBord.top
        color: "#87CEEB"
        clip: true

        property double avionX: 100
        property double avionY: 150

        // 🛣️ La Piste d'atterrissage
        Rectangle {
            id: pisteGraphique
            width: 300; height: 15; color: "#7F8C8D"
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: 50
        }

        // ✈️ L'Avion
        Rectangle {
            id: avionGraphique
            width: 40; height: 20; color: "#FFFFFF"; radius: 5
            x: zoneCiel.avionX; y: zoneCiel.avionY
        }
    }

    // 📊 2. ZONE INFÉRIEURE GAUCHE : Instruments de Vol
    Rectangle {
        id: tableauDeBord
        width: parent.width / 3; height: 200
        anchors.bottom: parent.bottom; anchors.left: parent.left
        color: "#2C3E50"; border.color: "#34495E"; border.width: 2

        Grid {
            columns: 2; spacing: 12; anchors.centerIn: parent
            Text { text: "Vitesse X :"; color: "white"; font.bold: true }
            Text { text: "0.0 kt"; color: "#2ECC71" }
            Text { text: "Vitesse Y :"; color: "white"; font.bold: true }
            Text { text: "0.0 ft/min"; color: "#2ECC71" }
            Text { text: "Altitude :"; color: "white"; font.bold: true }
            Text { text: "0 ft"; color: "#2ECC71" }
            Text { text: "Distance Piste :"; color: "white"; font.bold: true }
            Text { text: "0 m"; color: "#2ECC71" }
            Text { text: "V. Décrochage :"; color: "#E74C3C"; font.bold: true }
            Text { text: "0.0 kt"; color: "#E74C3C" }
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
                Text { text: "0.0 m/s²"; color: "#F1C40F"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Row {
                    spacing: 8
                    Button { text: "+"; width: 40; onClicked: monControllerCplusplus.accelererX() }
                    Button { text: "-"; width: 40; onClicked: monControllerCplusplus.freinerX() }
                }
            }

            Column {
                spacing: 10
                Text { text: "Accélération Y"; color: "white"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Text { text: "0.0 m/s²"; color: "#F1C40F"; font.bold: true; anchors.horizontalCenter: parent.horizontalCenter }
                Row {
                    spacing: 8
                    Button { text: "+"; width: 40; onClicked: monControllerCplusplus.accelererY() }
                    Button { text: "-"; width: 40; onClicked: monControllerCplusplus.freinerY() }
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
                id: affichageChrono
                text: monChronoCplusplus.tempsAffiche
                color: "red"; font.pointSize: 24; font.family: "Courier"; anchors.horizontalCenter: parent.horizontalCenter
            }
            Button {
                id: boutonChrono
                text: "Start / Pause"; anchors.horizontalCenter: parent.horizontalCenter
                onClicked: monChronoCplusplus.provoquerPause()
            }
        }
    }
}