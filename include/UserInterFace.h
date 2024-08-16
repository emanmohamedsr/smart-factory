#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <windows.h>///sleep,color
#include <cstdlib>///system

#include "SmartFactory.h"

class UserInterFace
{
private:
    SmartFactory SF;
public:
    UserInterFace();
    ~UserInterFace();

    void setColor(int color);
    void print(string text, bool newLine = true);
    void separator(int color);
    void Back(int x = 3);

    void SmartFactory_system();
    void Adding();
    void Deleting();
    void Display();
    void SizeInquiry();
};

#endif // USERINTERFACE_H
