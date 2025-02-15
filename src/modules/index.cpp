#include "../../include/modules/index.h"
#include "../../include/connections/auth.h"
#include "../../include/tools/logger.h"

#include <csignal>
#include <thread>
#include <unistd.h>

using std::cin;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

Game::Game() {
  Logger::debug("Game instance created.");
  auth_ = std::make_unique<Auth>();
}

void Game::init(bool &stop_flag) {
  Logger::debug("dupa 4");

  // Start server on another tread
  std::thread serverThread([this]() { this->auth_->startServer(); });

  Logger::debug("dupa 5");
  auth();

  while (!auth_->isAuthenticated) {
    sleep_for(1s);
  }

  Logger::log("Authentication successful. Exiting");

  auth_->stopServer();
  stop_flag = true;
  serverThread.join();
};

void Game::auth() {
  string option;

  Logger::log("Would you like to log in or register ? [login,reg]: ");
  cin >> option;

  if (option == "login") {
    auth_->login();
  } else {
    auth_->registerUser();
  }

  Logger::log("Waiting for authentication...");
}
