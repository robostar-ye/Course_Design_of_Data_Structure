cmake_minimum_required(VERSION 3.5)

project(Course_Design_of_Data_Structure LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXE_LINKER_FLAGS -static)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Lib)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

file(GLOB_RECURSE QRC_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)
set(QRC_SOURCE_FILES Resources/image.qrc)
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})
add_library(${PROJECT_NAME}
${QRC_FILES})

add_executable(design
        ${QRC_FILES}
        Sources/main.cpp
        Sources/main_window.cpp
        Headers/main_window.h
        Sources/place_graph.cpp
        Headers/place_graph.h
        Sources/mainwindow.ui
        )

target_link_libraries(design PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
