#include "movement/movement.h"
#include <iostream>

using std::cin;
using std::cout;

int main() {
    Movement movement;
    int input = 1;

    while (input > 0 && input <=4) {
        cout << "Where do you want to go [1,2,3,4]: \n";
        cin >> input;

        switch (input) {
            case 1:
            movement.move("West");
            break;
            case 2:
            movement.move("Nort");
            break;
            case 3:
            movement.move("East");
            break;
            case 4:
            movement.move("South");
            break;
        }
    }

    return 0;
}

