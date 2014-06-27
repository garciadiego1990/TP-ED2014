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

