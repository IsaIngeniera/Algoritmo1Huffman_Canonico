//
// Created by DevCore on 1/10/2025.
//

#ifndef NODOCOMPARADOR_H
#define NODOCOMPARADOR_H

#include "NodoHuffman.h"

class NodoComparador {
public:
    bool operator()(NodoHuffman* a, NodoHuffman* b) const;
};

#endif