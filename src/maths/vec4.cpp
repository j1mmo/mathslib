#include <vec4.hpp>

#include <cassert>
#include <cmath>

vec4::vec4(const float x, const float y, const float z, const float v)
    : data {x, y, z, v} {}

f32 vec4::dot_product(const vec4& a, const vec4& b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
}

//TODO: maybe change to vec3
vec4 vec4::cross_product(const vec4& a, const vec4& b) {
    return vec4 {
        (a[1] * b[2] - a[2] * b[1]),
        (a[2] * b[0] - a[0] * b[2]),
        (a[0] * b[1] - a[1] * b[0]),
        0};
}

f32 vec4::magnitude() const {
    return sqrtf(data[0] * data[0] + data[1] * data[1] + data[2] * data[2] + data[3] * data[3]);
}

f32 vec4::operator[](const uint32_t index) const {
    assert(index < 4);
    return data[index];
}

f32& vec4::operator[](const uint32_t index) {
    assert(index < 4);
    return data[index];
}

vec4 vec4::operator+=(const vec4& rhs) {
    data[0] += rhs.data[0];
    data[1] += rhs.data[1];
    data[2] += rhs.data[2];
    data[3] += rhs.data[3];
    return *this;
}

vec4 vec4::operator-=(const vec4& rhs) {
    data[0] -= rhs.data[0];
    data[1] -= rhs.data[1];
    data[2] -= rhs.data[2];
    data[3] -= rhs.data[3];
    return *this;
}

vec4 vec4::operator/=(const vec4& rhs) {
    data[0] /= rhs.data[0];
    data[1] /= rhs.data[1];
    data[2] /= rhs.data[2];
    data[3] /= rhs.data[3];
    return *this;
}

vec4 vec4::operator*=(const vec4& rhs) {
    data[0] *= rhs.data[0];
    data[1] *= rhs.data[1];
    data[2] *= rhs.data[2];
    data[3] *= rhs.data[3];
    return *this;
}

vec4 operator+(vec4 lhs, const vec4& rhs) {
    lhs += rhs;
    return lhs;
}

vec4 operator-(vec4 lhs, const vec4& rhs) {
    lhs -= rhs;
    return lhs;
}

vec4 operator*(vec4 lhs, const vec4& rhs) {
    lhs *= rhs;
    return lhs;
}

vec4 operator/(vec4 lhs, const vec4& rhs) {
    lhs /= rhs;
    return lhs;
}

vec4 vec4::operator+=(const f32 rhs) {
    data[0] += rhs;
    data[1] += rhs;
    data[2] += rhs;
    data[3] += rhs;
    return *this;
}

vec4 vec4::operator-=(const f32 rhs) {
    data[0] -= rhs;
    data[1] -= rhs;
    data[2] -= rhs;
    data[3] -= rhs;
    return *this;
}

vec4 vec4::operator/=(const f32 rhs) {
    data[0] /= rhs;
    data[1] /= rhs;
    data[2] /= rhs;
    data[3] /= rhs;
    return *this;
}

vec4 vec4::operator*=(const f32 rhs) {
    data[0] *= rhs;
    data[1] *= rhs;
    data[2] *= rhs;
    data[3] *= rhs;
    return *this;
}
