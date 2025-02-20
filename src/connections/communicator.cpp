#include "../../include/connections/communicator.hpp"
#include "../../include/external/httplib.hpp"
#include "../../include/tools/logger.hpp"
#include <stdexcept>
#include <string>

using std::runtime_error;
using std::string;
using std::to_string;

Communicator Communicator::instance = Communicator();

Communicator::Communicator() {}

void Communicator::sendGet(string path) {
  Logger::debug("Sending get request to: " + this->baseUrl + path);

  httplib::Client cli(this->baseUrl);

  // Ignore invalid ssl cert. Disable it later
  cli.set_ca_cert_path("");
  cli.enable_server_certificate_verification(false);
  auto res = cli.Get(path);

  if (!res) {
    Logger::error("Request failed: No response from server");
    throw runtime_error("No response from server");
  }

  if (res->status == 200) {
    Logger::debug("Got data back from server");
    Logger::debug(res->body);
  } else {
    Logger::debug("Request failed with code " + to_string(res->status) +
                  " and response " + (res ? res->body : "No response"));
  }
}

Communicator &Communicator::getInstance() { return Communicator::instance; }
