#ifndef VEC3_H
#define VEC3_H
#include "preferences.hpp"
#include <cstdint>

struct vec3 {
    f32 data[3] {0.0f,0.0f,0.0f};

    vec3() = default;
    vec3(float x, float y, float z);

    static f32 dot(const vec3& a, const vec3& b);
    static vec3 cross_product(const vec3& a, const vec3& b);
    f32 magnitude() const;
    void normalise();

    f32  operator[](uint32_t index) const;
    f32& operator[](uint32_t index);

    vec3 operator+=(const vec3& rhs);
    vec3 operator-=(const vec3& rhs);
    vec3 operator/=(const vec3& rhs);
    vec3 operator*=(const vec3& rhs);

    vec3 operator+=(f32 rhs);
    vec3 operator-=(f32 rhs);
    vec3 operator/=(f32 rhs);
    vec3 operator*=(f32 rhs);
};

vec3 operator+(vec3 lhs, const vec3& rhs);
vec3 operator-(vec3 lhs, const vec3& rhs);
vec3 operator*(vec3 lhs, const vec3& rhs);
vec3 operator/(vec3 lhs, const vec3& rhs);
vec3 operator*(f32 lhs, const vec3& rhs);
vec3 operator*(const vec3& rhs, f32 lhs);

#endif //VEC3_H
