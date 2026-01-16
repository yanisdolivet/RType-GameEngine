cmake_minimum_required(VERSION 3.28.3)

project(GameEngine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# Export compile_commands.json file into 'build' folder
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find Conan packages
find_package(raylib REQUIRED)
find_package(GTest REQUIRED)
find_package(spdlog REQUIRED)
find_package(imgui REQUIRED)

# Define the Library Target --> Move to SHARE later
add_library(GameEngine STATIC
    src/Core.cpp

    src/components/AnimationComponent.cpp
    src/components/Clickable.cpp
    src/components/Collider.cpp
    src/components/Controllable.cpp
    src/components/DrawableComponent.cpp
    src/components/DynamicScale.cpp
    src/components/EntityType.cpp
    src/components/Movement.cpp
    src/components/Parallax.cpp
    src/components/Position.cpp
    src/components/Speed.cpp
    src/components/SpriteComponent.cpp
    src/components/Velocity.cpp
    src/components/Scale.cpp

    src/ecs/Entity.cpp
    src/ecs/Registry.cpp

    src/event_subscriptions/EngineSubscriptions.cpp

    src/graphic/Raylib.cpp

    src/init/InitActionInput.cpp

    src/systems/CollisionSystem.cpp
    src/systems/InputReleasedSystem.cpp
    src/systems/InputSystem.cpp
    src/systems/MovementSystem.cpp
    src/systems/PhysicsSystem.cpp
    src/systems/animation_system/AnimationSystem.cpp
    src/systems/render_system/RenderSystem.cpp
    src/manager/ResourceManager.cpp
    src/systems/InputPressedSystem.cpp
    src/components/TextComponent.cpp
    src/systems/render_system/AudioSystem.cpp
    src/manager/SceneManager.cpp

    src/external_lib/rlImGui.cpp
)

# Set executable at root of project
set_target_properties(GameEngine PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

# Define Include Directories
target_include_directories(GameEngine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/components>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/ecs>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/events>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/event_subscriptions>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/graphic>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/manager>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/init>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/systems>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/systems/animation_system>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/systems/render_system>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/ecs/tppFiles>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/utils>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngine/external_lib>
        $<INSTALL_INTERFACE:include/GameEngine>

    PRIVATE
        src
)

# Link Dependencies
target_link_libraries(GameEngine
    PUBLIC
        raylib
        spdlog::spdlog
        imgui::imgui
    PRIVATE
        GTest::gtest
)

# Compiler Warnings
if(MSVC)
    target_compile_options(GameEngine PRIVATE /W4)
else()
    target_compile_options(GameEngine PRIVATE -Wall -Wextra)
endif()

# Alias to refer as GameEngine::GameEngine
add_library(GameEngine::GameEngine ALIAS GameEngine)

# clang-format target
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
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
endif()