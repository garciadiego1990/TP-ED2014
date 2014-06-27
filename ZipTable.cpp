#include "ZipTable.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <ctype.h>

using namespace std;

struct BitChainStr {
	vector<bool> bits;
};

BitChain emptyBitChain() {
	BitChain result = new BitChainStr;
	return result;
}

void deleteBitChain(BitChain& b) {
	delete b;
}

void append(BitChain& b, bool on) {
	b->bits.push_back(on);
}

void remove(BitChain& b) {
	b->bits.pop_back();
}

void write(BitChain b, ofstream& file) {
	vector<bool> aux(b->bits);
	while (!aux.empty()) {
		file << aux.back();
		aux.pop_back();
	}
}

void read(BitChain& b, ifstream& file) {
	long long aux;
	file >> aux;
	while (aux > 0) {
		b->bits.push_back(aux % 10 == 1);
		aux /= 10;
	}
}

#define CAP 256

struct ZipTableStr {
	BitChain* chains;
};

ZipTable emptyZipTable() {
	ZipTable result = new ZipTableStr;
	result->chains = new BitChain[CAP];
	for (int i = 0; i < CAP; ++i)
		result->chains[i] = emptyBitChain();
	return result;
}

void deleteZipTable(ZipTable& z) {
	for (int i = 0; i < CAP; ++i)
		deleteBitChain(z->chains[i]);
	delete[] z->chains;
	delete z;
}

void add(ZipTable& z, char c, BitChain b) {
	(*z->chains[(int)c]) = *b;
}

void write(ZipTable z, char* filename) {
	ofstream file(filename);
	for (int i = 0; i < CAP; ++i) {
		if (!z->chains[i]->bits.empty()) {
			file << i << " (" << (isalpha(i) ? (char)i : ' ') << ") : ";
			write(z->chains[i], file);
			file << endl;
		}
	}
	file.close();
}

void read(ZipTable& z, char* filename) {
	ifstream file(filename);
	int i;
	char c;
	while (file.good()) {
		file >> i;
		file >> c;
		read(z->chains[i], file);
	}
	file.close();
}

void compress(ZipTable z, char* sourceFile, char* targetReadableFile, char* targetBinaryFile) {
	ifstream source(sourceFile);
	ofstream target(targetReadableFile);
	ofstream binary(targetBinaryFile, ofstream::binary);
	vector<bool> buffer;
	char c;
	while (source.good()) {
		source.get(c);
		write(z->chains[(int)c], target);
		buffer.push_back(z->chains[(int)c]);
		target << ' ';
	}
	c = 0;
	int i;
	for (i = 0; !buffer.empty(); ++i) {
		c = (c << 1) | buffer.back();
		buffer.pop_back();
		if (i == 7) {
			binary.put(c);
			c = 0;
			i = 0;
		}
	}
	if (i > 0)
		binary.put(c);
	source.close();
	target.close();
	binary.close();
}
