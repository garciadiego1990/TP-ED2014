#include "HuffmanTree.h"
#include <iostream>
#include <sstream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

void check(HuffmanTree t, string r) {
	string ls = toString(t);
	if (ls != r) {
		cout << "ERROR: " << ls << " != " << r << endl;
		exit(1);
	}
}

void testLeaf()
{
    HuffmanTree h = leaf('r',190);
    check(h,"[ 'r',190 ]");
    deleteHuffmanTree(h);

    cout << "testLeaf - OK" << endl;
}

void testBinary()
{
    HuffmanTree h1 = leaf('a',100);
    HuffmanTree h2 = leaf('x',90);
    h1 = binary(h1,h2);
    check(h1,"[ 'ax',190 ]");
    h2 = leaf('w',45);
    h1 = binary(h1,h2);
    check(h1,"[ 'axw',235 ]");
    deleteHuffmanTree(h1);

    cout << "testBinary - OK" << endl;
}

void testWeight()
{
    HuffmanTree h1 = leaf('d', 18);
    HuffmanTree h2 = leaf('f', 23);

    assert(weight(h1) == 18);
    assert(weight(h2) == 23);

    h1 = binary(h1, h2);
    assert(weight(h1) == 41);

    h2 = leaf('j', 50);
    assert(weight(h2) == 50);

    h1 = binary (h1, h2);
    assert(weight(h1) == 91);

    deleteHuffmanTree(h1);


    cout << "testWeight - OK" << endl;
}

int main()
{

    testLeaf();
    testBinary();
    testWeight();
    return 0;
}
