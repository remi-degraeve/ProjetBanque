# CMakeList.txt : projet CMake pour First_world_bank, incluez la source et définissez
# la logique spécifique au projet ici.
#
#cmake_minimum_required (VERSION 3.8)

# Ajoutez une source à l'exécutable de ce projet.
#add_executable (Class2 "Class_Client.cpp" "Class_Client.h" "Customer_for_JSON.cpp")

#if (CMAKE_VERSION VERSION_GREATER 3.12)
 # set_property(TARGET Class2 PROPERTY CXX_STANDARD 20)
#endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.


cmake_minimum_required (VERSION 3.9)

project(Class)

set (CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    set(Boost_USE_STATIC_RUNTIME ON)
    add_compile_options($<$<CONFIG:Release>:/MT> # Runtime library: Multi-threaded
                      $<$<CONFIG:Debug>:/MTd> # Runtime library: Multi-threaded Debug
                      )
    set(Boost_DIR "C:/tools/Boost/lib/cmake/Boost-1.80.0")
elseif(MSVC)
    set(Boost_DIR /usr/local/lib/cmake/Boost-1.80.0)
endif (MSVC)

find_package(Boost 1.80.0 COMPONENTS serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(SRCS "Class_Client.cpp" "Customer_for_JSON.cpp")

add_library (customer ${SRCS})
target_include_directories (customer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})