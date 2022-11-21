# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

project ("Class")

# Incluez les sous-projets.
add_subdirectory ("Class_Banque")

# Incluez les sous-projets.
add_subdirectory ("Class_Client")

# Incluez les sous-projets.
add_subdirectory ("Class_Comptes")

# Incluez les sous-projets.
add_subdirectory ("Class_Transaction")

# Incluez les sous-projets.
add_subdirectory ("Fonction_General")
