#include "../include/connections/auth.hpp"
#include "../include/errors/errors.hpp"
#include "../include/modules/index.hpp"
#include "../include/tools/logger.hpp"

#include <csignal>
#include <optional>
#include <string>
#include <thread>
#include <unistd.h>

using std::this_thread::sleep_for;
using namespace std::chrono_literals;
using std::optional;
using std::string;

bool stop_flag = false;

void signalHandler(int signum) {
  Logger::log("Received signal to close application.");

  stop_flag = true;
}

int start() {
  Game game;

  std::signal(SIGINT, signalHandler);
  std::signal(SIGTERM, signalHandler);

  game.init(stop_flag);

  while (!stop_flag) {
    sleep_for(1s);
  }

  Logger::log("Cleanup and exiting... \n");
  return 0;
}

int main() {
  optional<int> result = Errors::catcher<int>([&]() { return start(); });

  return 1;
}
