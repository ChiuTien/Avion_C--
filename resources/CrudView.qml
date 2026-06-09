import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: crudView
    //anchors.fill: parent

    Rectangle {
        anchors.fill: parent
        color: "#2C3E50" // Fond sombre pro

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 15

            Text {
                text: "🛠️ ADMINISTRATION DU SYSTÈME"
                Layout.alignment: Qt.AlignHCenter
                color: "#3498DB"
                font.pointSize: 24
                font.bold: true
            }

            // 📑 Barre d'onglets pour choisir entre Avion et Piste
            TabBar {
                id: bar
                Layout.fillWidth: true
                TabButton { text: "Gestion des Avions" }
                TabButton { text: "Gestion des Pistes" }
            }

            // 🔄 Contenu changeant selon l'onglet
            StackLayout {
                id: layoutPrincipal
                currentIndex: bar.currentIndex
                Layout.fillWidth: true
                Layout.fillHeight: true

                // ==========================================
                // ✈️ ONGLET AVION (CONTENEUR PRINCIPAL DE L'ONGLET)
                // ==========================================
                ColumnLayout {
                    spacing: 10
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    // Liste des avions existants
                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 120
                        color: "#34495E"
                        radius: 5
                        ListView {
                            anchors.fill: parent
                            model: monCrudController.listeAvions
                            clip: true
                            delegate: ItemDelegate {
                                text: modelData
                                width: parent.width
                                palette.text: "white"
                            }
                        }
                    }

                    // Formulaire d'insertion exhaustif avec ScrollView
                    ScrollView {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        clip: true

                        ColumnLayout {
                            width: parent.width - 20
                            spacing: 15

                            // --- SECTION 1 : IDENTIFICATION & POSITION ---
                            GroupBox {
                                title: "📍 Identification & Position Initiale"
                                Layout.fillWidth: true
                                palette.windowText: "#3498DB"
                                GridLayout {
                                    columns: 4
                                    rowSpacing: 8; columnSpacing: 15
                                    anchors.fill: parent

                                    Label { text: "ID Avion:"; color: "white" }
                                    TextField { id: av_id; placeholderText: "ex: 1"; Layout.fillWidth: true }

                                    Label { text: "Distance Piste:"; color: "white" }
                                    TextField { id: av_dist; placeholderText: "en m"; Layout.fillWidth: true }

                                    Label { text: "Position X:"; color: "white" }
                                    TextField { id: av_x; placeholderText: "X initial (m)"; Layout.fillWidth: true }

                                    Label { text: "Altitude Y:"; color: "white" }
                                    TextField { id: av_y; placeholderText: "Y initial (m)"; Layout.fillWidth: true }
                                }
                            }

                            // --- SECTION 2 : CINÉMATIQUE (VITESSES & ACCÉLÉRATIONS) ---
                            GroupBox {
                                title: "⚡ Vitesses & Accélérations Initiales"
                                Layout.fillWidth: true
                                palette.windowText: "#2ECC71"
                                GridLayout {
                                    columns: 4
                                    rowSpacing: 8; columnSpacing: 15
                                    anchors.fill: parent

                                    Label { text: "Vitesse X:"; color: "white" }
                                    TextField { id: av_vx; placeholderText: "vx (m/s)"; Layout.fillWidth: true }

                                    Label { text: "Vitesse Y:"; color: "white" }
                                    TextField { id: av_vy; placeholderText: "vy (m/s)"; Layout.fillWidth: true }

                                    Label { text: "Accél. X:"; color: "white" }
                                    TextField { id: av_ax; placeholderText: "ax (m/s²)"; Layout.fillWidth: true }

                                    Label { text: "Accél. Y:"; color: "white" }
                                    TextField { id: av_ay; placeholderText: "ay (m/s²)"; Layout.fillWidth: true }

                                    Label { text: "V. Décrochage:"; color: "white" }
                                    TextField { id: av_vd; placeholderText: "vd (m/s)"; Layout.columnSpan: 3; Layout.fillWidth: true }
                                }
                            }

                            // --- SECTION 3 : PARAMÈTRES DE FREINAGE ---
                            GroupBox {
                                title: "🛑 Système de Freinage"
                                Layout.fillWidth: true
                                palette.windowText: "#E74C3C"
                                GridLayout {
                                    columns: 4
                                    rowSpacing: 8; columnSpacing: 15
                                    anchors.fill: parent

                                    Label { text: "Freinage Max X:"; color: "white" }
                                    TextField { id: av_fmaxx; placeholderText: "fmax_x"; Layout.fillWidth: true }

                                    Label { text: "Freinage Max Y:"; color: "white" }
                                    TextField { id: av_fmaxy; placeholderText: "fmax_y"; Layout.fillWidth: true }

                                    Label { text: "Pas Frein X:"; color: "white" }
                                    TextField { id: av_pasx; placeholderText: "pas_x"; Layout.fillWidth: true }

                                    Label { text: "Pas Frein Y:"; color: "white" }
                                    TextField { id: av_pasy; placeholderText: "pas_y"; Layout.fillWidth: true }
                                }
                            }

                            // --- BOUTON DE SOUMISSION ---
                            Button {
                                text: "Enregistrer l'Appareil Complet ✈️"
                                Layout.fillWidth: true
                                Layout.preferredHeight: 45
                                
                                background: Rectangle {
                                    color: parent.down ? "#1F618D" : "#2980B9"
                                    radius: 4
                                }
                                palette.buttonText: "white"

                                onClicked: {
                                    // Sécurisation anti-NaN si les champs sont vides
                                    monCrudController.creerAvion(
                                        parseInt(av_id.text) || 0, 
                                        parseFloat(av_x.text) || 0.0, 
                                        parseFloat(av_y.text) || 0.0,
                                        parseFloat(av_ax.text) || 0.0, 
                                        parseFloat(av_ay.text) || 0.0,
                                        parseFloat(av_vx.text) || 0.0, 
                                        parseFloat(av_vy.text) || 0.0, 
                                        parseFloat(av_vd.text) || 0.0,
                                        parseFloat(av_fmaxx.text) || 0.0, 
                                        parseFloat(av_fmaxy.text) || 0.0,
                                        parseFloat(av_pasx.text) || 0.0, 
                                        parseFloat(av_pasy.text) || 0.0,
                                        parseFloat(av_dist.text) || 0.0
                                    )
                                }
                            }
                        }
                    }
                }

                // ==========================================
                // 🛣️ ONGLET PISTE
                // ==========================================
                ColumnLayout {
                    spacing: 10
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    // Liste des pistes
                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 150
                        color: "#34495E"
                        radius: 5
                        ListView {
                            anchors.fill: parent
                            model: monCrudController.listePistes
                            clip: true
                            delegate: ItemDelegate {
                                text: modelData
                                width: parent.width
                                palette.text: "white"
                            }
                        }
                    }

                    // Formulaire Piste
                    GroupBox {
                        title: "Ajouter une nouvelle piste"
                        Layout.fillWidth: true
                        palette.windowText: "white"

                        GridLayout {
                            columns: 2
                            rowSpacing: 10
                            anchors.fill: parent

                            Label { text: "ID de la Piste:"; color: "white" }
                            TextField { id: pi_id; placeholderText: "ex: 101"; Layout.fillWidth: true }

                            Label { text: "Longueur totale (m):"; color: "white" }
                            TextField { id: pi_long; placeholderText: "ex: 3000"; Layout.fillWidth: true }

                            Label { text: "Point de début (X):"; color: "white" }
                            TextField { id: pi_debut; placeholderText: "0"; Layout.fillWidth: true }

                            Label { text: "Point de fin (X):"; color: "white" }
                            TextField { id: pi_fin; placeholderText: "3000"; Layout.fillWidth: true }

                            Button {
                                text: "Enregistrer la Piste 🛣️"
                                Layout.columnSpan: 2
                                Layout.fillWidth: true
                                onClicked: {
                                    // Sécurisation anti-NaN si les champs sont vides
                                    monCrudController.creerPiste(
                                        parseInt(pi_id.text) || 0, 
                                        parseFloat(pi_long.text) || 0.0,
                                        parseFloat(pi_debut.text) || 0.0, 
                                        parseFloat(pi_fin.text) || 0.0
                                    )
                                }
                            }
                        }
                    }
                    
                    // Espaceur pour pousser le contenu vers le haut dans l'onglet piste
                    Item { Layout.fillHeight: true }
                }
            }

            // Bouton retour
            Button {
                text: "⬅ Retour au Menu"
                Layout.alignment: Qt.AlignLeft
                onClicked: stackNavigation.pop()
            }
        }
    }
}