//
// Created by DevCore on 1/10/2025.
//

#include "ArbolHuffman.h"
#include "NodoComparador.h"
#include <queue>
#include <iostream>
#include <iomanip>

ArbolHuffman::ArbolHuffman() : raiz(nullptr) {}

ArbolHuffman::~ArbolHuffman() {
    delete raiz;
}

void ArbolHuffman::calcularFrecuencias(const std::string& texto) {
    frecuencias.clear();
    for (char c : texto) {
        frecuencias[c]++;
    }
}

void ArbolHuffman::construirArbol(const std::string& texto) {
    calcularFrecuencias(texto);

    std::priority_queue<NodoHuffman*, std::vector<NodoHuffman*>, NodoComparador> minHeap;

    // Crear nodos hoja
    for (const auto& par : frecuencias) {
        minHeap.push(new NodoHuffman(par.first, par.second));
    }

    // Caso especial: solo un símbolo
    if (minHeap.size() == 1) {
        NodoHuffman* unico = minHeap.top();
        minHeap.pop();
        raiz = new NodoHuffman(unico->frecuencia, unico, nullptr);
        codigosArbol[unico->simbolo] = "0";
        return;
    }

    // Construir árbol
    while (minHeap.size() > 1) {
        NodoHuffman* izq = minHeap.top();
        minHeap.pop();
        NodoHuffman* der = minHeap.top();
        minHeap.pop();

        NodoHuffman* padre = new NodoHuffman(izq->frecuencia + der->frecuencia, izq, der);
        minHeap.push(padre);
    }

    raiz = minHeap.top();

    // Generar códigos del árbol
    codigosArbol.clear();
    generarCodigos(raiz, "");
}

void ArbolHuffman::generarCodigos(NodoHuffman* nodo, std::string codigo) {
    if (nodo == nullptr) return;

    if (nodo->esHoja()) {
        codigosArbol[nodo->simbolo] = codigo.empty() ? "0" : codigo;
        return;
    }

    generarCodigos(nodo->izquierdo, codigo + "0");
    generarCodigos(nodo->derecho, codigo + "1");
}

std::vector<InfoCodigo> ArbolHuffman::obtenerInformacionCodigos() const {
    std::vector<InfoCodigo> infos;
    // Se recorre el mapa de códigos
    for (const auto& par : codigosArbol) {
        char simbolo = par.first;
        std::string codigo = par.second;
        int longitud = codigo.length();

        // Se crea el objeto y se añade
        InfoCodigo info(simbolo, longitud, codigo);
        infos.push_back(info);
    }

    return infos;
}

const std::unordered_map<char, int>& ArbolHuffman::obtenerFrecuencias() const {
    return frecuencias;
}

NodoHuffman* ArbolHuffman::obtenerRaiz() const {
    return raiz;
}

void ArbolHuffman::imprimirArbol() const {
    std::cout << "\n╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║           VISUALIZACIÓN DEL ÁRBOL HUFFMAN                  ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n\n";

    if (raiz == nullptr) {
        std::cout << "  (Árbol vacío)\n";
        return;
    }

    imprimirArbolRecursivo(raiz, "", false, true);
    std::cout << "\n";
}

void ArbolHuffman::imprimirArbolRecursivo(NodoHuffman* nodo, std::string prefijo, bool esIzquierdo, bool esRaiz) const {
    if (nodo == nullptr) return;

    std::cout << prefijo;

    if (esRaiz) {
        std::cout << "◉ ";
        prefijo += "  ";
    } else {
        std::cout << (esIzquierdo ? "├─0─● " : "└─1─● ");
        prefijo += (esIzquierdo ? "│     " : "      ");
    }

    if (nodo->esHoja()) {
        std::string simboloStr;
        if (nodo->simbolo == ' ') simboloStr = "' '";
        else if (nodo->simbolo == '\n') simboloStr = "'\\n'";
        else if (nodo->simbolo == '\t') simboloStr = "'\\t'";
        else simboloStr = std::string("'") + nodo->simbolo + "'";

        std::cout << "[" << simboloStr << " : " << nodo->frecuencia << "]\n";
    } else {
        std::cout << "[" << nodo->frecuencia << "]\n";
        imprimirArbolRecursivo(nodo->izquierdo, prefijo, true, false);
        imprimirArbolRecursivo(nodo->derecho, prefijo, false, false);
    }
}
