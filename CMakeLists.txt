cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(final-project)

# This tells the compiler to not aggressively optimize and
# to include debugging information so that the debugger
# can properly read what's going on.
set(CMAKE_BUILD_TYPE Debug)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning flags
if(MSVC)
    # warning level 3 and all warnings as errors
    add_compile_options(/W3 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wpedantic -Werror)
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# FetchContent_MakeAvailable was not added until CMake 3.14
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.11.1
)

# Adds Catch2 testing library
FetchContent_GetProperties(catch2)
if(NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    add_library(catch2 INTERFACE tests/test_main.cpp app/block-app.cpp include/visualizer/grid.h src/visualizer/grid.cpp
            src/visualizer/inventory.cpp include/visualizer/inventory.h include/core/block.h src/core/block.cpp)
    target_include_directories(catch2 INTERFACE ${catch2_SOURCE_DIR}/single_include)
endif()

get_filename_component(CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE)
get_filename_component(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")


list(APPEND SOURCE_FILES    ${CORE_SOURCE_FILES}
        src/visualizer/block_app.cpp
        src/visualizer/grid.cpp
        src/visualizer/inventory.cpp
        src/core/block.cpp)

list(APPEND TEST_FILES)

add_executable(block app/Main.cpp ${CORE_SOURCE_FILES} src/core/block.cpp include/core/block.h)
target_include_directories(block PRIVATE include)

ci_make_app(
        APP_NAME        block-app
        CINDER_PATH     ${CINDER_PATH}
        SOURCES app/block-app.cpp ${SOURCE_FILES}
        INCLUDES        include
)

ci_make_app(
        APP_NAME        test-block
        CINDER_PATH     ${CINDER_PATH}
        SOURCES         tests/test_main.cpp ${SOURCE_FILES} ${TEST_FILES}
        INCLUDES        include
        LIBRARIES       catch2
)

if(MSVC)
    set_property(TARGET naive-bayes-test APPEND_STRING PROPERTY LINK_FLAGS " /SUBSYSTEM:CONSOLE")
endif()
