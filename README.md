# Algoritmo1Huffman_Canonico

 ### Docente
- Alexander De Jesus Narvaez Berrio

### *Integrantes*
 - Maria Laura Tafur. (mltafurg@eafit.edu.co)
 - Isabella Ocampo Sánchez. (iocampos1@eafit.edu.co

### *Video del código* 
(https://www.youtube.com/watch?v=XpH3RBngGq0)

##### Plataforma y herramientas utilizadas
> Clion 2024.3.5.
> Librerías de Clion (iostrem, queue, iomanip, vector, string, unordered_map )

### *Descripción:*
Este proyecto busca comprimir cadenas de texto mediante el algoritmo de Huffman. 
La estructura del proyecto es: 
- /include: Aquí encontrarás todos los archivos .h
- /src: Aquí encontrarás todos los archivos .cpp, incluído el main. 
- /Información: Aquí encontrarás 2 archivos específicos que permiten la construcción del árbol con la infromcion.
  
### *¿Cómo compilar y ejecutar?*
PASOS: 
1. Clona el repositorio en el entorno de desarrollo que prefieras.
2. Dirigete al archivo main, ubicado en la carpeta src, y compilalo.
3. Si elegiste la opción 1, digita una cadena mayor a 30 caracteres
     EJEMPLO:
     Entrada: > mi mama se fue de viaje y comio mucho helado
     Salida: (Tabla de frecuencias, Árbol Huffman, Tabla con códigos canónicos, resultado de compresion, estadisticas de compresión)
   Si elegiste la opcion 2, tendrás tres opciones de ejemplos, cuyas cadenas están determinadas.
   
##### Explicación Huffman Canónico:
En el menú de opciones al ejecutar el programa, si se selecciona la opción 3, encontrarás información interesante sobre Huffman Canónico. 

### *Decisiones de diseño:*
Criterios de desempate:
- Cuando dos nodos tienen la misma frecuencia en la cola de prioridad, se desempata por orden alfabético del símbolo (ascendente)
- Implementado en `NodoComparador`: primero compara frecuencias, luego símbolos

Estructuras de datos utilizadas:
- `std::priority_queue`: con comparador personalizado (min-heap) para construir el árbol de Huffman
- `std::unordered_map<char, int>`: para almacenar frecuencias de caracteres
- `std::unordered_map<char, std::string>`: para mapear símbolos a códigos binarios
- `std::vector<InfoCodigo>`: para ordenar y generar códigos canónicos
- Árbol binario: mediante punteros (NodoHuffman) con hijos izquierdo y derecho

#### Resultados de Compresión:
Para cada cadena existen unos resultados diferentes, por tanto, el usuario debe validar con la cadena que ingrese. 
Sin embargo, para los ejemplo de la opción 2 si hay resultados determinados. 



   
