#include <string>
using std::string;

class Communicator {
public:
  void sendGet(string path);
  static Communicator &getInstance();

private:
  const string baseUrl = "https://api.server.com";
  static Communicator instance;
  Communicator();
  Communicator(Communicator const &);
  void operator=(Communicator const &);
};

#pragma once
