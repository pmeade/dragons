cmake_minimum_required(VERSION 3.13)
project(Dragons)


set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest src/main.cpp)
target_link_libraries(BoostTest ${Boost_LIBRARIES})

add_executable(Dragons
        src/Edge.h
        src/Edge.cpp
        src/MinSet.h
        src/MinSet.cpp
        src/House.h
        src/House.cpp
        src/Prime.h
        src/Prime.cpp
        src/Plank.cpp
        src/Plank.h
        src/Spell.cpp
        src/Spell.h
        src/Dragons.h src/Dragon.cpp src/Dragon.h test/TestPlank.cpp test/TestEdge.cpp src/Plane.cpp src/Plane.h test/TestHouse.cpp test/TestDragon.cpp src/Func.cpp src/Func.h)