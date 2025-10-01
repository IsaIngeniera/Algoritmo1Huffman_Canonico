//
// Created by DevCore on 1/10/2025.
//
#ifndef COMPRESORHUFFMAN_H
#define COMPRESORHUFFMAN_H

#include "ArbolHuffman.h"
#include "HuffmanCanonico.h"
#include <string>

class CompresorHuffman {
private:
    ArbolHuffman arbol;
    HuffmanCanonico canonico;
    std::string textoOriginal;
    std::string textoCodificado;

public:
    void comprimir(const std::string& texto);
    void mostrarResultados() const;
    void mostrarEstadisticas() const;

private:
    void codificarTexto();
    std::string bitsAHexadecimal(const std::string& bits) const;
};

#endif