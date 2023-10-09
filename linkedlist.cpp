/*********************
* Name: Carter Atnip
* Programming III: Data structures
* logic for LinkedList class
**********************/

#include "linkedlist.h"

/*********************
* Name: LinkedList (Constructor)
* Parameters: None
* Returns: None
* creates the first head node of a linked list by setting it to NULL
**********************/
LinkedList::LinkedList() {
    head = NULL;
}

/*********************
* Name: addNode
* Parameters: id (int) data (string ptr)
* Returns: bool
* adds an element to a linked list in order depending on its id
**********************/
bool LinkedList::addNode(int id, string *data) {
    bool valid_data = true;

    if(!data->empty() && id > -1) {
        if (!head || head->data.id > id) {insertHead(id, data);}

        else {
            Node* current = head;
            while (current->next && current->next->data.id <= id) {current = current->next;}

            if (current->next == NULL && current->data.id != id) {insertTail(id, data, current);}

            else if (current->data.id != id) {insertMiddle(id, data, current);}

            else {
                valid_data = false;
            }
        }
    } else {valid_data = false;}

    return valid_data;
}

/*********************
* Name: insertHead
* Parameters: id (int) data (string ptr)
* Returns: None
* adds an element to a linked lists head
**********************/
void LinkedList::insertHead(int id, string *data) {
    Node *new_element = new Node;
    new_element->data.id = id;
    new_element->data.data = *data;

    new_element->next = head;
    new_element->prev = NULL;

    if (head) {
        head->prev = new_element;
    }

    head = new_element;
}

/*********************
* Name: insertMiddle
* Parameters: id (int) data (string ptr) current (Node ptr)
* Returns: None
* inserts an element into the linked lists middle
**********************/
void LinkedList::insertMiddle(int id, string* data, Node* current) {
    Node *new_element = new Node;
    new_element->data.id = id;
    new_element->data.data = *data;

    new_element->prev = current;
    new_element->next = current->next;

    current->next->prev = new_element;
    current->next = new_element;
}

/*********************
* Name: insertTail
* Parameters: id (int) data (string ptr) current (Node ptr)
* Returns: None
* inserts an element into the linked lists tail
**********************/
void LinkedList::insertTail(int id, string* data, Node* current) {
    Node *new_element = new Node;
    new_element->data.id = id;
    new_element->data.data = *data;

    new_element->prev = current;
    new_element->next = NULL;
    current->next = new_element;
}

/*********************
* Name: deleteNode
* Parameters: id (int
* Returns: bool
* deletes an element from the link list and returns a bool to indicate success
**********************/
bool LinkedList::deleteNode(int id) {
    bool success = true;

    if (head != NULL) {
        Node* current = head;

        while (current->next && current->data.id != id) {
            current = current->next;
        }

        if (id == current->data.id) {

            if (current->prev == NULL) {removeHead(current);}

            else if (current->next == NULL) {removeTail(current);}

            else {removeMiddle(current);}

        } else {success = false;}

    } else {success = false;}

    return success;
}

/*********************
* Name: removeHead
* Parameters: current (Node ptr)
* Returns: None
* deletes element from linked list head
**********************/
void LinkedList::removeHead(Node* current) {
    head = current->next;

    if (head != NULL && head->prev != NULL) {head->prev = NULL;}

    delete current;
}

/*********************
* Name: removeMiddle
* Parameters: current (Node ptr)
* Returns: None
* deletes element from linked list middle
**********************/
void LinkedList::removeMiddle(Node* current) {
    current->next->prev = current->prev;
    current->prev->next = current->next;
    delete current;
}

/*********************
* Name: removeTail
* Parameters: current (Node ptr)
* Returns: None
* deletes element from linked list tail
**********************/
void LinkedList::removeTail(Node* current) {
    current->prev->next = NULL;
    delete current;
}


/*********************
* Name: getNode
* Parameters: id (int), data (Data ptr)
* Returns: bool
* gets an element from the linked list and returns bool to indicate success
**********************/
bool LinkedList::getNode(int id, Data *data) {

    Node* current = head;
    while (current->next && current->data.id != id) {
        current = current->next;
    }

    if (current->data.id == id) {
        *data = current->data;

    } else {
        data->id = UNKNOWNID;
        data->data = UNKNOWNDATA;
    }

    return id == current->data.id;
}

/*********************
* Name: printList
* Parameters: backward (bool, defaults to false)
* Returns: None
* prints all elements in linked list forward and backward depending on bool passed to it, defaults to forward
**********************/
void LinkedList::printList(bool backward) {
    Node* current = head;

    if (backward) {
        bool tail = false;

        while (current && !tail) {
            if (current->next) {
                current = current->next;

            } else {tail = true;}
        }

        while(current){
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->prev;
        }

    } else {
        while (current != NULL) {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->next;
        }
    }
}

/*********************
* Name: getCount
* Parameters: None
* Returns: int
* loops through linked list and returns the amount of elements in it
**********************/
int LinkedList::getCount() {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

/*********************
* Name: clearList
* Parameters: None
* Returns: bool
* loops through linked list, deletes all nodes, and sets head to NULL
**********************/
bool LinkedList::clearList() {

    Node* current;
    while (head != NULL) {
        current = head;
        removeHead(current);
    }

    return head == NULL;
}

/*********************
* Name: exists
* Parameters: id (int)
* Returns: bool
* checks if an element is in the linked list based on the id passed, returns bool when found/not found
**********************/
bool LinkedList::exists(int id) {
    Node* current = head;
    while (current->next && current->data.id != id) {
        current = current->next;
    }

    return current->data.id == id;
}

LinkedList::~LinkedList() {
    clearList();
}


