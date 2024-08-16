#ifndef SUBLINKEDLISTNODE_H
#define SUBLINKEDLISTNODE_H


#include <iostream>
#include <string>
#include <stdexcept>

#include "Stack.h"
using namespace std;

//----------SUB-LINKED-LIST NODE-----------

template<typename T>
class SubLinkedListNode
{
public:
    T* nodes;
    size_t nodeSize;
    static size_t capacity;
    SubLinkedListNode* next;
public:
    SubLinkedListNode();
    ~SubLinkedListNode();
};

template<typename T>
size_t SubLinkedListNode<T>::capacity = 3;

template<typename T>
SubLinkedListNode<T>::SubLinkedListNode() : nodeSize(0), next(nullptr) {
    nodes = new T[3];
}

template<typename T>
SubLinkedListNode<T>::~SubLinkedListNode() {
    delete[] nodes;
}

#endif // SUBLINKEDLISTNODE_H
