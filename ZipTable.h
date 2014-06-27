
// Tipo para cadenas de bits
struct BitChainStr;
typedef BitChainStr* BitChain;

// Construye una cadena de bits vacía
// Complejidad: O(1)
BitChain emptyBitChain();

// Libera la memoria utilizada por una cadena de bits
void deleteBitChain(BitChain& b);


// Tipo para cadenas de bits
struct BitChainStr;
typedef BitChainStr* BitChain;

// Construye una cadena de bits vacía
// Complejidad: O(1)
BitChain emptyBitChain();

// Libera la memoria utilizada por una cadena de bits
void deleteBitChain(BitChain& b);

// Agrega un bit en on/off a la cadena de bits
// Complejidad: O(1)
void append(BitChain& b, bool on);

// Remueve el último bit agregado a la cadena de bits
// Complejidad: O(1)
void remove(BitChain& b);


// Tipo de una tabla de compresión
struct ZipTableStr;
typedef ZipTableStr* ZipTable;

// Construye una tabla de compresión vacía
ZipTable emptyZipTable();

// Libera la memoria utilizada por una tabla de compresión
void deleteZipTable(ZipTable& z);

// Agrega la asociación entre un caracter y su codificación en una cadena de bits
void add(ZipTable& z, char c, BitChain b);

// Escribe el contenido de la tabla a un archivo
void write(ZipTable z, char* filename);

// Lee el contenido de la tabla de un archivo
void read(ZipTable& z, char* filename);

// Comprime el archivo fuente utilizando la tabla de compresión
// escribiendo el resultado en el archivo destino
void compress(ZipTable z, char* sourceFile, char* targetReadableFile, char* targetBinaryFile);

