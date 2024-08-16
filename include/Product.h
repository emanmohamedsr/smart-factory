#ifndef PRODUCT_H
#define PRODUCT_H

#include "Stack.h"

class Product : public Stack<string>
{
public:
    Product();
    ~Product();

    void getProduct();

    friend ostream& operator<<(ostream& out, const Product& p);

};

#endif // PRODUCT_H
