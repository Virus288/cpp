#include <iostream>
#include "../include/connections/auth.h"

using std::cin;
using std::cout;

int main() {
    Auth auth;
    string option;

    cout << "Would you like to log in or register ? [login,reg]: \n";
    cin >> option;

    if(option == "login") {
        auth.login();
    } else {
        auth.registerUser();
    }

    return 0;
}

