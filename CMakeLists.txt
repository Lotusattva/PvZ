cmake_minimum_required(VERSION 3.28)
project(PvZ LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})

# despite other people's advice not to, I *AM* using GLOB_RECURSE here
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(PvZ ${SOURCES})

target_include_directories(PvZ PRIVATE inc)
target_link_libraries(PvZ PRIVATE SFML::Graphics SFML::Audio)
target_compile_features(PvZ PRIVATE cxx_std_23)