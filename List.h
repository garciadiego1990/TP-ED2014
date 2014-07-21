#include <iostream>
#define ELEM_TYPE unsigned char

struct listNode;
struct ListStr;
typedef ListStr* List;

// Retorna una lista vacia
List emptyList();

// Retorna true si la lista pasada por parametro es vacia
bool isEmptyList(List l);

// Agrega un elemento a la lista pasada por parametro
void pushBack(List &l, ELEM_TYPE elem);

// Destuye todos los elementos de la lista
void destroyList(List &l);

// Tipo de un iterador de lista
typedef listNode* ListIterator;

// Retorna un iterador de lista
ListIterator createIterator(List &l);

// Devuelve True si el iterador pasado por parametro es distinto NULL
bool isValid(ListIterator l);

// Devuelve el elemento apuntado por el iterador
ELEM_TYPE getCurrentElement(ListIterator l);

// Avanza al siguiente elemento apuntado por el iterador
// Precondición: El next del elemento actual debe ser distinto de NULL
ListIterator next(ListIterator &l);

/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

// DEFENSA

// Borra de la lista "l" el elemento actual apuntado por el iterador "it"
// Precondicion: "it" apunta a un nodo de "l"
// Complejidad: O(1), si el elemento a borrar es el primero; O(n) si el elemento a borrar es otro (n = longitud de la lista)
void removeCurrentElement(List &l, ListIterator &it);


// Borra de la lista "l" el elemento "e"
// Precondicion: "e" pertenece a "l"
// Complejidad: O(1), si el elemento a borrar es el primero; O(n) si el elemento a borrar es otro (con n = longitud de la lista)
void removeElement(List &l, ELEM_TYPE e);
