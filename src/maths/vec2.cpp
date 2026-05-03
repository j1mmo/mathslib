#include "include/vec2.hpp"
#include "include/preferences.hpp"
#include <cassert>
#include <cmath>

vec2::vec2(const float x, const float y)
    : data {x, y} {}

f32 vec2::cross_product(const vec2& lhs, const vec2& rhs) {
  return lhs[0] * rhs[1] - rhs[0] * lhs[1];
}

f32 vec2::dot_product(const vec& lhs, const vec& rhs) {
  return lhs[0] * lhs[1] + rhs[0] * rhs[1];
}
void vec2::normalise() {
    (*this) /= magnitude();
}

void vec2::Absolute() {
  f32 x = data[0];
  f32 y = data[1];
  data[0] = abs(x);
  data[1] = abs(y);
}

f32 vec2::magnitude() const {
    return sqrtf(data[0] * data[0] + data[1] * data[1]);
}

f32 vec2::operator[](const u32 index) const {
    assert(index < 2);
    return data[index];
}

f32& vec2::operator[](const u32 index) {
    assert(index < 2);
    return data[index];
}

vec2 vec2::operator-() const {
  vec2 v{-data[0], -data[1]};
  return v;
}

vec2 vec2::operator+=(const vec2& rhs) {
    data[0] += rhs.data[0];
    data[1] += rhs.data[1];
    return *this;
}

vec2 vec2::operator-=(const vec2& rhs) {
    data[0] -= rhs.data[0];
    data[1] -= rhs.data[1];
    return *this;
}

vec2 vec2::operator/=(const vec2& rhs) {
    data[0] /= rhs.data[0];
    data[1] /= rhs.data[1];
    return *this;
}

vec2 vec2::operator*=(const vec2& rhs) {
    data[0] *= rhs.data[0];
    data[1] *= rhs.data[1];
    return *this;
}

vec2 operator+(vec2 lhs, const vec2& rhs) {
    lhs += rhs;
    return lhs;
}

vec2 operator-(vec2 lhs, const vec2& rhs) {
    lhs -= rhs;
    return lhs;
}

vec2 operator*(vec2 lhs, const vec2& rhs) {
    lhs *= rhs;
    return lhs;
}

vec2 operator/(vec2 lhs, const vec2& rhs) {
    lhs /= rhs;
    return lhs;
}

vec2 vec2::operator+=(const f32 rhs) {
    data[0] += rhs;
    data[1] += rhs;
    return *this;
}

vec2 vec2::operator-=(const f32 rhs) {
    data[0] -= rhs;
    data[1] -= rhs;
    return *this;
}

vec2 vec2::operator/=(const f32 rhs) {
    data[0] /= rhs;
    data[1] /= rhs;
    return *this;
}

vec2 vec2::operator*=(const f32 rhs) {
    data[0] *= rhs;
    data[1] *= rhs;
    return *this;
}

vec2 operator*(f32 lhs, const vec2& rhs) {
  return vec2 {lhs * rhs[0], lhs * rhs[1]};
}

vec2 operator*( const vec2& rhs, f32 lhs) {
  return lhs * rhs;
}
