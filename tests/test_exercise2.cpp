
#include "ais1002/exercises/exercise2.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("1: Generate random number in range") {

  int num = 100;
  double min = 10;
  double max = 100;
  std::vector<double> v = ais1002::generateRandomNumbersInRange(num, min, max);

  REQUIRE(!v.empty());

  double min_found = *std::min_element(v.begin(), v.end());
  double max_found = *std::max_element(v.begin(), v.end());

  REQUIRE(min <= min_found);
  REQUIRE(max >= max_found);

  double sum = std::accumulate(v.begin(), v.end(), 0.0);
  REQUIRE(sum > (min * num));
  REQUIRE(sum < (max * num));
}
