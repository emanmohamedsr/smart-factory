#ifndef STACK_H
#define STACK_H


#include <iostream>
#include <string.h>
#include <stdexcept>

using namespace std;

//-------------STACK--------------

template<typename T>
struct stackNode {
	T data;
	stackNode* next;
	stackNode() :next(nullptr) {}
	stackNode(T d) :data(d), next(nullptr) {}
};

template<typename T>
class Stack {
protected:
	stackNode<T>* top;
	size_t stackSize;
public:

	Stack();
	~Stack();
	void destroyStack();

	void push(const T& val);
	T pop();
	T peek();

	size_t getSize() const;
	bool isEmpty() const;
	bool isFull() const;

};


template<typename T>
Stack<T>::Stack() : stackSize(0), top(nullptr)
{
}

template<typename T>
Stack<T>::~Stack()
{
	stackNode<T>* temp;
	while (top) {
		temp = top->next;
		top = top->next;
		top = temp;
	}
	stackSize = 0;
}

template<typename T>
void Stack<T>::destroyStack()
{
	stackNode<T>* temp;
	while (top) {
		temp = top->next;
		top = top->next;
		top = temp;
	}
	stackSize = 0;
}

template<typename T>
void Stack<T>::push(const T& val)
{
	stackNode<T>* newnode = new stackNode<T>(val);
	newnode->next = top;
	top = newnode;
	stackSize++;
}

template<typename T>
T Stack<T>::pop()
{
	if (!top)
		throw out_of_range("UnderFlow!!");
	T holder = top->data;
	stackNode<T>* temp = top;
	top = top->next;
	delete temp;
	stackSize--;
	return holder;
}

template<typename T>
T Stack<T>::peek()
{
	if (!top)
		throw out_of_range("UnderFlow!!");
	T holder = top->data;
	return holder;

}

template<typename T>
size_t Stack<T>::getSize() const
{
	return stackSize;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
	return !top;
}

template<typename T>
bool Stack<T>::isFull() const
{
	return false;
}

#endif // STACK_H
