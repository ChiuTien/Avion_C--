import QtQuick
import QtQuick.Controls

Item {
    id: configurationView
    //anchors.fill: parent

    // Signal pour avertir le main.qml qu'on veut lancer la simulation
    signal simulationLancee()

    Rectangle {
        anchors.fill: parent
        color: "#2C3E50" // Fond bleu nuit / cockpit

        Column {
            anchors.centerIn: parent
            spacing: 30
            width: parent.width * 0.8

            Text {
                text: "Configuration de la Simulation"
                color: "white"
                font.pointSize: 24
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            // --- Sélection de l'Avion ---
            Column {
                spacing: 10
                width: parent.width
                
                Text { text: "Choisir un Avion :"; color: "#ECF0F1"; font.pointSize: 14 }
                ComboBox {
                    id: comboAvion
                    width: parent.width
                    model: ["Cesna 172", "Boeing 737", "Airbus A320"]
                }
            }

            // --- Sélection de la Piste ---
            Column {
                spacing: 10
                width: parent.width

                Text { text: "Choisir une Piste d'Atterrissage :"; color: "#ECF0F1"; font.pointSize: 14 }
                ComboBox {
                    id: comboPiste
                    width: parent.width
                    model: ["Piste Principale (3000m)", "Piste Courte (1500m)", "Piste Secondaire (2000m)"]
                }
            }

            // --- Bouton de validation ---
            Button {
                text: "Prêt pour le décollage 🚀"
                width: 250
                height: 50
                anchors.horizontalCenter: parent.horizontalCenter
                
                onClicked: {
                    // On émet le signal pour dire au main.qml de passer à la suite
                    configurationView.simulationLancee()
                }
            }
        }
    }
}