//
// Created by DevCore on 1/10/2025.
//

#include "NodoComparador.h"

bool NodoComparador::operator()(NodoHuffman* a, NodoHuffman* b) const {
    if (a->frecuencia != b->frecuencia) {
        return a->frecuencia > b->frecuencia;
    }
    // Desempate por símbolo (orden ascendente)
    if (a->esHoja() && b->esHoja()) {
        return a->simbolo > b->simbolo;
    }
    return false;
}