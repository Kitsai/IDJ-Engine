cmake_minimum_required(VERSION 3.28)
project(idj_engine)

include_directories(
        include
        src
)

set(CMAKE_CXX_STANDARD 26)

add_library(idj_engine STATIC library.cpp
        src/arith/Vec2.h
        src/arith/Vec2.cpp
        src/arith/Vec3.cpp
        src/arith/Vec3.h
        src/InputManager.cpp
        src/InputManager.h
        src/arith/Rect.cpp
        src/arith/Rect.h
        src/arith/Vec2Int.cpp
        src/arith/Vec2Int.h
        src/arith/Vec3Int.cpp
        src/arith/Vec3Int.h
        src/Game.cpp
        src/Game.h
        src/State.cpp
        src/State.h
        src/GameObject.cpp
        src/GameObject.h
        src/components/Component.cpp
        src/components/Component.h)
