#include <string>

// Tipo de un multiconjunto de caracteres
struct CharBagStr;
typedef CharBagStr* CharBag;

// Retorna un CharBag vacío, con capacidad para almacenar n chars.
CharBag emptyCharBag(int n);

// Libera la memoria utilizada por el CharBag c.
void deleteCharBag(CharBag& b);

// Agrega una ocurrencia del caracer c en el CharBag.
// Complejidad: O(1)
void add(CharBag& b, char c);

// Retorna la cantidad de ocurrencias del caracter c en el CharBag.
// Complejidad: O(1)
int get(CharBag& b, char c);

// Función agregada para darle mas claridad a los tests
std::string toString(CharBag c);

// Tipo de un iterador de CharBags
struct CharBagIteratorStr;
typedef CharBagIteratorStr* CharBagIterator;

// Construye un iterador a un CharBag apuntando al primer elemento definido.
// Complejidad: O(1)
CharBagIterator iterate(CharBag b);

// Libera la memoria correspondiente al iterador.
void deleteCharBagIterator(CharBagIterator& it);

// Indica si el iterador apunta a un element válido.
// Complejidad: O(1)
bool valid(CharBagIterator it);

// Avanza al siguiente elemento definido en el CharBag
// (aquellos con ocurrencias mayor a cero)
// PRE: valid(it)
// Complejidad: O(1), NOTA: Esto debe ser independiente del tamaño máximo del CharBag
void next(CharBagIterator it);

// Retorna el caracter actualmente apuntado por el iterador.
// PRE: valid(it)
// Complejidad: O(1)
char currentChar(CharBagIterator it);

// Retorna la cantidad de ocurrencias del caracter actualmente apuntado por el iterador.
// PRE: valid(it)
// Complejidad: O(1)
int currentCount(CharBagIterator it);


////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

// DEFENSA


// Remueve una aparicion del caracter c del charbag
// Complejidad: O(1)
void remove(CharBag& cb, char c);


// Remueve del charbag una aparicion del caracter actualmente apuntado por el iterador
// Complejidad: O(1)
void removeCurrent(CharBagIterator& it);
