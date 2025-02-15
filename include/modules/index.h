#include "../connections/auth.h"
#include <memory>
#include <string>

using std::string;
using std::unique_ptr;

class Game {
public:
  Game();
  void init(bool &stop_flag);
  void auth();

private:
  unique_ptr<Auth> auth_;
};

#pragma once
