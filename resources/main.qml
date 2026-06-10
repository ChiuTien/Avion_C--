import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 1020
    height: 720
    title: "Simulateur de Vol"
    
    // Fond blanc
    background: Rectangle {
        color: "white"
    }
    
    // Conteneur principal centré
    Item {
        anchors.fill: parent
        
        // Layout vertical centré
        Column {
            anchors.centerIn: parent
            spacing: 30
            
            // Titre
            Text {
                text: "Simulateur"
                font.pixelSize: 32
                font.bold: true
                color: "#333"
                anchors.horizontalCenter: parent.horizontalCenter
            }
            
            // Bouton Données
            Button {
                text: "Données"
                width: 200
                height: 50
                font.pixelSize: 18
                
                background: Rectangle {
                    color: parent.pressed ? "#ddd" : "#2196F3"
                    radius: 8
                }
                
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font.pixelSize: parent.font.pixelSize
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                
                onClicked: {
                    stackNavigation.push("CrudView.qml")
                }
            }
            
            // Bouton Simulation
            Button {
                text: "Simulation"
                width: 200
                height: 50
                font.pixelSize: 18
                
                background: Rectangle {
                    color: parent.pressed ? "#ddd" : "#4CAF50"
                    radius: 8
                }
                
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font.pixelSize: parent.font.pixelSize
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                
                onClicked: {
                    stackNavigation.push("ConfigurationView.qml")
                }
            }
        }
    }
    
    // Navigation par pile
    StackView {
        id: stackNavigation
        anchors.fill: parent
        initialItem: null  // On commence par le menu personnalisé
        
        // Surcharge pour afficher le menu principal en premier
        Component.onCompleted: {
            // Rien à empiler, on garde l'interface actuelle
        }
    }
    
    // Gestionnaire pour capturer les signaux des pages
    Connections {
        target: stackNavigation.currentItem
        ignoreUnknownSignals: true
        
        function onSimulationLancee() {
            stackNavigation.push("SimulationView.qml")
        }
    }
}