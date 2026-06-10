import QtQuick
import QtQuick.Controls

Item {
    id: configurationView

    signal simulationLancee()

    Rectangle {
        anchors.fill: parent
        color: "#2C3E50"

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
                    // 🔗 Charge les vrais avions du CSV
                    model: monSimulationController.modelesAvions 
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
                    // 🔗 Charge les vraies pistes du CSV
                    model: monSimulationController.modelesPistes 
                }
            }

            // --- Bouton de validation ---
            Button {
                text: "Prêt pour le décollage 🚀"
                width: 250
                height: 50
                anchors.horizontalCenter: parent.horizontalCenter
                
                onClicked: {
                    // 🔗 On valide les indices sélectionnés dans le contrôleur C++
                    let valide = monSimulationController.selectionnerConfiguration(comboAvion.currentIndex, comboPiste.currentIndex)
                    
                    if (valide) {
                        // Déclenche le signal intercepté par main.qml
                        configurationView.simulationLancee()
                    }
                }
            }
        }
    }
}