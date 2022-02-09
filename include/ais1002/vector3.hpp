
#ifndef AIS1002_LAB_WEEK_6_VECTOR3_HPP
#define AIS1002_LAB_WEEK_6_VECTOR3_HPP

#include <ostream>
#include "matrix4.hpp"

namespace ais1002 {

class matrix4; //forward reference

class vector3 {

public:
  float x{0.f};
  float y{0.f};
  float z{0.f};

  vector3() = default;

  vector3(float x, float y, float z);

  vector3 operator + (const vector3& v) const;

  vector3 operator - (const vector3& v) const;

  vector3 operator * (const vector3& v) const;

  vector3 operator / (const vector3& v) const;

  vector3 &set(float x, float y, float z);

  vector3 &applyMatrix4(const matrix4 &m);
  
  float dot(const vector3 &v) const;
  
  float lengthSq() const;

  float length() const;

  float distanceTo(const vector3 &v) const;

  float distanceToSquared(const vector3 &v) const;

  vector3 &setFromMatrixPosition(const matrix4 &m);

  bool operator == (const vector3& v) const;

  friend std::ostream &operator<<(std::ostream &, const vector3 &);
};

} // namespace ais1002

#endif // AIS1002_LAB_WEEK_6_VECTOR3_HPP
