#include "../../include/connections/auth.h"
#include "../../include/external/httplib.h"

using std::system;
using std::string;
using std::cout;

void Auth::login() {
    std::string login_url = "https://api.server.com/user/login?client=login";
    std::system(("xdg-open " + login_url).c_str());  // Linux. Add option for windows
};

void Auth::registerUser() {
    std::string login_url = "https://api.server.com/user/register/start?client=register";
    std::system(("xdg-open " + login_url).c_str());  // Linux. Add option for windows
};

void Auth::startServer() {
    httplib::Server server;

    server.Get("/callback", [](const httplib::Request &req, httplib::Response &res) {
        cout << "Got request back" << std::endl;

        // Print all headers
        cout << "Headers:" << std::endl;
        for (const auto &header : req.headers) {
            cout << header.first << ": " << header.second << std::endl;
        }

        res.set_content("Logged in successfully!", "text/plain");
    });

    server.listen("localhost", 8080);
}

