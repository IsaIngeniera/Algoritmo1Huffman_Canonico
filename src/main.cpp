#include "../include/CompresorHuffman.h"
#include <iostream>
#include <string>
#include <locale>

#ifdef _WIN32
#include <windows.h>
#endif

void configurarConsola() {
#ifdef _WIN32
    // Configurar consola para UTF-8 en Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    std::locale::global(std::locale(""));
}

void mostrarMenu() {
    std::cout<<"\n┌──────────────────────────────────────────────────────────────┐\n";
    std::cout << "│                         MENÚ PRINCIPAL                       │\n";
    std::cout << "├──────────────────────────────────────────────────────────────┤\n";
    std::cout << "│  1. Comprimir texto nuevo                                    │\n";
    std::cout << "│  2. Usar texto de ejemplo                                    │\n";
    std::cout << "│  3. Información sobre Huffman Canónico                       │\n";
    std::cout << "│  4. Salir                                                    │\n";
    std::cout << "└──────────────────────────────────────────────────────────────┘\n";
    std::cout << "\nSeleccione una opción: ";
}

void mostrarInformacion() {
    std::cout<<"\n╔══════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║            ¿QUÉ ES LA CODIFICACIÓN HUFFMAN CANÓNICA?             ║\n";
    std::cout << "╚══════════════════════════════════════════════════════════════════╝\n\n";

    std::cout << "La codificación Huffman Canónica es una variante del algoritmo de\n";
    std::cout << "Huffman que genera códigos únicos y reproducibles.\n\n";

    std::cout << "Características principales:\n";
    std::cout << "  • Los códigos se asignan de forma determinística\n";
    std::cout << "  • Se ordenan primero por longitud, luego por símbolo\n";
    std::cout << "  • Los códigos son incrementales dentro de cada longitud\n";
    std::cout << "  • Facilita la transmisión (solo se necesitan las longitudes)\n\n";

    std::cout << "Ventajas:\n";
    std::cout << "  ✓ Reproducibilidad: mismo texto = mismos códigos\n";
    std::cout << "  ✓ Eficiencia: solo se transmiten longitudes de código\n";
    std::cout << "  ✓ Simplicidad: reconstrucción del árbol más sencilla\n\n";

    std::cout << "Presione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

std::string obtenerTextoUsuario() {
    std::string texto;
    std::cout<<"\n┌────────────────────────────────────────────────────────────────┐\n";
    std::cout << "│                    ENTRADA DE TEXTO                            │\n";
    std::cout << "└────────────────────────────────────────────────────────────────┘\n";
    std::cout << "\nIngrese el texto a comprimir (mínimo 30 caracteres):\n";
    std::cout << "→ ";

    std::getline(std::cin, texto);

    while (texto.length() < 30) {
        std::cout << "\n⚠ Error: El texto debe tener al menos 30 caracteres.\n";
        std::cout << "   Caracteres actuales: " << texto.length() << "\n";
        std::cout << "\nIntente nuevamente:\n→ ";
        std::getline(std::cin, texto);
    }

    return texto;
}

std::string obtenerTextoEjemplo() {
    std::cout <<"\n────────────────────────────────────────────────────────────\n";
    std::cout << "                     TEXTOS DE EJEMPLO                         \n";
        std::cout << "────────────────────────────────────────────────────────────\n";
        std::cout << "  1. Texto con muchos espacios                              \n";
        std::cout << "  2. Texto con pocos símbolos distintos                     \n";
        std::cout << "  3. Texto con distribución uniforme                        \n";
        std::cout << "────────────────────────────────────────────────────────────\n";
    std::cout << "\nSeleccione un ejemplo: ";

    int opcion;
    std::cin >> opcion;
    std::cin.ignore();

    switch (opcion) {
        case 1:
            return "isa     y      lau      prueban      el      codigo";
        case 2:
            return "isalauisalauisalauisalauisalauisalauisalauisalauisa";
        case 3:
            return "abcdefghijklmnopqrstuvwxyz 1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        default:
            return "Este es un texto de ejemplo para demostrar la compresión Huffman Canónica en acción.";
    }
}

int main() {
    configurarConsola();
    bool continuar = true;

    while (continuar) {
        mostrarMenu();

        int opcion;
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1: {
                std::string texto = obtenerTextoUsuario();
                CompresorHuffman compresor;
                compresor.comprimir(texto);
                compresor.mostrarResultados();
                compresor.mostrarEstadisticas();

                std::cout << "\n\nPresione Enter para continuar...";
                std::cin.get();
                break;
            }
            case 2: {
                std::string texto = obtenerTextoEjemplo();
                std::cout << "\nTexto seleccionado: \"" << texto << "\"\n";
                CompresorHuffman compresor;
                compresor.comprimir(texto);
                compresor.mostrarResultados();
                compresor.mostrarEstadisticas();

                std::cout << "\n\nPresione Enter para continuar...";
                std::cin.get();
                break;
            }
            case 3:
                mostrarInformacion();
                break;
            case 4:
                std::cout << "\n¡Gracias por usar el Compresor Huffman Canónico!\n\n";
                continuar = false;
                break;
            default:
                std::cout << "\n⚠ Opción inválida. Intente nuevamente.\n";
                std::cout << "Presione Enter para continuar...";
                std::cin.get();
        }
    }

    return 0;
}