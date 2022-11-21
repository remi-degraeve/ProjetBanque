# CMakeList.txt : projet CMake pour Projet_Banque, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Class4 "Class_Transactions.cpp" "Class_Transactions.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Class4 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
