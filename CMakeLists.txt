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
        src/State.cpp
        src/State.h
        src/GameObject.cpp
        src/GameObject.h
        src/components/Component.cpp
        src/components/Component.h
        src/exceptions/ComponentNotFoundException.cpp
        src/exceptions/ComponentNotFoundException.h
        src/components/Collision.cpp
        src/components/Collider.cpp
        src/components/Collider.h
        src/Defines.cpp
        src/components/Camera.cpp
        src/components/Camera.h
        src/Game.cpp
        src/Game.h
        src/Time/Time.cpp
        src/Time/Time.h
        src/settings/Settings.cpp
        src/settings/Settings.h
        src/exceptions/GameNotStartedException.cpp
        src/exceptions/GameNotStartedException.h
        src/Resources.cpp
        src/Resources.h
)
