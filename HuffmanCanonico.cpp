//
// Created by DevCore on 1/10/2025.
//
#include "HuffmanCanonico.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

bool HuffmanCanonico::compararInfoCodigo(const InfoCodigo& a, const InfoCodigo& b) {
    if (a.longitud != b.longitud) {
        return a.longitud < b.longitud;
    }
    return a.simbolo < b.simbolo;
}

std::string HuffmanCanonico::intABinario(int valor, int longitud) const {
    std::string temporal = "";
    int valorCopia = valor;

    // si el valor es 0
    if (valorCopia == 0) {
        temporal = "0";
    } else {
        //convertir el número a binario (sale al revés)
        while (valorCopia > 0) {
            if (valorCopia % 2 == 1) {
                temporal += '1';
            } else {
                temporal += '0';
            }
            valorCopia /= 2;
        }
    }

    //  Revertimos y rellenamos con ceros para asegurar la longitud
    std::string resultado = "";

    // Rellenar con ceros a la izquierda, si es necesario
    int cerosFaltantes = longitud - temporal.length();

    // Un bucle for simple para rellenar
    for (int i = 0; i < cerosFaltantes; i++) {
        resultado += '0';
    }

    // Revertir la cadena temporal 
    for (int i = temporal.length() - 1; i >= 0; i--) {
        resultado += temporal[i];
    }

    // Manejo de error
    if (resultado.length() > longitud) {
        resultado = resultado.substr(resultado.length() - longitud);
    }

    return resultado;
}

void HuffmanCanonico::generarCodigosCanonico(std::vector<InfoCodigo>& infos) {
    codigosCanonico.clear();

    if (infos.empty()) return;

    // Ordenar por longitud y luego por símbolo
    std::sort(infos.begin(), infos.end(), compararInfoCodigo);

    int codigo = 0;
    int longitudAnterior = infos[0].longitud;

    for (auto& info : infos) {
        if (info.longitud > longitudAnterior) {
            codigo <<= (info.longitud - longitudAnterior);
            longitudAnterior = info.longitud;
        }

        info.codigoCanonico = intABinario(codigo, info.longitud);
        codigosCanonico[info.simbolo] = info.codigoCanonico;
        codigo++;
    }
}

const std::unordered_map<char, std::string>& HuffmanCanonico::obtenerCodigosCanonico() const {
    return codigosCanonico;
}

void HuffmanCanonico::imprimirTablaCodigos(const std::vector<InfoCodigo>& infos,
                                           const std::unordered_map<char, int>& frecuencias) const {
    std::cout << "\n╔════════════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    TABLA DE CÓDIGOS HUFFMAN                            ║\n";
    std::cout << "╠═══════════╦══════════╦══════════╦═════════════════╦══════════════════╣\n";
    std::cout << "║  Símbolo  ║   Freq   ║ Longitud ║  Código Árbol   ║ Código Canónico  ║\n";
    std::cout << "╠═══════════╬══════════╬══════════╬═════════════════╬══════════════════╣\n";

    for (const auto& info : infos) {
        std::string simboloStr;
        if (info.simbolo == ' ') simboloStr = "espacio";
        else if (info.simbolo == '\n') simboloStr = "\\n";
        else if (info.simbolo == '\t') simboloStr = "\\t";
        else simboloStr = std::string(1, info.simbolo);

        auto it = frecuencias.find(info.simbolo);
        int freq = (it != frecuencias.end()) ? it->second : 0;

        std::cout << "║ " << std::setw(9) << std::left << simboloStr
                  << " ║ " << std::setw(8) << freq
                  << " ║ " << std::setw(8) << info.longitud
                  << " ║ " << std::setw(15) << info.codigoArbol
                  << " ║ " << std::setw(16) << info.codigoCanonico << " ║\n";
    }

    std::cout << "╚═══════════╩══════════╩══════════╩═════════════════╩══════════════════╝\n";
}
