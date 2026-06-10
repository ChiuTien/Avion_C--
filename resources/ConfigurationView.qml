import QtQuick
import QtQuick.Controls

Item {
    id: configurationView
    
    signal simulationLancee()
    
    // Fond blanc
    Rectangle {
        anchors.fill: parent
        color: "white"
        
        // Conteneur principal centré
        Column {
            anchors.centerIn: parent
            spacing: 25
            width: Math.min(parent.width * 0.6, 400)
            
            // Titre
            Text {
                text: "Configuration"
                font.pixelSize: 28
                font.bold: true
                color: "#333"
                anchors.horizontalCenter: parent.horizontalCenter
            }
            
            // Sélection de l'avion
            Column {
                spacing: 8
                width: parent.width
                
                Text {
                    text: "Avion"
                    font.pixelSize: 14
                    font.bold: true
                    color: "#555"
                }
                
                ComboBox {
                    id: comboAvion
                    width: parent.width
                    model: monSimulationController.modelesAvions
                    
                    background: Rectangle {
                        color: "white"
                        border.color: "#ccc"
                        border.width: 1
                        radius: 4
                    }
                }
            }
            
            // Sélection de la piste
            Column {
                spacing: 8
                width: parent.width
                
                Text {
                    text: "Piste"
                    font.pixelSize: 14
                    font.bold: true
                    color: "#555"
                }
                
                ComboBox {
                    id: comboPiste
                    width: parent.width
                    model: monSimulationController.modelesPistes
                    
                    background: Rectangle {
                        color: "white"
                        border.color: "#ccc"
                        border.width: 1
                        radius: 4
                    }
                }
            }
            
            // Bouton de lancement
            Button {
                text: "Lancer la simulation"
                width: parent.width
                height: 45
                anchors.horizontalCenter: parent.horizontalCenter
                
                background: Rectangle {
                    color: parent.pressed ? "#1976D2" : "#2196F3"
                    radius: 4
                }
                
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                
                onClicked: {
                    let valide = monSimulationController.selectionnerConfiguration(
                        comboAvion.currentIndex,
                        comboPiste.currentIndex
                    )
                    
                    if (valide) {
                        configurationView.simulationLancee()
                    }
                }
            }
        }
    }
}