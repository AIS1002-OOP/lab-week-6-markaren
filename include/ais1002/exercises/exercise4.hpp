
#ifndef AIS1002_LAB_WEEK_6_EXERCISE4_HPP
#define AIS1002_LAB_WEEK_6_EXERCISE4_HPP

#include "../matrix4.hpp"

namespace ais1002 {

double distanceBetween(const vector3 &v1, const vector3 &v2) {
  return v1.distanceTo(v2);
}

vector3 getPosition(const matrix4 &m) {
  vector3 v;
  v.setFromMatrixPosition(m);
  return v;
}

matrix4 makeTranslationMatrix(const vector3 &v) {
  return matrix4().setPosition(v);
}

} // namespace ais1002

#endif // AIS1002_LAB_WEEK_6_EXERCISE4_HPP
