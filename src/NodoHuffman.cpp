//
// Created by DevCore on 1/10/2025.
//

#include "../include/NodoHuffman.h"

NodoHuffman::NodoHuffman(char sim, int freq)
    : simbolo(sim), frecuencia(freq), izquierdo(nullptr), derecho(nullptr) {}

NodoHuffman::NodoHuffman(int freq, NodoHuffman* izq, NodoHuffman* der)
    : simbolo('\0'), frecuencia(freq), izquierdo(izq), derecho(der) {}

NodoHuffman::~NodoHuffman() {
    delete izquierdo;
    delete derecho;
}

bool NodoHuffman::esHoja() const {
    return izquierdo == nullptr && derecho == nullptr;
}
