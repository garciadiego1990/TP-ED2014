#include "HuffmanTree.h"
#include <iostream>
#include <sstream>

// El peso de un Huffman Tree es mayor o igual a cero
// Si el Huffman Tree no es una hoja, su peso es igual a la suma de los pesos de los sub-arboles izquierdo y derecho
// Un nodo de un Huffman Tree tiene 0 o 2 hijos, nunca tiene uno solo (izq == NULL si y solo si der == NULL)
// Todas las hojas del Huffman Tree tienen caracteres distintos (Los demas nodos tienen cualquier caracter)

using namespace std;

struct HuffmanTreeStr
{
    int peso;
    char c;
    HuffmanTree izq;
    HuffmanTree der;
};


HuffmanTree leaf(char c, int w)
{
    HuffmanTree hf = new HuffmanTreeStr;

    hf->c = c;
    hf->peso = w;
    hf->izq = NULL;
    hf->der = NULL;

    return hf;
}


HuffmanTree binary(HuffmanTree a, HuffmanTree b)
{
    HuffmanTree hf = new HuffmanTreeStr;

    hf->izq = a;
    hf->der = b;
    hf->peso = (hf->izq->peso) + (hf->der->peso);

    return hf;
}


void deleteHuffmanTree(HuffmanTree& t)
{
    if(t->izq != NULL)
    {
        deleteHuffmanTree(t->izq);
        deleteHuffmanTree(t->der);
    }
    delete t;
}


int weight(HuffmanTree t)
{
    return t->peso;
}


// Esta función devuelve verdadero si el HuffmanTree pasado por referencia es una hoja
bool isLeaf(HuffmanTree &t)
{
    return (t->izq == NULL && t->der == NULL);
}


// Recorre el HuffmanTree, y cada vez que llega a una hoja agrega el bitChain correspondiente en el zipTable
void recorrerHuffmanTree(HuffmanTree &t, BitChain &bc, ZipTable &zp)
{
    if(isLeaf(t))
    {
        add(zp,t->c,bc);
    }
    else
    {
        append(bc,0);
        recorrerHuffmanTree(t->izq,bc,zp);
        remove(bc);
        append(bc,1);
        recorrerHuffmanTree(t->der,bc,zp);
        remove(bc);
    }
}


ZipTable buildTable(HuffmanTree t)
{
    BitChain bc = emptyBitChain();
    ZipTable zp = emptyZipTable();

    if(isLeaf(t))
    {
        append(bc,1);
        add(zp,t->c,bc);
        remove(bc);
    }
    else
    {
        recorrerHuffmanTree(t,bc,zp);
    }

    deleteBitChain(bc);
    return zp;
}


void recorrerEimprimir(HuffmanTree t, stringstream &sout)
{
    if(isLeaf(t))
    {
        sout << t->c;
    }
    else
    {
        recorrerEimprimir(t->izq,sout);
        recorrerEimprimir(t->der,sout);
    }
}


string toString(HuffmanTree t)
{
    stringstream sout;
    sout << "[ '";
    recorrerEimprimir(t,sout);
    sout << "'," << t->peso << " ]";
    return sout.str();
}
