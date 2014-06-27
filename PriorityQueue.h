#include "HuffmanTree.h"
#include <string>

struct PriorityQueueStr;
typedef PriorityQueueStr* PriorityQueue;

// Construye una PriorityQueue vacía.
PriorityQueue emptyPriorityQueue();

// Libera la memoria utilizada por la PriorityQueue.
void deletePriorityQueue(PriorityQueue& q);

// Retorna la cantidad de elementos en la PriorityQueue.
// Complejidad: O(1)
int size(PriorityQueue q);

// Agrega un elemento a la PriorityQueue.
// Complejidad: O(log(size(q)))
void enqueue(PriorityQueue& q, HuffmanTree t);

// Remueve y retorna el elemento de menor prioridad de la PriorityQueue.
// Complejidad: O(log(size(q)))
HuffmanTree dequeue(PriorityQueue& q);

// Función agregada para darle mas claridad a los tests
std::string toString(PriorityQueue q);
