/* 
 * File: testdata.h
 * Author: Alex Katrompas
 * 
 * DO NOT MODIFY THIS FILE
 * LEAVE THIS COMMENT HEADER HERE
 */

#ifndef TESTDATA_H
#define TESTDATA_H

/*
 * used to make test case number between 1 and 13
 * note that the test data will have 2 extra entries
 * for a bad data test. there will always be 3-10 
 * based on these defines
 */
#define TEST_DATA_BASE 8
#define TEST_DATA_OFFSET 1
#define DATA_STR_SIZE 16
#define MAXID 100
#define DEFAULT_DATA_SIZE 10

#include <stdlib.h>    // srand, rand
#include <string.h>    // strcpy
#include <iostream>    // cout, endl

using std::cout;
using std::endl;

#include "data.h"

class testData {
public:
    testData(int);
    ~testData();

    void displayTestData();
    int getNumData();
    bool getData(int, Data*);
    bool getDataElement(int, Data*);
    int getRandomId();

private:
    int numData;
    int *ids;
    char **data;

    int createTestData(int);
    bool exists(int);
    bool inIntArray(int *haystack, int needle, const int SIZE);

};

#endif /* TESTDATA_H */

