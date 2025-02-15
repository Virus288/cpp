#include "../../include/connections/auth.h"
#include "../../include/external/httplib.h"
#include "../../include/tools/logger.h"

#include <cstdlib>

using std::cout;
using std::string;
using std::system;

void Auth::login() {
  std::string login_url = "https://api.server.com/user/login?client=login";
  Logger::debug("Opening browser in login");
  std::system(
      ("xdg-open " + login_url).c_str()); // Linux. Add option for windows
};

void Auth::registerUser() {
  std::string login_url =
      "https://api.server.com/user/register/start?client=register";
  Logger::debug("Opening browser in register");
  std::system(
      ("xdg-open " + login_url).c_str()); // Linux. Add option for windows
};

void Auth::startServer() {
  server_ = std::make_unique<httplib::Server>();

  server_->Get("/login",
               [this](const httplib::Request &req, httplib::Response &res) {
                 Logger::debug("Got request on callback");

                 // Print all headers
                 cout << "Headers:" << std::endl;
                 for (const auto &header : req.headers) {
                   cout << header.first << ": " << header.second << std::endl;
                 }

                 this->isAuthenticated = true;
               });

  Logger::log("Server started on http://localhost:3003 \n");
  server_->listen("127.0.0.1", 3003);
}

void Auth::stopServer() { server_->stop(); }
