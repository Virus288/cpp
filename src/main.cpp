#include "../include/connections/auth.h"
#include "../include/modules/index.h"
#include "../include/tools/logger.h"

#include <csignal>
#include <thread>
#include <unistd.h>

using std::this_thread::sleep_for;
using namespace std::chrono_literals;

bool stop_flag = false;

void signalHandler(int signum) {
  Logger::log("Received signal to close application.");
  stop_flag = true;
}

int main() {
  Logger::debug("dupa 1");
  Game game;
  Logger::debug("dupa 2");

  std::signal(SIGINT, signalHandler);
  std::signal(SIGTERM, signalHandler);

  Logger::debug("dupa 3");
  game.init(stop_flag);

  while (!stop_flag) {
    sleep_for(1s);
  }

  Logger::log("Cleanup and exiting... \n");
  return 0;
}
