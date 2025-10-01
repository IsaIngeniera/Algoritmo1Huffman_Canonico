//
// Created by DevCore on 1/10/2025.
//

#include "InfoCodigo.h"

InfoCodigo::InfoCodigo() : simbolo('\0'), longitud(0), codigoArbol(""), codigoCanonico("") {}

InfoCodigo::InfoCodigo(char sim, int long_cod, std::string cod_arbol)
    : simbolo(sim), longitud(long_cod), codigoArbol(cod_arbol), codigoCanonico("") {}
