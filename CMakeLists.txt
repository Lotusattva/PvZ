cmake_minimum_required(VERSION 3.28)
project(PvZ LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB SOURCE_FILES src/*.cpp)

add_executable(PvZ ${SOURCE_FILES})

file(COPY res DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

target_link_libraries(PvZ PRIVATE sfml-graphics sfml-audio)
target_compile_features(PvZ PRIVATE cxx_std_23)

if(WIN32)
    add_custom_command(
        TARGET PvZ
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:PvZ>
        VERBATIM)
endif()

# enable_testing()

# add_executable(tests test/test.cpp)
# target_link_libraries(tests PRIVATE sfml-graphics sfml-audio)
# target_compile_features(tests PRIVATE cxx_std_23)
# add_test(NAME tests COMMAND $<TARGET_FILE:tests>)