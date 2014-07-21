#include "List.h"

struct listNode
{
    ELEM_TYPE  elem;
    listNode* next;
};


struct ListStr
{
    listNode* first;
    listNode* last;
};


List emptyList()
{
    List ls = new ListStr;
    ls->first = NULL;
    ls->last = NULL;

    return ls;
}


// Inv. Rep.= Si el First es NULL, el last también lo será
bool isEmptyList(List l)
{
    return (l->first == NULL);
}


void pushBack(List &l, ELEM_TYPE elem)
{
    listNode* newNode = new listNode;
    newNode->elem = elem;
    newNode->next = NULL;

    if(isEmptyList(l))
    {
        l->first = newNode;
        l->last = newNode;
    }
    else
    {
        l->last->next = newNode;
        l->last = newNode;
    }
}


void destroyList(List &l)
{
    listNode* copyN;

    while(!isEmptyList(l))
    {
        copyN = l->first;
        l->first = copyN->next;
        delete copyN;
    }
    delete l;
}


ListIterator createIterator(List &l)
{
    return l->first;
}


bool isValid(ListIterator l)
{
    return (l != NULL);
}


ELEM_TYPE getCurrentElement(ListIterator l)
{
    return l->elem;
}


ListIterator next(ListIterator &l)
{
    return l->next;
}

//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


// DEFENSA

void removeCurrentElement(List &l, ListIterator &it)
{
    if(l->first == it) // si el elemento que tengo que borrar de la lista es el primero
    {
        if(l->first == l->last) // si el primer elemento es tambien el ultimo
        {
            l->first = NULL;
            l->last = NULL;
            delete it;
        }
        else{//si el ultimo elemento no es el primero

            l->first = it->next; // el primer elemento es ahora el siguiente
            delete it; // borro el antiguo primer elemento



        }
    }
    else // si, en cambio, el elemento que tengo que borrar de la lista no es el primero
    {
        ListIterator anterior = createIterator(l); // creo un iterador a la lista llamado "anterior"
        while(anterior->next != it) // mientras el siguiente de "anterior" no sea el nodo que tengo que borrar
        {
            anterior = next(anterior); // avanzo el iterador "anterior"
        }
        // al salir del while, "anterior" apunta al nodo anterior al que tengo que borrar
        anterior->next = it->next; // reconecto el nodo anterior (al que tengo que borrar) con el nodo siguiente del que tengo que borrar
        if(it == l->last)// si voy a borrar el ultimo elemento
        {
            l->last = anterior; // actualizo quien es el ultimo ahora

        }
        delete it; // borro el nodo que tengo que borrar
    }
}


void removeElement(List &l, ELEM_TYPE e)
{
    ListIterator it = createIterator(l); // Creo un iterador apuntando al primer elemento de la lista
    while(getCurrentElement(it) != e) // Mientras el elemento actual apuntado por el iterador no sea el que me piden borrar
    {
        it = next(it); // Avanzo el iterador
    }
    // Al salir del while, "it" apunta al elemento a borrar
    removeCurrentElement(l,it); // Borro el elemento de la lista
}
