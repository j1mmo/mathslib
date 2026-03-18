#ifndef VEC4_H
#define VEC4_H

#include "preferences.hpp"

#include <cstdint>

struct vec4 {
    f32 data[4] {0.0f,0.0f,0.0f,0.0f};

    vec4() = default;
    vec4(float x, float y, float z, float v);

    static f32  dot_product(const vec4& a, const vec4& b);
    static vec4 cross_product(const vec4& a, const vec4& b);
    [[nodiscard]] f32 magnitude() const;

    f32  operator[](uint32_t index) const;
    f32& operator[](uint32_t index);

    vec4 operator+=(const vec4& rhs);
    vec4 operator-=(const vec4& rhs);
    vec4 operator/=(const vec4& rhs);
    vec4 operator*=(const vec4& rhs);

    vec4 operator+=(f32 rhs);
    vec4 operator-=(f32 rhs);
    vec4 operator/=(f32 rhs);
    vec4 operator*=(f32 rhs);
};

vec4 operator+(vec4 lhs, const vec4& rhs);
vec4 operator-(vec4 lhs, const vec4& rhs);
vec4 operator*(vec4 lhs, const vec4& rhs);
vec4 operator/(vec4 lhs, const vec4& rhs);

#endif //VEC4_H
