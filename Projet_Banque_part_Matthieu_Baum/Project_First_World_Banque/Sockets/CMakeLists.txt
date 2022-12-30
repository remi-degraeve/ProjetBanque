# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

project ("Project_First_World_Banque")

# Incluez les sous-projets.
add_subdirectory ("Server")
add_subdirectory ("S_Client")
