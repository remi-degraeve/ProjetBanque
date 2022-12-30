cmake_minimum_required(VERSION 3.20)

project(json)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)

if(MSVC)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options($<$<CONFIG:Release>:/MT> # Runtime library: Multi-threaded
                      $<$<CONFIG:Debug>:/MTd> # Runtime library: Multi-threaded Debug
                      )
    set(Boost_USE_STATIC_RUNTIME ON)
	set(Boost_DIR "C:/tools/Boost/lib/cmake/Boost-1.80.0")

elseif(MSVC)
    set(Boost_DIR /usr/local/lib/cmake/Boost-1.80.0)
endif (MSVC)

find_package(Boost 1.80.0 COMPONENTS json serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})



# CMakeList.txt : projet CMake pour Sockets, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Sockets "Server.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sockets PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
