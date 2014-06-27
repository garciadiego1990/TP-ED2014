#include "CharBag.h"
#include "List.h"
#include <iostream>
#include <sstream>

using namespace std;

// Invariantes de Representación:
// -- La cantidad de elementos del Char Bag ("cantElem") es menor o igual a la capacidad del mismo ("capacidad")
// -- Todas las posiciones del array tienen ocurrencias mayores o iguales a 0
// -- Los enteros "capacidad" y "cantElem" son mayores o iguales a 0
// -- Para cada elemento que hay en "elems", la cantidad de ocurrencias en el array de ese elemento es mayor a 0
// -- La lista "elems" no tiene elementos repetidos
// -- La longitud de "elems" es igual a la cantidad de posiciones del array con ocurrencias mayores a 0

struct CharBagStr
{
    int ocurrencias[256];
    int capacidad;
    int cantElem;
    List elems;
};


CharBag emptyCharBag(int n)
{
    CharBag cb = new CharBagStr;
    cb->cantElem = 0;
    cb->capacidad = n;
    cb->elems = emptyList();

    for(int i = 0 ; i<256; i++)
    {
        cb->ocurrencias[i] = 0;
    }

    return cb;
}


void deleteCharBag(CharBag& b)
{
    destroyList(b->elems);
    delete b;
}

void add(CharBag& b, char c)
{
    if(b->cantElem < b->capacidad)
    {
        b->ocurrencias[(int)(unsigned char)c]++;
        b->cantElem++;

        if(b->ocurrencias[(int)(unsigned char)c] == 1)
        {
            pushBack(b->elems, c);
        }
    }
    else
    {
        cout << "El CharBag esta lleno" << endl;
    }
}


int get(CharBag& b, char c)
{
    return b->ocurrencias[(int)(unsigned char)c];
}


struct CharBagIteratorStr
{
    CharBag ch;

    ListIterator iteratorL;
};


CharBagIterator iterate(CharBag b)
{
    CharBagIterator it = new CharBagIteratorStr;
    it->ch = b;
    it->iteratorL = createIterator(b->elems);

    return it;
}


void deleteCharBagIterator(CharBagIterator& it)
{
    delete it;
}


bool valid(CharBagIterator it)
{
    return isValid(it->iteratorL);
}


void next(CharBagIterator it)
{
    it->iteratorL = next(it->iteratorL);
}


char currentChar(CharBagIterator it)
{
    return getCurrentElement(it->iteratorL);
}


int currentCount(CharBagIterator it)
{
    return (it->ch->ocurrencias[(int)(unsigned char)getCurrentElement(it->iteratorL)]);
}


string toString(CharBag c)
{
    stringstream sout;
    sout << "[ ";
    CharBagIterator it;

    for(it = iterate(c); valid(it); next(it))
    {
        sout << "'" << currentChar(it) << "'," << currentCount(it) << " ";
    }
    sout << "]";
    deleteCharBagIterator(it);
    return sout.str();
}
