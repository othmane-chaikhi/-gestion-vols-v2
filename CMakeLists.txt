cmake_minimum_required(VERSION 3.27)
project(GestionVols_tp)

set(CMAKE_CXX_STANDARD 17)

add_executable(GestionVols_tp main.cpp
        Vols.cpp
        Vols.h
        Passager.cpp
        Passager.h
        vol.cpp
        vol.h
        avion.cpp
        avion.h
        Date.cpp)
