#include "utils.hpp"
#include <fstream>

namespace beast = boost::beast;
namespace http = beast::http;

std::string read_file(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) return "";
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

http::response<http::string_body> handle_request(const http::request<http::string_body>& req) {
  http::response<http::string_body> res;

  res.version(req.version());
  res.keep_alive(false);

  res.set(http::field::server, "http-beastie");
  res.set(http::field::content_type, "text/html");

 if (req.method() == http::verb::get) {
    if (req.target() == "/") {
        res.result(http::status::ok);
        res.body() = read_file("static/index.html");
    }

    else if (req.target() == "/sulieman") {
        res.result(http::status::ok);
        res.body() = read_file("static/sulieman.html");
    }
    else {
        res.result(http::status::not_found);
        res.body() = "<h1>404 Not Found</h1>";
    }
}

  res.prepare_payload();
  return res;
}

