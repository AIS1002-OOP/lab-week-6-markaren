
#include "ais1002/exercises/exercise4.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace ais1002;

TEST_CASE("1: Distance between vectors") {

  vector3 v1{0, 10, 0};
  vector3 v2{-10, 10, 0};

  float distance = v1.distanceTo(v2);
  REQUIRE(distance == distanceBetween(v1, v2));
}

TEST_CASE("2: Get position from matrix") {
  vector3 answer{1, 2, 3};
  matrix4 m;
  m.setPosition(answer);
  vector3 v = getPosition(m);

  REQUIRE(answer == v);
}

TEST_CASE("3: Make translation matrix") {
  vector3 v{1, 1, 1};
  matrix4 m = makeTranslationMatrix(v);
  matrix4 answer;
  answer.setPosition(v);

  REQUIRE(answer == m);
}
