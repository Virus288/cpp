#include "../include/connections/auth.h"
#include "../include/tools/logger.h"
#include <iostream>
#include <thread>

using std::cin;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

int main() {
  Auth auth;
  string option;

  // Start server on another tread
  std::thread serverThread([&auth]() { auth.startServer(); });

  Logger::log("Would you like to log in or register ? [login,reg]: \n");
  cin >> option;

  if (option == "login") {
    auth.login();
  } else {
    auth.registerUser();
  }

  Logger::log("Waiting for authentication... \n");
  while (!auth.isAuthenticated) {
    sleep_for(1s);
  }

  Logger::log("Authentication successful. Exiting \n");

  auth.stopServer();
  serverThread.join();
  return 0;
}
