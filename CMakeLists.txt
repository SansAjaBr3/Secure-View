cmake_minimum_required(VERSION 3.5)

project(SecureView VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
)

set(HEADERS
    headers/mainwindow.h
)

add_executable(SecureView WIN32
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(SecureView PRIVATE headers)
target_link_libraries(SecureView Qt6::Widgets)
