cmake_minimum_required(VERSION 3.10)        # versione minima di CMake necessaria per buildare il progetto

project(Snake)                  # da un nome al progetto

set(CMAKE_CXX_STANDARD 17)          # viene imposto di usare C++ 17
set(CMAKE_CXX_STANDARD_REQUIRED True)       # e non degradare in versioni precedenti


include_directories(src)        # gli dice di cercare gli header nella cartella include

find_package(SFML 2.6 COMPONENTS graphics REQUIRED)     # cerca SFML e caricaci tutte le informazioni

add_executable(main src/main.cpp src/Game.cpp src/Food.cpp src/Snake.cpp src/Renderer.cpp)      # qui vanno tutti i .cpp

target_link_libraries(main PRIVATE sfml-graphics)       # quando compila main usa anche SFML

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})           # ogni volta che viene eseguito build chiama in automatico il font in assets