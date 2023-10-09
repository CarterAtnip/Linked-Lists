/*********************
* Name: Carter Atnip
* Programming III: Data structures
* header file for doubly linked list
**********************/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "iostream"
#include "data.h"
#include "string"

#define UNKNOWNID (-1)
#define UNKNOWNDATA ""

using std::string;


class LinkedList {
public:
    LinkedList(); // constructor

    bool addNode(int, string*);

    bool deleteNode(int);

    bool getNode(int, Data*);

    void printList(bool = false);

    int getCount();

    bool clearList();

    bool exists(int);

    ~LinkedList(); // destructor

private:
    // inserting node helper methods
    void insertHead(int, string*);

    void insertMiddle(int, string*, Node*);

    void insertTail(int, string*, Node*);

    // removing node helper methods
    void removeHead(Node*);

    void removeMiddle(Node*);

    void removeTail(Node*);

    //attributes
    Node *head;
};

#endif //LINKEDLIST_H