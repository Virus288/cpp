#include "../../include/tools/logger.hpp"
#include <exception>
#include <functional>

class Errors {
public:
  static void catcher(std::function<void()> func);

  template <typename T> static T catcher(std::function<T()> func) {
    try {
      return func();
    } catch (const std::exception &e) {
      Logger::error("Error: " + std::string(e.what()));
    } catch (...) {
      Logger::error("Unknown error occurred.");
    }
    return T();
  }
};

#pragma once
