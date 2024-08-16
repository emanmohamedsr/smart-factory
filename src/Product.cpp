#include "Product.h"

Product::Product() {}

Product::~Product() {}

ostream& operator<<(ostream& out, const Product& p)
{
    size_t counter = p.getSize();
    stackNode<string>* temp = p.top;
    while (temp) {
        out << "[" << counter-- << "] " << temp->data << endl;
        temp = temp->next;
    }
    return out;
}

void Product::getProduct()
{
    int n;
    cout << "Enter Number Of Operations: ";
    cin >> n;
    string op;
    for (int i = 0; i < n; i++) {
        cout << "-> Operation " << "(" << i + 1 << ")" << " Information: ";
        cin >> op;
        push(op);
    }
}

