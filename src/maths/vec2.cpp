#include "include/vec2.hpp"
#include "include/preferences.hpp"
#include <cassert>
#include <cmath>

vec2::vec2(const float x, const float y)
    : data {x, y} {}

void vec2::normalise() {
    (*this) /= magnitude();
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
