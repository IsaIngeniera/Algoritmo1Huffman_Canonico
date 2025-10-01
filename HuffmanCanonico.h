//
// Created by DevCore on 1/10/2025.
//
#ifndef HUFFMANCANONICO_H
#define HUFFMANCANONICO_H

#include "InfoCodigo.h"
#include <vector>
#include <unordered_map>
#include <string>

class HuffmanCanonico {
private:
    std::unordered_map<char, std::string> codigosCanonico;

    static bool compararInfoCodigo(const InfoCodigo& a, const InfoCodigo& b);
    std::string intABinario(int valor, int longitud) const;

public:
    void generarCodigosCanonico(std::vector<InfoCodigo>& infos);
    const std::unordered_map<char, std::string>& obtenerCodigosCanonico() const;
    void imprimirTablaCodigos(const std::vector<InfoCodigo>& infos,
                              const std::unordered_map<char, int>& frecuencias) const;
};

#endif