#include "UserInterFace.h"

UserInterFace::UserInterFace() {}
UserInterFace::~UserInterFace() {}

void UserInterFace::setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void UserInterFace::print(string text, bool newLine)
{
    cout << text << (newLine ? "\n" : " ");
}

void UserInterFace::separator(int color)
{
    int x = 80;
    setColor(color);
    for (auto i = 0; i < x; ++i)
    {
        cout << "_";
    }
    setColor(15);
    cout << endl;
}

void UserInterFace::Back(int x)
{
    cout << "\t\t";
    for (auto i = 0; i < x; ++i)
    {
        cout << ". ";
        Sleep(400);
    }
}

void UserInterFace::SmartFactory_system()
{
    system("cls");
    setColor(13);
    print("\t\tWELCOME TO OUR SMART FACTORY SYSTEM");
    print("\t\t___________________________________\n");
    setColor(15);
    print("HOW CAN WE HELP YOU \x03 ....");
    print("1) ADDING ");
    print("2) SIZE INQUIRY");
    print("3) REMOVING ");
    print("4) REPORTING ");
    print("0) CLOSE ");
    print("YOUR CHOICE! ", false);
}

void UserInterFace::Adding() {
    system("cls");
    setColor(9);
    cout << "\t\tADDING " << endl
        << "\t\t______ " << endl;
    setColor(15);

    SF.addProduct();
    cout << "SUCCESS ;)" << endl;

    separator(9);
    Back(3);
}

void UserInterFace::Deleting() {
    system("cls");
    setColor(12);
    cout << "\t\tREMOVING " << endl
        << "\t\t________" << endl;
    setColor(15);

    if (!SF.removeProduct())
        cout << "Empty, What about adding some products first :)" << endl;
    else
        cout << "SUCCESS ;)" << endl;

    separator(12);
    Back(3);
}

void UserInterFace::Display() {
    system("cls");
    setColor(14);
    cout << "\t\tREPORTING" << endl
        << "\t\t_________" << endl;
    setColor(15);

    if (!SF.displayProducts())
        cout << "Empty, What about adding some products first :)" << endl;
    else
        cout << "SUCCESS ;)" << endl;

    separator(14);
    system("pause");
}

void UserInterFace::SizeInquiry() {

    size_t Size = SF.NumberOfProducts();
    if (!Size)
        cout << "Still Empty" << endl;
    else
        cout << "Number of Products: " << Size << endl;

    separator(13);
    Back(3);
}
