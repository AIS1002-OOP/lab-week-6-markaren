
#include "ais1002/matrix4.hpp"
#include <string>

using namespace ais1002;

matrix4 &matrix4::set(float n11, float n12, float n13, float n14, float n21,
                      float n22, float n23, float n24, float n31, float n32,
                      float n33, float n34, float n41, float n42, float n43,
                      float n44) {

  auto &te = this->elements;

  // clang-format off
    te[ 0 ] = n11; te[ 4 ] = n12; te[ 8 ] = n13; te[ 12 ] = n14;
    te[ 1 ] = n21; te[ 5 ] = n22; te[ 9 ] = n23; te[ 13 ] = n24;
    te[ 2 ] = n31; te[ 6 ] = n32; te[ 10 ] = n33; te[ 14 ] = n34;
    te[ 3 ] = n41; te[ 7 ] = n42; te[ 11 ] = n43; te[ 15 ] = n44;
  // clang-format on

  return *this;
}

float &matrix4::operator[](unsigned int index) {
  if (index >= 16)
    throw std::runtime_error("index out of bounds: " + std::to_string(index));

  return elements[index];
}

float matrix4::operator[](unsigned int index) const {
  if (index >= 16)
    throw std::runtime_error("index out of bounds: " + std::to_string(index));

  return elements[index];
}

matrix4 &matrix4::identity() {
  // clang-format off
  this->set(
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
  );
  // clang-format on
  return *this;
}

matrix4 &matrix4::setPosition(const vector3 &v) {
  this->setPosition(v.x, v.y, v.z);

  return *this;
}

matrix4 &matrix4::setPosition(float x, float y, float z) {
  elements[12] = x;
  elements[13] = y;
  elements[14] = z;

  return *this;
}

bool matrix4::operator==(const matrix4 &m) const {

  const auto &te = this->elements;
  const auto &me = m.elements;

  for (int i = 0; i < 16; i++) {
    if (te[i] != me[i])
      return false;
  }

  return true;
}

std::ostream &ais1002::operator<<(std::ostream &os, const matrix4 &m) {
  // clang-format off
            os << "matrix4(\n" <<
                    m.elements[0] << ", " << m.elements[1] << ", " << m.elements[2] << ", " << m.elements[3] << "\n" <<
                    m.elements[4] << ", " << m.elements[5] << ", " << m.elements[6] << ", " << m.elements[7] << "\n" <<
                    m.elements[8] << ", " << m.elements[9] << ", " << m.elements[10] << ", " << m.elements[11] << "\n" <<
                    m.elements[12] << ", " << m.elements[13] << ", " << m.elements[14] << ", " << m.elements[15] << "\n" <<
                    ")";
  // clang-format on
  return os;
}
