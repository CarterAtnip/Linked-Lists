/* 
 * File: main.cpp
 * Author: Alex Katrompas
 * 
 * DO NOT MODIFY THIS FILE
 * LEAVE THIS COMMENT HEADER HERE
 */

#include "main.h"

int main() {

    //seed the rand function
    srand(time(NULL));

    //generate and display the test data
    testData testdata(rand() % (TEST_DATA_BASE + 1) + TEST_DATA_OFFSET);
    int numTestData = testdata.getNumData();
    cout << "displaying test data - " << numTestData << " elements" << endl;
    cout << "==================================" << endl;
    testdata.displayTestData();

    //making temporary data holder for testing
    Data tmpData;

    //making linked list object
    cout << "creating the linked list...";
    LinkedList list;
    cout << "done" << endl << endl;

    cout << "checking list...\n";
    cout << "\tThere are " << list.getCount() << " nodes." << endl;
    list.printList();
    cout << endl;

    //adding all the test data to the list
    for (int i = 0; i < numTestData; i++) {
        testdata.getDataElement(i, &tmpData);
        cout << "adding " << tmpData.id << ": " << tmpData.data << "... ";
        if (list.addNode(tmpData.id, &(tmpData.data))) {
            cout << "success" << endl;
        } else {
            cout << "failed" << endl;
        }
    }
    cout << endl;

    cout << "checking list forward...\n";
    cout << "\tThere are " << list.getCount() << " nodes." << endl;
    list.printList();
    cout << endl;

    cout << "checking list backwards...\n";
    cout << "\tThere are " << list.getCount() << " nodes." << endl;
    list.printList(true);
    cout << endl;

    //randomly getting a few nodes
    int getid;
    for (int i = 0; i < 4; i++) {
        getid = testdata.getRandomId();
        cout << "getting " << getid << "... ";
        if (list.getNode(getid, &tmpData)) {
            cout << "found " << tmpData.id << ": " << tmpData.data << endl;
        } else {
            cout << "failed to find " << getid << endl;
        }
    }
    cout << "getting " << MAXID + MAXID << "... ";
    if (list.getNode(MAXID + MAXID, &tmpData)) {
        cout << "found " << tmpData.id << ": " << tmpData.data << endl;
    } else {
        cout << "failed to find " << MAXID + MAXID << endl;
    }
    cout << endl;

    //randomly checking for a few ids
    for (int i = 0; i < 4; i++) {
        getid = testdata.getRandomId();
        cout << "checking for " << getid << "... ";
        if (list.exists(getid)) {
            cout << "found " << getid << endl;
        } else {
            cout << "failed to find " << getid << endl;
        }
    }
    cout << endl;
    
    
    //deleting from the list random ids from the test data
    int delid;
    for (int i = 0; i < numTestData; i++) {
        delid = testdata.getRandomId();
        cout << "deleting " << delid << "... ";
        if (list.deleteNode(delid)) {
            cout << "success" << endl;
        } else {
            cout << "failed" << endl;
        }
    }
    cout << endl;

    cout << "checking list...\n";
    cout << "\tThere are " << list.getCount() << " nodes." << endl;
    list.printList();
    cout << endl;

    cout << "clearing list...";
    list.clearList();
    cout << "done" << endl << endl;

    cout << "checking list...\n";
    cout << "\tThere are " << list.getCount() << " nodes." << endl;
    list.printList();
    cout << endl;


    return 0;
}
