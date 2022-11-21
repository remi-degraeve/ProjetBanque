# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

project ("Projet_Banque")

# Incluez les sous-projets.
add_subdirectory ("Class_Comptes")
add_subdirectory ("Class_Client")
add_subdirectory ("Class_Banque")
add_subdirectory ("Class_Transactions")
add_subdirectory ("Fonctions_General")
