#include <string>

using std::string;

class Logger {
public:
  void static log(string log);
  void static debug(string log);
  void static warning(string log);
  void static error(string log);
};

#pragma once
