#include "CharBag.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include "ZipTable.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


typedef char* Buffer;


// Construye una ZipTable a partir de un array de caracteres de tamaño n
// Complejidad: O(n * log(n))
ZipTable buildZipTable(int n, Buffer buffer) {
	CharBag bag = emptyCharBag(256);
	for (int i = 0; i < n; ++i)
		add(bag, buffer[i]);

	PriorityQueue queue = emptyPriorityQueue();
	CharBagIterator it = iterate(bag);
	while (valid(it)) {
		enqueue(queue, leaf(currentChar(it), currentCount(it)));
		next(it);
	}

	while (size(queue) > 1) {
		HuffmanTree a = dequeue(queue);
		HuffmanTree b = dequeue(queue);
		enqueue(queue, binary(a,b));
	}

	HuffmanTree completeTree = dequeue(queue);

	ZipTable result = buildTable(completeTree);

	deleteCharBagIterator(it);
	deleteCharBag(bag);
	deletePriorityQueue(queue);
	deleteHuffmanTree(completeTree);

	return result;
}


// Lee todos los caracteres de un archivo en un buffer y retorna su tamaño
int readBuffer(char* filename, Buffer& buffer) {
	vector<char> aux;
	ifstream file(filename);
	char c;
	while (file.good()) {
		file.get(c);
		aux.push_back(c);
	}
	int size = aux.size();
	buffer = new char[size];
	for (int i = 0; i < size; ++i)
		buffer[i] = aux[i];
	return size;
}


// Libera la memoria reservada por la función readBuffer
void deleteBuffer(Buffer& buffer) {
	delete[] buffer;
}


// Lee el archivo test.txt y genera:
// 1. La tabla de compresión test.ztb
// 2. El archivo comprimido en binario test.comp.bin
// 3. El archivo comprimido en texto plano test.comp.txt
int main() {
	Buffer buffer;
	int n = readBuffer("test.txt", buffer);
	if (n == 0) {
		cout << "Empty file." << endl;
		return 1;
	}
	ZipTable table = buildZipTable(n, buffer);
	write(table, "test.ztb");
	compress(table, "test.txt", "test.zip.txt", "test.zip.bin");
	deleteBuffer(buffer);
	deleteZipTable(table);
	return 0;
}
