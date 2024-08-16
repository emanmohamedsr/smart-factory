#ifndef SUBLINKEDLISTASQUEUE_H
#define SUBLINKEDLISTASQUEUE_H

#include "SubLinkedListNode.h"

//----------SUB-LINKED-LIST AS QUEUE-------------------

template<typename T>
class SubLinkedListAsQueue : public SubLinkedListNode<T>
{
private:
    SubLinkedListNode<T>* head;
    SubLinkedListNode<T>* tail;
    size_t queueSize;
    static size_t enQueueCounter;
    static size_t deQueueCounter;

public:
    SubLinkedListAsQueue();
    ~SubLinkedListAsQueue();

    void enQueue(T val);
    void deQueue();
    T* peek() const;
    void displayQueue();
    size_t getSize() const;
    bool isEmpty() const;
    bool isFull() const;
};

template<typename T>
size_t SubLinkedListAsQueue<T>::deQueueCounter = 0;

template<typename T>
size_t SubLinkedListAsQueue<T>::enQueueCounter = 0;

template<typename T>
SubLinkedListAsQueue<T>::SubLinkedListAsQueue() : head(nullptr), tail(nullptr), queueSize(0) {}

template<typename T>
SubLinkedListAsQueue<T>::~SubLinkedListAsQueue() {
    SubLinkedListNode<T>* temp;
    while (head) {
        temp = head->next;
        delete (head);
        head = temp;
    }
    tail = nullptr;
    queueSize = 0;
}

template<typename T>
void SubLinkedListAsQueue<T>::enQueue(T val) {
    if (!(enQueueCounter % SubLinkedListNode<T>::capacity)) {
        enQueueCounter = 0;
        SubLinkedListNode<T>* newsubList = new SubLinkedListNode<T>();
        if (!head) {
            head = tail = newsubList;
        }
        else {
            tail->next = newsubList;
            tail = newsubList;
        }
    }
    tail->nodes[enQueueCounter++] = val;
    queueSize++;
}

template<typename T>
void SubLinkedListAsQueue<T>::deQueue()
{
    if (isEmpty())
        throw std::out_of_range("UnderFlow!!");

    deQueueCounter++;
    head->nodeSize--;
    queueSize--;

    if (deQueueCounter >= SubLinkedListNode<T>::capacity) {
        SubLinkedListNode<T>* temp = head;
        head = head->next;
        delete temp;
        deQueueCounter = 0;

        if (!head) {
            tail = nullptr;
        }
    }
}



template<typename T>
T* SubLinkedListAsQueue<T>::peek() const
{
    if (isEmpty())
        throw std::out_of_range("UnderFlow!!");
    T* holder = &(head->nodes[deQueueCounter]);
    return holder;
}

template<typename T>
void SubLinkedListAsQueue<T>::displayQueue()
{
    if (isEmpty())
        throw out_of_range("UnderFlow!!");
    SubLinkedListNode<T>* temp = head;
    size_t start = deQueueCounter;
    for (size_t i = 0; i < queueSize; i++) {
        cout << temp->nodes[start] << endl;
        start = ((start + 1) % SubLinkedListNode<T>::capacity);
        if (!start && temp->next)
            temp = temp->next;
    }
}

template<typename T>
size_t SubLinkedListAsQueue<T>::getSize() const {
    return queueSize;
}

template<typename T>
bool SubLinkedListAsQueue<T>::isEmpty() const {
    return !queueSize;
}

template<typename T>
bool SubLinkedListAsQueue<T>::isFull() const {
    return false;
}


#endif // SUBLINKEDLISTASQUEUE_H
