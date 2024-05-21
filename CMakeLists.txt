cmake_minimum_required(VERSION 3.28)
project(idj_engine)

include_directories(
        include
        src
)

set(CMAKE_CXX_STANDARD 26)

add_library(idj_engine STATIC library.cpp
        include/arith/Vec2.h
        src/arith/Vec2.cpp
        src/arith/Vec3.cpp
        include/arith/Vec3.h
        src/InputManager.cpp
        include/InputManager.h
        src/arith/Rect.cpp
        include/arith/Rect.h
        src/arith/Vec2Int.cpp
        include/arith/Vec2Int.h
        src/arith/Vec3Int.cpp
        include/arith/Vec3Int.h
        src/State.cpp
        include/State.h
        src/GameObject.cpp
        include/GameObject.h
        src/components/Component.cpp
        include/components/Component.h
        src/exceptions/ComponentNotFoundException.cpp
        include/exceptions/ComponentNotFoundException.h
        src/physics/Collision.cpp
        src/components/BoxCollider.cpp
        include/components/BoxCollider.h
        include/Defines.h
        src/components/Camera.cpp
        include/components/Camera.h
        src/Game.cpp
        include/Game.h
        src/time/Time.cpp
        include/time/Time.h
        src/settings/Settings.cpp
        include/settings/Settings.h
        src/exceptions/GameNotStartedException.cpp
        include/exceptions/GameNotStartedException.h
        src/Resources.cpp
        include/Resources.h
        src/arith/Circle.cpp
        include/arith/Circle.h
        src/components/Collider.cpp
        include/components/Collider.h
        src/components/CircleCollider.cpp
        include/components/CircleCollider.h
        include/physics/precision.h
)
