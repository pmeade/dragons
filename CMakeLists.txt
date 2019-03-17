cmake_minimum_required(VERSION 3.13)
project(Dragons)


set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest main.cpp)
target_link_libraries(BoostTest ${Boost_LIBRARIES})

add_executable(Dragons
        Edge.h
        Edge.cpp
        MinSet.h
        MinSet.cpp
        House.h
        House.cpp
        Prime.h
        Prime.cpp
        Plank.cpp
        Plank.h
        Spell.cpp
        Spell.h
        Dragons.h Dragon.cpp Dragon.h test/TestPlank.cpp test/TestEdge.cpp Plane.cpp Plane.h test/TestHouse.cpp test/TestDragon.cpp Func.cpp Func.h)