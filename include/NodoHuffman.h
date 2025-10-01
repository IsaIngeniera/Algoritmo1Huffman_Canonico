//
// Created by DevCore on 1/10/2025.
//
#ifndef NODOHUFFMAN_H
#define NODOHUFFMAN_H

class NodoHuffman {
public:
    char simbolo;
    int frecuencia;
    NodoHuffman* izquierdo;
    NodoHuffman* derecho;

    NodoHuffman(char sim, int freq);
    NodoHuffman(int freq, NodoHuffman* izq, NodoHuffman* der);
    ~NodoHuffman();

    bool esHoja() const;
};

#endif