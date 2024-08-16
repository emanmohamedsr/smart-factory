
#include "UserInterFace.h"


int main() {

    UserInterFace UI;
    int choice;

    while (true) {

        UI.SmartFactory_system();
        cin >> choice;
        UI.separator(13);

        switch (choice) {
        case 1:  //add
            UI.Adding();
            break;
        case 2:  //size
            UI.SizeInquiry();
            break;
        case 3:  //remove
            UI.Deleting();
            break;
        case 4:  //show
            UI.Display();
            break;
        case 0:  //exit
            UI.print("Thank you, Hope I Have Helped \x03");
            return 0;
        default:
            UI.print("Invalid Choice, Try Again");
            UI.separator(13);
            UI.Back(3);
        }
    }
}
