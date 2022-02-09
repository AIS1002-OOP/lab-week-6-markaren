#include <algorithm>
#include <numeric>

#include "ais1002/exercises/exercise1.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace ais1002;

namespace {


// Class used to produced high quality random numbers
class random_generator {

public:
  random_generator(int min, int max) : dev(), gen(dev()), dis(min, max) {}

  // Generates and returns new random number when invoked
  int operator()() { return dis(gen); }

private:
  std::random_device dev;
  std::mt19937 gen;
  std::uniform_int_distribution<> dis;
};

}

TEST_CASE("1: multiplyDoubles doubles") {
  random_generator rng(-100, 100);
  double a = rng(); // a in the range -100 to 100
  double b = rng(); // b in the range -100 to 100
  REQUIRE(ais1002::multiplyDoubles(a, b) == Approx(a * b));
}

TEST_CASE("2: compute sum") {
  const int num = 50;
  std::vector<int> list(num);
  random_generator rng(0, 100);
  for (int i = 0; i < num; i++) {
    list.push_back(rng()); // element in the range 0 to 100
  }

  auto sum = std::accumulate(list.begin(), list.end(), 0);
  REQUIRE(sum == ais1002::computeSum(list));
}

TEST_CASE("3: count elements") {
  const int num = 100;
  std::vector<double> list(num);
  random_generator rng(0, 100);
  for (int i = 0; i < num; i++) {
    list.push_back(rng()); // element in the range 0 to 100
  }

  auto count = std::count_if(list.begin(), list.end(),
                             [](double value) { return value < 50; });
  REQUIRE(count == ais1002::countValuesBelowThreshold(list));
}

TEST_CASE("4: Capitalize string") {
  std::vector<std::string> names{"per",   "ola", "nils",   "conny",
                                 "tonje", "kim", "torhild"};
  auto rd = std::random_device{};
  auto rng = std::default_random_engine{rd()};
  std::shuffle(std::begin(names), std::end(names), rng);

  std::string name = names.front();
  ais1002::capitalizeString(name);

  std::string answer = names.front();
  answer[0] = static_cast<char>(toupper(answer[0]));
  REQUIRE(name == answer);
}

TEST_CASE("5: Convert object") {

  std::vector<std::pair<std::string, int>> list{
      {"Per", 44}, {"Ole", 25}, {"Tomine", 19}, {"Gerd", 67}};

  auto m = ais1002::convert(list);
  for (auto &elem : list) {
    REQUIRE(elem.second == m[elem.first]);
  }
}
