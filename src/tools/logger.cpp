#include "../../include/tools/logger.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

using std::cout;

string getDate() {
  auto now = std::chrono::system_clock::now();

  std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
  std::tm local_time = *std::localtime(&now_time_t);
  std::ostringstream oss;
  oss << std::put_time(&local_time, "%a %b %d %H:%M:%S %Y");

  return oss.str();
}

string exitCode = "\033[0m";

void Logger::error(string log) {
  string startCode = "\x1B[31m";
  cout << (getDate() + startCode + " [Error]: " + exitCode + log + "\n");
};

void Logger::log(string log) {
  string startCode = "\x1B[32m";
  cout << (getDate() + startCode + " [Log]: " + exitCode + log + "\n");
}

void Logger::warning(string log) {
  string startCode = "\x1B[33m";
  cout << (getDate() + startCode + " [Warning]: " + exitCode + log + "\n");
}

void Logger::debug(string log) {
  string startCode = "\x1B[35m";
  cout << (getDate() + startCode + " [Debug]: " + exitCode + log + "\n");
}
