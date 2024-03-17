cmake_minimum_required(VERSION 3.1.0)

project(algebraic_god VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

include_directories(
        include
)

set(SOURCE_FILES
        src/book.cpp
        src/cursors.cpp
        src/mybutton.cpp
        src/plusminus.cpp
)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(algebraic_god ${SOURCE_FILES} main.cpp)

target_link_libraries(algebraic_god Qt5::Core)
target_link_libraries(algebraic_god Qt5::Widgets)