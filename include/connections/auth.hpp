#include "../external/httplib.hpp"

#include <memory>
#include <optional>
#include <string>

using std::optional;
using std::string;

class Auth {
public:
  Auth();
  void registerUser();
  void login();
  void stopServer();
  void startServer();
  void saveToken(string token);
  optional<string> readToken();
  bool isAuthorized();
  bool isAuthenticated;

private:
  std::unique_ptr<httplib::Server>
      server_; // This creates a pointer for server instance, shared between
               // methods in this class ?
};

#pragma once
