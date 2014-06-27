#include "CharBag.h"
#include <iostream>
#include <sstream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

void check(CharBag c, string r) {
	string ls = toString(c);
	if (ls != r) {
		cout << "ERROR: " << ls << " != " << r << endl;
		exit(1);
	}
}

void testEmptyCharBag()
{
    CharBag cb = emptyCharBag(300);
    check(cb,"[ ]");
    deleteCharBag(cb);
    cout << "testEmptyCharBag - OK" << endl;
}

void testAdd()
{
    CharBag cb = emptyCharBag(8);

    add(cb, 'a');
    check(cb, "[ 'a',1 ]");
    add(cb, 'b');
    check(cb, "[ 'a',1 'b',1 ]");
    add(cb, 'b');
    check(cb, "[ 'a',1 'b',2 ]");

    deleteCharBag(cb);

    cout << "testAdd - OK" << endl;
}

void testGet()
{
    CharBag cb = emptyCharBag(2);
    assert(get(cb, 'a') == 0);

    add(cb, 'a');
    assert(get(cb, 'a') == 1);
    add(cb, 'a');
    assert(get(cb, 'a') == 2);

    deleteCharBag(cb);

    cout << "testGet - OK" << endl;
}

void testValid()
{
    CharBag cb = emptyCharBag(8);

    CharBagIterator it = iterate(cb);

    assert(! valid(it));

    deleteCharBagIterator(it);
    add(cb, 'a');
    it = iterate(cb);
    assert (valid(it));
    add(cb, 'b');
    next(it);
    assert(valid(it));
    add(cb, 'b');
    next(it);
    assert(!valid(it));


    deleteCharBagIterator(it);
    deleteCharBag(cb);

    cout << "testValid - OK" << endl;
}

void testCurrentChar()
{
    CharBag cb = emptyCharBag(8);
    add(cb, 'a');
    CharBagIterator it = iterate(cb);

    assert(currentChar(it) == 'a');
    add(cb, 'b');
    next(it);
    assert(currentChar(it) == 'b');

    add(cb, 'b');
    add(cb, 'c');
    next(it);
    assert(currentChar(it) == 'c');

    deleteCharBagIterator(it);
    deleteCharBag(cb);

     cout << "testCurrentChar - OK" << endl;

}

void testCurrentCount()
{
    CharBag cb = emptyCharBag(8);
    add(cb, 'a');
    CharBagIterator it = iterate(cb);

    assert(currentCount(it) == 1);
    add(cb, 'b');
    next(it);
    assert(currentCount(it) == 1);

    add(cb, 'b');
    assert(currentCount(it) == 2);
    add(cb, 'c');
    next(it);
    assert(currentCount(it) == 1);

    deleteCharBagIterator(it);
    deleteCharBag(cb);

     cout << "testCurrentCount - OK" << endl;
}

int main()
{
    testEmptyCharBag();
    testAdd();
    testGet();
    testValid();
    testCurrentChar();
    testCurrentCount();

    return 0;
}
