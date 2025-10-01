cmake_minimum_required(VERSION 3.30)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)

# Lista de todos los archivos .cpp
add_executable(untitled3
        src/main.cpp
        src/ArbolHuffman.cpp
        src/CompresorHuffman.cpp
        src/HuffmanCanonico.cpp
        extra/InfoCodigo.cpp
        src/NodoComparador.cpp
        src/NodoHuffman.cpp
)
