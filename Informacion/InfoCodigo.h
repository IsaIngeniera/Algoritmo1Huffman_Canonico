//
// Created by DevCore on 1/10/2025.
//

#ifndef INFOCODIGO_H
#define INFOCODIGO_H

#include <string>

class InfoCodigo {
public:
    char simbolo;
    int longitud;
    std::string codigoArbol;
    std::string codigoCanonico;

    InfoCodigo();
    InfoCodigo(char sim, int long_cod, std::string cod_arbol);
};

#endif