cmake_minimum_required(VERSION 3.13)
project(Dragons)


set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest src/main.cpp)
target_link_libraries(BoostTest ${Boost_LIBRARIES})

add_executable(Dragons
        src/DimensionalDisc.h
        src/DimensionalDisc.cpp
        src/DimensionalHouse.h
        src/DimensionalHouse.cpp
        src/Dragon.h
        src/Dragon.cpp
        src/Dragons.h
        src/Dragons.cpp
        src/Edge.h
        src/Edge.cpp
        src/Func.h
        src/Func.cpp
        src/House.h
        src/House.cpp
        src/MinSet.h
        src/MinSet.cpp
        src/Plane.h
        src/Plane.cpp
        src/SeptumDecum.h
        src/SeptumDecum.cpp
        src/Prime.h
        src/Prime.cpp
        src/Spell.h
        src/Spell.cpp
        src/Schema.h
        src/Schema.cpp
        src/Verse.cpp
        src/Verse.h
        test/TestPlank.cpp
        test/TestEdge.cpp
        test/TestHouse.cpp
        test/TestDragon.cpp src/Snip.cpp src/Snip.h test/TestDimensionalDisc.cpp test/TestMinSet.cpp test/TestSchema.cpp src/Filament.cpp src/Filament.h)
