#include "PriorityQueue.h"
#include <iostream>
#include <sstream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

void check(PriorityQueue pq, string r) {
	string ls = toString(pq);
	if (ls != r) {
		cout << "ERROR: " << ls << " != " << r << endl;
		exit(1);
	}
}


void testEmptyPriorityQueue()
{
    PriorityQueue pq = emptyPriorityQueue();
    check(pq, "[ ]");
    deletePriorityQueue(pq);

    cout << "testEmptyPriorityQueue - OK" << endl;
}



void testEnqueue()
{
    PriorityQueue pq = emptyPriorityQueue();
    HuffmanTree h1 = leaf('c', 12);
    enqueue(pq,h1);
    check(pq, "[ [ 'c',12 ] ]");

    HuffmanTree h2 = leaf('e', 14);
    enqueue(pq,h2);
    check(pq, "[ [ 'c',12 ] [ 'e',14 ] ]");


    HuffmanTree h3 = leaf('q',1);
    enqueue(pq, h3);
    check(pq, "[ [ 'q',1 ] [ 'e',14 ] [ 'c',12 ] ]");

    h1 = leaf('z', 10);
    h2 = leaf('p', 16);
    h3 = binary(h1,h2);
    enqueue(pq, h3);
    check(pq, "[ [ 'q',1 ] [ 'e',14 ] [ 'c',12 ] [ 'zp',26 ] ]");

    deletePriorityQueue(pq);


    cout << "testEnqueue - OK" << endl;
}

void testDequeue()
{
    PriorityQueue pq = emptyPriorityQueue();
    HuffmanTree h1 = leaf('c', 12);
    enqueue(pq,h1);
    HuffmanTree h2 = leaf('e', 14);
    enqueue(pq,h2);
    HuffmanTree h3 = leaf('q',1);
    enqueue(pq, h3);
    h1 = leaf('z', 10);
    h2 = leaf('p', 16);
    h3 = binary(h1,h2);
    enqueue(pq, h3);

    HuffmanTree h = dequeue(pq);
    assert(weight(h) == 1);
    check(pq, "[ [ 'c',12 ] [ 'e',14 ] [ 'zp',26 ] ]");

    deleteHuffmanTree(h);

    h = dequeue(pq);
    assert(weight(h) == 12);
    check(pq, "[ [ 'e',14 ] [ 'zp',26 ] ]");

    deleteHuffmanTree(h);

    h = dequeue(pq);
    assert(weight(h) == 14);
    check(pq, "[ [ 'zp',26 ] ]");

    deleteHuffmanTree(h);

    h = dequeue(pq);
    assert(weight(h) == 26);
    check(pq, "[ ]");

    deleteHuffmanTree(h);
    deletePriorityQueue(pq);

    cout << "testDequeue - OK" << endl;
}


void testSize()
{
    PriorityQueue pq = emptyPriorityQueue();
    assert(size(pq) == 0);
    HuffmanTree h1 = leaf('c', 12);
    enqueue(pq,h1);
    assert(size(pq) == 1);
    h1 = leaf('e', 14);
    enqueue(pq,h1);
    assert(size(pq) == 2);
    h1 = leaf('q',1);
    HuffmanTree h2 = dequeue(pq);
    assert(size(pq) == 1);
    h1 = binary(h1,h2);
    enqueue(pq,h1);
    assert(size(pq) == 2);
    h1 = leaf('z', 10);
    h2 = leaf('p', 16);
    HuffmanTree h3 = binary(h1,h2);
    enqueue(pq, h3);
    assert(size(pq) == 3);

    deletePriorityQueue(pq);
    cout << "testSize - OK" << endl;
}


int main()
{
    testEmptyPriorityQueue();
    testEnqueue();
    testDequeue();
    testSize();


    return 0;
}
