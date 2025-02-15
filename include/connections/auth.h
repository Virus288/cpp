#include "../external/httplib.h"
#include <memory>
#include <string>

using std::string;

class Auth {
public:
  void registerUser();
  void login();
  void stopServer();
  void startServer();
  bool isAuthenticated;

private:
  std::unique_ptr<httplib::Server>
      server_; // This creates a pointer for server instance, shared between
               // methods in this class ?
};

#pragma once
