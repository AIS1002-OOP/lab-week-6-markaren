
#include "ais1002/vector3.hpp"

#include <cmath>

using namespace ais1002;

vector3::vector3(float x, float y, float z) : x(x), y(y), z(z) {}

vector3 &vector3::set(float x, float y, float z) {

  this->x = x;
  this->y = y;
  this->z = z;

  return *this;
}

vector3 vector3::operator+(const vector3 &v) const {
  return {x + v.x, y + v.y, z + v.z};
}

vector3 vector3::operator-(const vector3 &v) const {
  return {x - v.x, y - v.y, z - v.z};
}

vector3 vector3::operator*(const vector3 &v) const {
  return {x * v.x, y * v.y, z * v.z};
}

vector3 vector3::operator/(const vector3 &v) const {
  return {x / v.x, y / v.y, z / v.z};
}

vector3 &vector3::applyMatrix4(const matrix4 &m) {
  const auto x_ = this->x, y_ = this->y, z_ = this->z;

  this->x = m[0] * x_ + m[3] * y_ + m[6] * z_;
  this->y = m[1] * x_ + m[4] * y_ + m[7] * z_;
  this->z = m[2] * x_ + m[5] * y_ + m[8] * z_;

  return *this;
}

float vector3::dot(const vector3 &v) const {
  return x * v.x + y * v.y + z * v.z;
}

float vector3::lengthSq() const { return x * x + y * y + z * z; }

float vector3::length() const { return std::sqrt(x * x + y * y + z * z); }

float vector3::distanceTo(const vector3 &v) const {
  return std::sqrt(distanceToSquared(v));
}

float vector3::distanceToSquared(const vector3 &v) const {
  const auto dx = this->x - v.x, dy = this->y - v.y, dz = this->z - v.z;

  return dx * dx + dy * dy + dz * dz;
}
vector3 &vector3::setFromMatrixPosition(const matrix4 &m) {

  this->x = m[12];
  this->y = m[13];
  this->z = m[14];

  return *this;
}

bool vector3::operator==(const vector3 &v) const {
  return ((v.x == this->x) && (v.y == this->y) && (v.z == this->z));
}

std::ostream &ais1002::operator<<(std::ostream &os, const vector3 &v) {
  os << "vector3(x=" << v.x << ", y=" << v.y << ", z=" << v.z << ")";
  return os;
}