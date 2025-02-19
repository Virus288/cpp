#include "../../include/connections/auth.hpp"
#include "../../include/external/httplib.hpp"
#include "../../include/tools/logger.hpp"

#include <cstdlib>
#include <fstream>
#include <optional>

using std::ifstream;
using std::nullopt;
using std::ofstream;
using std::string;
using std::system;

Auth::Auth() {
  Logger::debug("Auth instance created.");
  server_ = std::make_unique<httplib::Server>();
}

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
  server_->Get("/login",
               [this](const httplib::Request &req, httplib::Response &res) {
                 Logger::debug("Got request on callback");

                 string cookie_header = req.headers.find("cookie")->second;

                 // Now parse the cookie value
                 string token;
                 string key = "authClient.token=";
                 size_t pos = cookie_header.find(key);
                 if (pos != string::npos) {
                   pos += key.length();
                   size_t end = cookie_header.find(";", pos);
                   token = cookie_header.substr(pos, end - pos);
                 }

                 saveToken(token);
                 this->isAuthenticated = true;
               });

  Logger::log("Server started on http://localhost:3003 \n");
  server_->listen("127.0.0.1", 3003);
}

void Auth::stopServer() { server_->stop(); }

void Auth::saveToken(string token) {
  ofstream config_file;
  Logger::debug("Saving token to file");
  config_file.open("./config.txt");
  config_file << token << "\n";
  config_file.close();
}

optional<string> Auth::readToken() {
  ifstream config_file;
  string token = "";
  config_file.open("./config.txt");
  config_file >> token;
  config_file.close();

  if (token != "") {
    return token;
  } else {
    return nullopt;
  }
}

bool Auth::isAuthorized() {
  const optional<string> token = readToken();
  return token.has_value();
}
