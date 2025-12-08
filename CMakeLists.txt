cmake_minimum_required(VERSION 3.16)
project(TicTacToe VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(TicTacToe
    src/main.cpp
    src/tic_tac_toe.cpp
    src/tic_tac_toe.h
    widget/tic_tac_toe_widget.cpp
    widget/tic_tac_toe_widget.h
)

target_link_libraries(TicTacToe Qt6::Core Qt6::Widgets)

target_include_directories(TicTacToe PRIVATE widget)

add_subdirectory(tests)
