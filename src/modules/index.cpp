#include "../../include/modules/index.hpp"
#include "../../include/connections/auth.hpp"
#include "../../include/connections/communicator.hpp"
#include "../../include/errors/errors.hpp"
#include "../../include/tools/logger.hpp"

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
  const bool isAuthorized = auth_->isAuthorized();
  if (isAuthorized) {
    Logger::log("User is authorized");
    stop_flag = true;
    auth_->stopServer();

    getUser();
  } else {
    // Start server on another tread
    std::thread serverThread([this]() { this->auth_->startServer(); });

    auth();

    while (!auth_->isAuthenticated) {
      sleep_for(1s);
    }

    Logger::log("Authentication successful. Exiting");

    auth_->stopServer();
    stop_flag = true;
    serverThread.join();
  }
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

void Game::getUser() {
  Communicator &name = Communicator::getInstance();

  Errors::catcher([&]() {
    return name.sendGet("/users/details"); // Send GET request
  });
}
