
#include "ais1002/exercises/exercise3.hpp"
#include <filesystem>
#include <fstream>
#include <string>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace ais1002;

namespace {

  std::string readFile(const std::filesystem::path& p) {
    std::ifstream file(p);
    std::stringstream ss;
    for (std::string tmp; std::getline(file, tmp);) {
      ss << tmp << "\n";
    }
    return ss.str();
  }

}

TEST_CASE("1: Read file") {

  std::filesystem::path p{"data/hello.txt"};

  auto answer = readFile(p);
  auto read = ais1002::readTextFile(p);
  REQUIRE(answer == read);
}

TEST_CASE("2: Write file") {

  std::filesystem::path p{"data/hello_out.txt"};

  std::string data{"AIS1002 - OOP & Algoritmer\n"};

  std::ofstream file(p);
  file << data;
  file.close();

  auto read = readFile(p);
  REQUIRE(data == read);
}
