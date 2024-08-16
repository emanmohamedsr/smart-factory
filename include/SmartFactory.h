#ifndef SMARTFACTORY_H
#define SMARTFACTORY_H

#include "Product.h"
#include "SubLinkedListAsQueue.h"

class SmartFactory
{
private:
    SubLinkedListAsQueue<Product> QueueSubList;
public:
    SmartFactory();
    ~SmartFactory();

    void addProduct();
    bool removeProduct();
    bool displayProducts();

    size_t NumberOfProducts();

};

#endif // SMARTFACTORY_H
