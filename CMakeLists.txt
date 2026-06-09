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
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

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
    src/services/AvionService.cpp)

# 8. Association du fichier QML à l'exécutable (Méthode Qt6 moderne)
# qt_add_qml_module(${PROJECT_NAME}
#     URI AppAvion
#     VERSION 1.0
#     QML_FILES
#         src/ui/main.qml
# )

# 9. Liaison de ton projet avec les bibliothèques de Qt
target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Qml 
    Qt6::Quick
)