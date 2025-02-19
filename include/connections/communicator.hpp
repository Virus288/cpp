#include "../external/httplib.hpp"

#include <memory>
#include <optional>
#include <string>

using std::optional;
using std::string;

class Communicator {
public:
  void static sendGet(string path);
};

#pragma once
