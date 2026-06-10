cmake_minimum_required(VERSION 3.16)
project(Avion VERSION 1.0 LANGUAGES CXX)

# 1. Configuration de C++ (Version moderne)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Activation de la compilation automatique pour Qt
set(CMAKE_AUTOMOC ON) # Gère les signaux et slots de Qt
set(CMAKE_AUTOUIC ON) # Gère les fichiers d'interface .ui
set(CMAKE_AUTORCC ON) # Gère les fichiers de ressources

# 3. Recherche des modules de Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Widgets)

# 4. Inclusion du dossier 'include'
include_directories(include)

# 5. Configuration du dossier de sortie pour l'exécutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 6. Collecte de tous les fichiers sources (.cpp)
file(GLOB_RECURSE SOURCES "src/*.cpp")


# 7. Création de l'exécutable final
add_executable(${PROJECT_NAME} ${SOURCES}
    include/models/Piste.hpp
    src/models/Piste.cpp
    include/services/AvionService.hpp
    src/services/AvionService.cpp
    include/views/ChronometreWidget.hpp
    src/views/ChronometreWidget.cpp
    src/repositories/PisteDAO.cpp
    include/controllers/CrudController.hpp
    src/controllers/CrudController.cpp
    include/controllers/SimulationController.hpp
    src/controllers/SimulationController.cpp)

# 8. Association du fichier QML à l'exécutable (Méthode Qt6 moderne)
qt_add_resources(Avion "fichiers_qml"
    PREFIX "/"
    FILES
        resources/main.qml
        resources/ConfigurationView.qml  
        resources/SimulationView.qml
        resources/AccueilView.qml    
        resources/CrudView.qml 
)

# 9. Liaison de ton projet avec les bibliothèques de Qt
target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Qml 
    Qt6::Quick
    Qt6::Widgets
)