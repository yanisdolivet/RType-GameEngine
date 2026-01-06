cmake_minimum_required(VERSION 3.28.3)

project(GameEngine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# Find Conan packages
find_package(raylib REQUIRED)
find_package(GTest REQUIRED)
find_package(spdlog REQUIRED)

# Define the Library Target --> Move to SHARE later
add_library(GameEngine STATIC
    main.cpp
    src/Core.cpp

    src/components/AnimationComponent.cpp
    src/components/Clickable.cpp
    src/components/Collider.cpp
    src/components/Controllable.cpp
    src/components/DrawableComponent.cpp
    src/components/DynamicScale.cpp
    src/components/EntityType.cpp
    src/components/Mouvement.cpp
    src/components/Parallax.cpp
    src/components/Position.cpp
    src/components/Speed.cpp
    src/components/SpriteComponent.cpp
    src/components/Velocity.cpp

    src/ecs/Entity.cpp
    src/ecs/Registry.cpp

    src/event_subscriptions/EngineSubscriptions.cpp

    src/graphic/Raylib.cpp

    src/init/InitActionInput.cpp

    src/logs/Logs.cpp

    src/systems/CollisionSystem.cpp
    src/systems/InputReleasedSystem.cpp
    src/systems/InputSystem.cpp
    src/systems/MovementSystem.cpp
    src/systems/PhysicsSystem.cpp
    src/systems/animation_system/AnimationSystem.cpp
    src/systems/render_system/RenderSystem.cpp
    src/systems/render_system/ResourceManager.cpp

)

# Define Include Directories
target_include_directories(GameEngine
    # Any project linking this engine can see headers in 'include/'
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/components>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/ecs>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/events>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/event_subscriptions>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/graphic>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/init>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/logs>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/systems>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/systems/animation_system>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/systems/render_system>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/ecs/tppFiles>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/utils>
        $<INSTALL_INTERFACE:include>

    # Only the engine itself can see headers in 'src/'
    PRIVATE
        src
)

# Link Dependencies
target_link_libraries(GameEngine
    PUBLIC
        raylib
        spdlog::spdlog
    PRIVATE
        GTest::gtest
)

# Compiler Warnings
if(MSVC)
    target_compile_options(GameEngine PRIVATE /W4 /WX)
else()
    target_compile_options(GameEngine PRIVATE -Wall -Wextra -Werror)
endif()

# Alias (Optional) - Allows you to refer to it as GameEngine::GameEngine
add_library(GameEngine::GameEngine ALIAS GameEngine)

# clang-format target
find_program(FORMAT_BIN clang-format)

if (FORMAT_BIN)
    add_custom_target(format
        COMMAND find src include
                -type f
                -name "*.*pp"
                -exec ${FORMAT_BIN} -i {} +

        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Formatting all source files using find..."
    )
else()
    message(WARNING "clang-format not found!")
endif()