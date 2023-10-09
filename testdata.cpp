/* 
 * File: testdata.cpp
 * Author: Alex Katrompas
 * 
 * DO NOT MODIFY THIS FILE
 * LEAVE THIS COMMENT HEADER HERE
 */

#include "testdata.h"

/*
 * ****************************************
 * Constructors / Destructors
 * ****************************************
 */

testData::testData(int n) {
    if (n >= TEST_DATA_OFFSET && n <= TEST_DATA_BASE + TEST_DATA_OFFSET) {
        createTestData(n);
    } else {
        createTestData(DEFAULT_DATA_SIZE);
    }
}

testData::~testData() {
    delete ids;
    for (int i = 0; i < numData; i++) {
        delete data[i];
    }
    delete data;
}

/*
 * ****************************************
 * Public
 * ****************************************
 */

int testData::getNumData() {
    return numData;
}

void testData::displayTestData() {
    for (int i = 0; i < numData; i++) {
        cout << "\t" << i << ": " << ids[i] << " : " << data[i] << endl;
    }
    cout << endl;
}

bool testData::exists(int id) {
    bool exists = false;
    for (int i = 0; i < numData; i++) {
        if (ids[i] == id) {
            exists = true;
        }
    }
    return exists;
}

bool testData::getData(int id, Data *returnData) {
    bool found = false;
    returnData->id = -1;
    returnData->data = "";

    for (int i = 0; i < numData && !found; i++) {
        if (ids[i] == id) {
            returnData->id = ids[i];
            returnData->data = data[i];
            found = true;
        }
    }
    return found;
}

bool testData::getDataElement(int element, Data *returnData) {
    bool found = false;
    returnData->id = -1;
    returnData->data = "";

    if (element >= 0 && element < numData) {
        returnData->id = ids[element];
        returnData->data = data[element];
        found = true;
    }

    return found;
}

int testData::getRandomId() {
    return ids[rand() % numData];
}

/*
 * ****************************************
 * Private
 * ****************************************
 */

bool testData::inIntArray(int *haystack, int needle, const int SIZE) {
    bool found = false;
    for (int i = 0; i < SIZE && !found; i++) {
        if (haystack[i] == needle) {
            found = true;
        }
    }
    return found;
}

int testData::createTestData(int n) {
    if (n < TEST_DATA_OFFSET || n > TEST_DATA_BASE + TEST_DATA_OFFSET) {
        n = DEFAULT_DATA_SIZE;
    }

    n += 2; //adding two for bad data

    //making test data parallel arrays to hold test data
    try {
        ids = new int[n];
        data = new char*[n];
        for (int i = 0; i < n; i++) {
            ids[i] = -1;
            data[i] = new char[DATA_STR_SIZE];
        }
    } catch (...) {
        n = 0;
    }

    //filling arrays with test data
    int id;
    for (int i = 0; i < n - 2; i++) {

        id = rand() % MAXID + 1;
        while (inIntArray(ids, id, n)) {
            //guarantees unique id
            id = rand() % MAXID + 1;
        }
        ids[i] = id;

        do {
            //guarantees unique id
            id = rand() % MAXID + 1;
        } while (inIntArray(ids, id, n));
        //not this has a logic flaw if 
        ids[i] = id;

        for (int j = 0; j < DATA_STR_SIZE - 1; j++) {
            data[i][j] = rand() % 2 ? (rand() % (26)) + 'A' : (rand() % (26)) + 'a';
        }
        data[i][DATA_STR_SIZE - 1] = '\0';
    }

    ids[n - 2] = ids[rand() % (n - 2)]; //duplicating an entry randomly
    strcpy(data[n - 2], "duplicate");
    ids[n - 1] = -1; //duplicating the first entry
    strcpy(data[n - 1], "bad data");

    numData = n;
    return n;
}

