#include <vec3.hpp>

#include <cassert>
#include <cmath>

vec3::vec3(const float x, const float y, const float z)
    : data {x, y, z} {}

f32 vec3::dot(const vec3& a, const vec3& b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

vec3 vec3::cross_product(const vec3& a, const vec3& b) {
    return vec3 {
        (a[1] * b[2] - a[2] * b[1]),
        (a[2] * b[0] - a[0] * b[2]),
        (a[0] * b[1] - a[1] * b[0])};
}

void vec3::normalise() {
  float mag = magnitude();

  if (0.0f == mag) {
      (*this) = {0.0f, 0.0f, 0.0f};
  } else {
      (*this) /= magnitude();
  }
}

f32 vec3::magnitude() const {
    return sqrtf(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]);
}

f32 vec3::operator[](const uint32_t index) const {
    assert(index < 3);
    return data[index];
}

f32& vec3::operator[](const uint32_t index) {
    assert(index < 3);
    return data[index];
}

vec3 vec3::operator+=(const vec3& rhs) {
    data[0] += rhs.data[0];
    data[1] += rhs.data[1];
    data[2] += rhs.data[2];
    return *this;
}

vec3 vec3::operator-=(const vec3& rhs) {
    data[0] -= rhs.data[0];
    data[1] -= rhs.data[1];
    data[2] -= rhs.data[2];
    return *this;
}

vec3 vec3::operator/=(const vec3& rhs) {
    data[0] /= rhs.data[0];
    data[1] /= rhs.data[1];
    data[2] /= rhs.data[2];
    return *this;
}

vec3 vec3::operator*=(const vec3& rhs) {
    data[0] *= rhs.data[0];
    data[1] *= rhs.data[1];
    data[2] *= rhs.data[2];
    return *this;
}

vec3 operator+(vec3 lhs, const vec3& rhs) {
    lhs += rhs;
    return lhs;
}

vec3 operator-(vec3 lhs, const vec3& rhs) {
    lhs -= rhs;
    return lhs;
}

vec3 operator*(vec3 lhs, const vec3& rhs) {
    lhs *= rhs;
    return lhs;
}

vec3 operator/(vec3 lhs, const vec3& rhs) {
    lhs /= rhs;
    return lhs;
}

vec3 vec3::operator+=(const f32 rhs) {
    data[0] += rhs;
    data[1] += rhs;
    data[2] += rhs;
    return *this;
}

vec3 vec3::operator-=(const f32 rhs) {
    data[0] -= rhs;
    data[1] -= rhs;
    data[2] -= rhs;
    return *this;
}

vec3 vec3::operator/=(const f32 rhs) {
    data[0] /= rhs;
    data[1] /= rhs;
    data[2] /= rhs;
    return *this;
}

vec3 vec3::operator*=(const f32 rhs) {
    data[0] *= rhs;
    data[1] *= rhs;
    data[2] *= rhs;
    return *this;
}

vec3 operator*(f32 lhs, const vec3& rhs) {
  return vec3 {lhs * rhs[0], lhs * rhs[1], lhs * rhs[2]};
}

vec3 operator*(const vec3& rhs, f32 lhs) {
  return lhs * rhs;
}
