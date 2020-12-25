cmake_minimum_required(VERSION 3.5)

project(Course_Design_of_Data_Structure LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(design
        Sources/main.cpp
        Sources/main_window.cpp
        Headers/main_window.h
        Sources/place_graph.cpp
        Headers/place_graph.h
        Sources/mainwindow.ui
        )

target_link_libraries(design PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
