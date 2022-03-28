#include <iostream>
#include "kraken/controller/controller.h"
#include "kraken/tools/protstring.h"
#include "kraken/tools/prottest.h"
#include "kraken/tools/arraylist.h"

#include <string>

bool summary_flag = false;

ProtTest test("=== ArrsayList ===");
ArrayList<int> al;

void testInsertingAndRetrievingInList() {
    int a = 3;
    al.insert(a);
    test.test("Insert and retrieve information", al.get(0) == a);
}

void testInsertIndexBiggerThanSize() {
    int a = al.get(25);
    test.test("Retrieving index > size should return NULL", a == NULL);
}

void testReplacingInList() {
    int b = 4;
    al.replace(0, b);
    test.test("Replace information", al.get(0) == b);
}

void testRemoveInformation() {
    int c = 5;
    size_t size = al.size();
    al.insert(c);
    int d = al.remove(size);

    test.test("Remove information", (d == c) && (size == al.size()));
}

void testResetAndIsEmpty() {
    al.reset();
    test.test("Reset and is Empty", !al.is_empty() == true);
}

void testForceResize() {
    for (int i = 0; i < 100; i++)
        al.insert(i);
    
}


int main(void) {

    testInsertingAndRetrievingInList();
    testInsertIndexBiggerThanSize();
    testReplacingInList();
    testRemoveInformation();
    testResetAndIsEmpty();
    testForceResize();

    test.report();

    return 0;
}