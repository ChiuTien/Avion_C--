import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 900
    height: 600
    title: "Simulateur de Vol - Menu Principal"

    StackView {
        id: stackNavigation
        anchors.fill: parent
        
        // 🏠 L'application démarre maintenant sur l'écran d'accueil !
        initialItem: "AccueilView.qml"
    }

    // 📡 Gestionnaire de connexions pour intercepter les signaux des pages
    Connections {
        target: stackNavigation.currentItem
        ignoreUnknownSignals: true // Évite les erreurs pendant les transitions

        // 1. Si l'utilisateur clique sur "Données"
        function onAllerAuxDonnees() {
            stackNavigation.push("CrudView.qml")
        }

        // 2. Si l'utilisateur clique sur "Simulation"
        function onAllerALaSimulation() {
            // On le redirige vers la page de choix (l'ancienne ConfigurationView)
            stackNavigation.push("ConfigurationView.qml")
        }

        // 3. Quand la page de choix a fini, elle lance la simulation
        function onSimulationLancee() {
            stackNavigation.push("SimulationView.qml")
        }
    }
}