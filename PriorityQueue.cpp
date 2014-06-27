#include "PriorityQueue.h"
#include <iostream>
#include <sstream>
#define ELEM_TYPE HuffmanTree
#define minData leaf(0,0)
#define maxSize 1000

using namespace std;


// Invariantes de representación:
// -- El size es mayor o igual a 0
// -- El size es menor o igual al maxSize
// -- El priority queue se va llenando de izquierda a derecha
// -- El centinela es el elemento con el peso mas chico de todos
// -- Todo nodo tiene un peso menor o igual al de su hijo izquierdo
// -- Todo nodo tiene un peso menor o igual al de su hijo derecho

struct PriorityQueueStr
{
    int size;
    ELEM_TYPE* elems;
};


PriorityQueue emptyPriorityQueue()
{
    PriorityQueue pq = new PriorityQueueStr;
    pq->size = 0;
    pq->elems = new ELEM_TYPE[maxSize+1];
    pq->elems[0] = minData; //centinela
    return pq;
}


void deletePriorityQueue(PriorityQueue& q)
{
    deleteHuffmanTree(q->elems[0]); // Se elim¡na el centinela

    // Con este ciclo lo que hago es eliminar los elementos almacenados dentro del Priority Queue
    for(int i = 1; i <= q->size; i++)
    {
        deleteHuffmanTree(q->elems[i]);
    }
    delete[] q->elems;
    delete q;
}


int size(PriorityQueue q)
{
    return q->size;
}


bool isFull(PriorityQueue& q)
{
    return (q->size == maxSize);
}


void enqueue(PriorityQueue& q, HuffmanTree t)
{
    if(isFull(q))
    {
        cout << "El PriorityQueue esta lleno" << endl;
    }
    else
    {
        q->size++;
        int i = q->size;
        while(weight(q->elems[i/2])>weight(t))
        {
            q->elems[i] = q-> elems[i/2];
            i = i/2;
        }
        q->elems[i] = t;
    }
}


bool isEmpty(PriorityQueue& q)
{
    return (q->size == 0);
}


HuffmanTree dequeue(PriorityQueue& q)
{
    if(isEmpty(q))
    {
        cout << "El PriorityQueue esta vacio" << endl;
        return NULL;
    }
    else
    {
        int i;
        int child;
        ELEM_TYPE minElem = q->elems[1];
        ELEM_TYPE lastElem = q->elems[q->size];
        q->size--;

        for(i=1; i*2<=q->size; i=child)
        {
            child=i*2;
            if(child != q->size && weight(q->elems[child + 1]) < weight(q->elems[child]))
            {
                child++;
            }

            if(weight(lastElem) > weight(q->elems[child]))
            {
                q->elems[i] = q->elems[child];
            }
            else
            {
                break;
            }
        }

        q->elems[i] = lastElem;
        return minElem;
    }
}


string toString(PriorityQueue q)
 {
    stringstream sout;
	sout << "[ ";
	for(int i = 1; i <= q->size; i++)
	{
        sout << toString(q->elems[i]) << " ";
	}
    sout << "]";
    return sout.str();
}
