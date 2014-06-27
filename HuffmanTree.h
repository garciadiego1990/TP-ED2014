#include "ZipTable.h"
#include <string>

struct HuffmanTreeStr;
typedef HuffmanTreeStr* HuffmanTree;

// Construye una hoja de un árbold de Huffman a partir de un caracter y un peso.
// Complejidad: O(1)
HuffmanTree leaf(char c, int w);

// Construye una nodo binario de un árbol de Huffman a partir de dos hijos.
// Complejidad: O(1)
HuffmanTree binary(HuffmanTree a, HuffmanTree b);

// Libera toda la memoria utilizada por un árbol de Huffman.
void deleteHuffmanTree(HuffmanTree& t);

// Retorna el peso de un árbol de Huffman.
// Cmplejidad: O(1)
int weight(HuffmanTree t);

// Construye la tabla de compresión asociada al árbol de Huffman.
ZipTable buildTable(HuffmanTree t);

// Función agregada para darle mas claridad a los tests
std::string toString(HuffmanTree t);
