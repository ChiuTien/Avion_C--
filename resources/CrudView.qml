import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: crudView
    
    // Fond blanc
    Rectangle {
        anchors.fill: parent
        color: "white"
        
        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 15
            
            // Titre simplifié
            Text {
                text: "Administration"
                Layout.alignment: Qt.AlignHCenter
                color: "#333"
                font.pixelSize: 24
                font.bold: true
            }
            
            // Barre d'onglets
            TabBar {
                id: bar
                Layout.fillWidth: true
                background: Rectangle { color: "#f0f0f0" }
                
                TabButton {
                    text: "Avions"
                    font.pixelSize: 14
                    contentItem: Text {
                        text: parent.text
                        color: parent.checked ? "#2196F3" : "#666"
                        font.pixelSize: parent.font.pixelSize
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                TabButton {
                    text: "Pistes"
                    font.pixelSize: 14
                    contentItem: Text {
                        text: parent.text
                        color: parent.checked ? "#2196F3" : "#666"
                        font.pixelSize: parent.font.pixelSize
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
            
            // Contenu des onglets
            StackLayout {
                id: layoutPrincipal
                currentIndex: bar.currentIndex
                Layout.fillWidth: true
                Layout.fillHeight: true
                
                // ========== ONGLET AVIONS ==========
                ScrollView {
                    id: avionScroll
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    clip: true
                    
                    ColumnLayout {
                        width: parent.width - 20
                        spacing: 15
                        
                        // Liste des avions
                        ColumnLayout {
                            Layout.fillWidth: true
                            spacing: 5
                            
                            Text {
                                text: "Avions existants"
                                font.bold: true
                                color: "#555"
                            }
                            
                            Rectangle {
                                Layout.fillWidth: true
                                Layout.preferredHeight: 120
                                color: "#f5f5f5"
                                border.color: "#ddd"
                                radius: 4
                                
                                ListView {
                                    anchors.fill: parent
                                    anchors.margins: 5
                                    model: monCrudController.listeAvions
                                    clip: true
                                    delegate: ItemDelegate {
                                        text: modelData
                                        width: parent.width
                                    }
                                }
                            }
                        }
                        
                        // Formulaire avion complet
                        ColumnLayout {
                            Layout.fillWidth: true
                            spacing: 10
                            
                            Text {
                                text: "Nouvel avion"
                                font.bold: true
                                color: "#555"
                            }
                            
                            // IDENTIFICATION & POSITION
                            GroupBox {
                                title: "📍 Identification & Position"
                                Layout.fillWidth: true
                                
                                GridLayout {
                                    columns: 2
                                    rowSpacing: 8
                                    columnSpacing: 10
                                    anchors.fill: parent
                                    
                                    Label { text: "ID Avion:"; color: "#333" }
                                    TextField { id: av_id; placeholderText: "ex: 1"; Layout.fillWidth: true }
                                    
                                    Label { text: "Distance Piste:"; color: "#333" }
                                    TextField { id: av_dist; placeholderText: "en m"; Layout.fillWidth: true }
                                    
                                    Label { text: "Position X:"; color: "#333" }
                                    TextField { id: av_x; placeholderText: "X initial (m)"; Layout.fillWidth: true }
                                    
                                    Label { text: "Altitude Y:"; color: "#333" }
                                    TextField { id: av_y; placeholderText: "Y initial (m)"; Layout.fillWidth: true }
                                }
                            }
                            
                            // CINÉMATIQUE
                            GroupBox {
                                title: "⚡ Vitesses & Accélérations"
                                Layout.fillWidth: true
                                
                                GridLayout {
                                    columns: 2
                                    rowSpacing: 8
                                    columnSpacing: 10
                                    anchors.fill: parent
                                    
                                    Label { text: "Vitesse X:"; color: "#333" }
                                    TextField { id: av_vx; placeholderText: "vx (m/s)"; Layout.fillWidth: true }
                                    
                                    Label { text: "Vitesse Y:"; color: "#333" }
                                    TextField { id: av_vy; placeholderText: "vy (m/s)"; Layout.fillWidth: true }
                                    
                                    Label { text: "Accélération X:"; color: "#333" }
                                    TextField { id: av_ax; placeholderText: "ax (m/s²)"; Layout.fillWidth: true }
                                    
                                    Label { text: "Accélération Y:"; color: "#333" }
                                    TextField { id: av_ay; placeholderText: "ay (m/s²)"; Layout.fillWidth: true }
                                    
                                    Label { text: "Vitesse décrochage:"; color: "#333" }
                                    TextField { id: av_vd; placeholderText: "vd (m/s)"; Layout.fillWidth: true }
                                }
                            }
                            
                            // FREINAGE
                            GroupBox {
                                title: "🛑 Système de freinage"
                                Layout.fillWidth: true
                                
                                GridLayout {
                                    columns: 2
                                    rowSpacing: 8
                                    columnSpacing: 10
                                    anchors.fill: parent
                                    
                                    Label { text: "Freinage max X:"; color: "#333" }
                                    TextField { id: av_fmaxx; placeholderText: "fmax_x"; Layout.fillWidth: true }
                                    
                                    Label { text: "Freinage max Y:"; color: "#333" }
                                    TextField { id: av_fmaxy; placeholderText: "fmax_y"; Layout.fillWidth: true }
                                    
                                    Label { text: "Pas frein X:"; color: "#333" }
                                    TextField { id: av_pasx; placeholderText: "pas_x"; Layout.fillWidth: true }
                                    
                                    Label { text: "Pas frein Y:"; color: "#333" }
                                    TextField { id: av_pasy; placeholderText: "pas_y"; Layout.fillWidth: true }
                                }
                            }
                            
                            // Bouton créer
                            Button {
                                text: "Créer l'avion"
                                Layout.fillWidth: true
                                Layout.preferredHeight: 40
                                
                                background: Rectangle {
                                    color: parent.pressed ? "#1976D2" : "#2196F3"
                                    radius: 4
                                }
                                
                                contentItem: Text {
                                    text: parent.text
                                    color: "white"
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }
                                
                                onClicked: {
                                    monCrudController.creerAvion(
                                        parseInt(av_id.text) || 0,
                                        parseFloat(av_x.text) || 0,
                                        parseFloat(av_y.text) || 0,
                                        parseFloat(av_ax.text) || 0,
                                        parseFloat(av_ay.text) || 0,
                                        parseFloat(av_vx.text) || 0,
                                        parseFloat(av_vy.text) || 0,
                                        parseFloat(av_vd.text) || 0,
                                        parseFloat(av_fmaxx.text) || 0,
                                        parseFloat(av_fmaxy.text) || 0,
                                        parseFloat(av_pasx.text) || 0,
                                        parseFloat(av_pasy.text) || 0,
                                        parseFloat(av_dist.text) || 0
                                    )
                                }
                            }
                        }
                    }
                }
                
                // ========== ONGLET PISTES ==========
                ColumnLayout {
                    spacing: 15
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    
                    // Liste des pistes
                    ColumnLayout {
                        Layout.fillWidth: true
                        spacing: 5
                        
                        Text {
                            text: "Pistes existantes"
                            font.bold: true
                            color: "#555"
                        }
                        
                        Rectangle {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 150
                            color: "#f5f5f5"
                            border.color: "#ddd"
                            radius: 4
                            
                            ListView {
                                anchors.fill: parent
                                anchors.margins: 5
                                model: monCrudController.listePistes
                                clip: true
                                delegate: ItemDelegate {
                                    text: modelData
                                    width: parent.width
                                }
                            }
                        }
                    }
                    
                    // Formulaire piste
                    ColumnLayout {
                        Layout.fillWidth: true
                        spacing: 10
                        
                        Text {
                            text: "Nouvelle piste"
                            font.bold: true
                            color: "#555"
                        }
                        
                        GroupBox {
                            title: "🛣️ Caractéristiques de la piste"
                            Layout.fillWidth: true
                            
                            GridLayout {
                                columns: 2
                                rowSpacing: 8
                                columnSpacing: 10
                                anchors.fill: parent
                                
                                Label { text: "ID Piste:"; color: "#333" }
                                TextField { id: pi_id; placeholderText: "101"; Layout.fillWidth: true }
                                
                                Label { text: "Longueur (m):"; color: "#333" }
                                TextField { id: pi_long; placeholderText: "3000"; Layout.fillWidth: true }
                                
                                Label { text: "Début X:"; color: "#333" }
                                TextField { id: pi_debut; placeholderText: "0"; Layout.fillWidth: true }
                                
                                Label { text: "Fin X:"; color: "#333" }
                                TextField { id: pi_fin; placeholderText: "3000"; Layout.fillWidth: true }
                            }
                        }
                        
                        Button {
                            text: "Créer la piste"
                            Layout.fillWidth: true
                            Layout.preferredHeight: 40
                            
                            background: Rectangle {
                                color: parent.pressed ? "#1976D2" : "#2196F3"
                                radius: 4
                            }
                            
                            contentItem: Text {
                                text: parent.text
                                color: "white"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                            
                            onClicked: {
                                monCrudController.creerPiste(
                                    parseInt(pi_id.text) || 0,
                                    parseFloat(pi_long.text) || 0,
                                    parseFloat(pi_debut.text) || 0,
                                    parseFloat(pi_fin.text) || 0
                                )
                            }
                        }
                    }
                    
                    Item { Layout.fillHeight: true }
                }
            }
            
            // Bouton retour
            Button {
                text: "← Retour"
                Layout.alignment: Qt.AlignLeft
                background: Rectangle {
                    color: parent.pressed ? "#ddd" : "#f0f0f0"
                    radius: 4
                }
                onClicked: stackNavigation.pop()
            }
        }
    }
}