#include "../../include/connections/communicator.hpp"
#include "../../include/tools/logger.hpp"
#include <string>

using std::string;
using std::to_string;

string baseUrl = "https://api.server.com";

void Communicator::sendGet(string path) {
  Logger::debug("Sending get request to: " + baseUrl + path);

  httplib::Client cli(baseUrl);
  cli.set_ca_cert_path("");
  cli.enable_server_certificate_verification(false);
  auto res = cli.Get(path);

  if (res && res->status == 200) {
    Logger::debug("Got data back from server");
    Logger::debug(res->body);
  } else {
    Logger::debug("Request failed with code " + to_string(res->status) +
                  " and response " + (res ? res->body : "No response"));
  }
}
