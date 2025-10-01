//
// Created by DevCore on 1/10/2025.
//

#include "../include/CompresorHuffman.h"
#include <iostream>
#include <iomanip>
#include <cmath>

void CompresorHuffman::comprimir(const std::string& texto) {
    textoOriginal = texto;

    std::cout<<"\n╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║         INICIANDO COMPRESIÓN HUFFMAN CANÓNICA              ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";

    // Paso 1: Construir árbol
    std::cout << "\n[1] Construyendo árbol de Huffman...\n";
    arbol.construirArbol(texto);

    // Paso 2: Mostrar frecuencias
    std::cout << "\n[2] Tabla de frecuencias:\n";
    std::cout << "┌───────────┬────────────┐\n";
    std::cout << "│  Símbolo  │ Frecuencia │\n";
    std::cout << "├───────────┼────────────┤\n";

    const auto& frecuencias = arbol.obtenerFrecuencias();
    for (const auto& par : frecuencias) {
        std::string simboloStr;
        if (par.first == ' ') simboloStr = "espacio";
        else if (par.first == '\n') simboloStr = "\\n";
        else if (par.first == '\t') simboloStr = "\\t";
        else simboloStr = std::string(1, par.first);

        std::cout << "│ " << std::setw(9) << std::left << simboloStr
                  << " │ " << std::setw(10) << par.second << " │\n";
    }
    std::cout << "└───────────┴────────────┘\n";

    // Paso 3: Mostrar árbol
    arbol.imprimirArbol();

    // Paso 4: Generar códigos canónicos
    std::cout << "\n[3] Generando códigos canónicos...\n";
    std::vector<InfoCodigo> infos = arbol.obtenerInformacionCodigos();
    canonico.generarCodigosCanonico(infos);

    // Paso 5: Mostrar tabla de códigos
    canonico.imprimirTablaCodigos(infos, frecuencias);

    // Paso 6: Codificar texto
    std::cout << "\n[4] Codificando texto...\n";
    codificarTexto();
}

void CompresorHuffman::codificarTexto() {
    textoCodificado = "";
    const auto& codigos = canonico.obtenerCodigosCanonico();

    for (char c : textoOriginal) {
        auto it = codigos.find(c);
        if (it != codigos.end()) {
            textoCodificado += it->second;
        }
    }
}

std::string CompresorHuffman::bitsAHexadecimal(const std::string& bits) const {
    std::string hex = "";
    std::string bitsCopia = bits;

    // Rellenar con ceros si es necesario
    while (bitsCopia.length() % 4 != 0) {
        bitsCopia += "0";
    }

    for (size_t i = 0; i < bitsCopia.length(); i += 4) {
        std::string nibble = bitsCopia.substr(i, 4);
        int valor = 0;
        for (size_t j = 0; j < 4; j++) {
            if (nibble[j] == '1') {
                valor += (1 << (3 - j));
            }
        }

        if (valor < 10) hex += char('0' + valor);
        else hex += char('A' + valor - 10);
    }

    return hex;
}

void CompresorHuffman::mostrarResultados() const {
    std::cout<<"\n╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                  RESULTADO DE COMPRESIÓN                   ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";

    std::cout << "\nTexto original:\n\"" << textoOriginal << "\"\n";

    std::cout << "\nPrimeros bits del texto comprimido:\n";
    std::string primeros128 = textoCodificado.substr(0, std::min(size_t(128), textoCodificado.length()));

    // Mostrar en grupos de 8 bits
    for (size_t i = 0; i < primeros128.length(); i += 8) {
        std::cout << primeros128.substr(i, std::min(size_t(8), primeros128.length() - i)) << " ";
        if ((i + 8) % 64 == 0) std::cout << "\n";
    }
    std::cout << "\n";

    if (textoCodificado.length() > 128) {
        std::cout << "... (" << (textoCodificado.length() - 128) << " bits más)\n";
    }

    std::cout << "\nRepresentación hexadecimal (primeros 32 nibbles):\n";
    std::string hex = bitsAHexadecimal(primeros128);
    for (size_t i = 0; i < hex.length() && i < 32; i += 2) {
        std::cout << hex.substr(i, 2) << " ";
        if ((i + 2) % 16 == 0) std::cout << "\n";
    }
    std::cout << "\n";
}

void CompresorHuffman::mostrarEstadisticas() const {
    int tamanoOriginal = textoOriginal.length() * 8;
    int tamanoComprimido = textoCodificado.length();
    double ratio = static_cast<double>(tamanoComprimido) / tamanoOriginal;
    double reduccion = (1.0 - ratio) * 100.0;

    std::cout<<"\n══════════════════════════════════════════════════════════════\n";
    std::cout << "                  ESTADÍSTICAS DE COMPRESIÓN                  \n";
    std::cout << "══════════════════════════════════════════════════════════════\n";
    std::cout << "  Tamaño original:      " << std::setw(6) << tamanoOriginal << " bits ("
              << textoOriginal.length() << " caracteres)\n";
    std::cout << "  Tamaño comprimido:    " << std::setw(6) << tamanoComprimido << " bits"
              << std::string(24, ' ') << "\n";
    std::cout << "  Ratio de compresión:  " << std::fixed << std::setprecision(4) << ratio
              << std::string(29, ' ') << "\n";
    std::cout << "  Reducción:            " << std::fixed << std::setprecision(2) << reduccion
              << " %" << std::string(27, ' ') << "\n";
    std::cout << "══════════════════════════════════════════════════════════════\n";
}
