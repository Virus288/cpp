#include "../../include/errors/errors.hpp"
#include "../../include/tools/logger.hpp"
#include <exception>
#include <functional>
#include <string>

using std::exception;
using std::function;
using std::string;

void Errors::catcher(function<void()> func) {
  try {
    func();
  } catch (const exception &e) {
    Logger::error("Error: " + string(e.what()));
  } catch (...) {
    Logger::error("Unknown error occurred.");
  }
}
