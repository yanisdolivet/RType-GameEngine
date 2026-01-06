cmake_minimum_required(VERSION 3.28.3)

project(GameEngine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# Define the Library Target --> Move to SHARE later
add_library(GameEngine STATIC
    src/Core.cpp
    src/Entity.cpp
)

# Define Include Directories
target_include_directories(GameEngine
    # Any project linking this engine can see headers in 'include/'
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>

    # Only the engine itself can see headers in 'src/'
    PRIVATE
        src
)

# Link Dependencies
target_link_libraries(GameEngine)

# Compiler Warnings
if(MSVC)
    target_compile_options(GameEngine PRIVATE /W4 /WX)
else()
    target_compile_options(GameEngine PRIVATE -Wall -Wextra -Werror)
endif()

# Alias (Optional) - Allows you to refer to it as GameEngine::GameEngine
add_library(GameEngine::GameEngine ALIAS GameEngine)

message(STATUS "Game Engine Library Configured.")