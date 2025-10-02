//
// Created by DevCore on 1/10/2025.
//

#ifndef ARBOLHUFFMAN_H
#define ARBOLHUFFMAN_H

#include "NodoHuffman.h"
#include "../Informacion/InfoCodigo.h"
#include <unordered_map>
#include <vector>
#include <string>

class ArbolHuffman {
private:
    NodoHuffman* raiz;
    std::unordered_map<char, int> frecuencias;
    std::unordered_map<char, std::string> codigosArbol;

    void calcularFrecuencias(const std::string& texto);
    void generarCodigos(NodoHuffman* nodo, std::string codigo);
    void imprimirArbolRecursivo(NodoHuffman* nodo, std::string prefijo, bool esIzquierdo, bool esRaiz) const;

public:
    ArbolHuffman();
    ~ArbolHuffman();

    void construirArbol(const std::string& texto);
    std::vector<InfoCodigo> obtenerInformacionCodigos() const;
    const std::unordered_map<char, int>& obtenerFrecuencias() const;
    void imprimirArbol() const;
    NodoHuffman* obtenerRaiz() const;
};

#endif
