/* 
 * File: data.h
 * Author: Alex Katrompas
 * 
 * DO NOT MODIFY THIS FILE
 * LEAVE THIS COMMENT HEADER HERE
 */

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */

