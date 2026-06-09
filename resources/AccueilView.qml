import QtQuick
import QtQuick.Controls

Item {
    id: accueilView
    anchors.fill: parent

    // 📣 Signaux pour avertir le main.qml du choix de l'utilisateur
    signal allerAuxDonnees()
    signal allerALaSimulation()

    Rectangle {
        anchors.fill: parent
        color: "#1A252F" // Fond sombre et moderne

        Column {
            anchors.centerIn: parent
            spacing: 40
            width: parent.width * 0.6

            Text {
                text: "SIMULATEUR DE VOL"
                color: "#3498DB"
                font.pointSize: 28
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                text: "Veuillez choisir un mode d'accès :"
                color: "#BDC3C7"
                font.pointSize: 14
                anchors.horizontalCenter: parent.horizontalCenter
            }

            // Grille pour aligner les deux gros boutons côte à côte
            Row {
                spacing: 20
                anchors.horizontalCenter: parent.horizontalCenter

                // Bouton Gestion des Données
                Button {
                    width: 200
                    height: 80
                    text: "📊 Gestion des Données\n(CRUD)"
                    
                    onClicked: accueilView.allerAuxDonnees()
                }

                // Bouton Lancer la Simulation
                Button {
                    width: 200
                    height: 80
                    text: "🚀 Mode Simulation\n(Piloter)"
                    
                    onClicked: accueilView.allerALaSimulation()
                }
            }
        }
    }
}