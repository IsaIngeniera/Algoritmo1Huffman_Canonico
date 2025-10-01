cmake_minimum_required(VERSION 3.30)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)

# Lista de todos los archivos .cpp
add_executable(untitled3
        main.cpp
        ArbolHuffman.cpp
        CompresorHuffman.cpp
        HuffmanCanonico.cpp
        InfoCodigo.cpp
        NodoComparador.cpp
        NodoHuffman.cpp
)
