#include "SmartFactory.h"

SmartFactory::SmartFactory() {}

SmartFactory::~SmartFactory() {}

void SmartFactory::addProduct() {
    Product p;
    p.getProduct();
    QueueSubList.enQueue(p);
}
bool SmartFactory::removeProduct() {
    if (QueueSubList.isEmpty())
        return 0;
    QueueSubList.deQueue();
    return 1;
}
bool SmartFactory::displayProducts() {
    if (QueueSubList.isEmpty())
        return 0;
    QueueSubList.displayQueue();
    return 1;
}
size_t SmartFactory::NumberOfProducts() {
    return QueueSubList.getSize();
}
