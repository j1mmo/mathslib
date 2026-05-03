#ifndef VEC2_HPP
#define VEC2_HPP

#include "preferences.hpp"

struct vec2 {
  f32 data[2] {0.0f,0.0f};

  vec2() = default;
  vec2(float x, float y);

  static f32 cross_product(const vec2& lhs, const vec2& rhs);
  static f32 dot_product(const vec2& lhs, const vec2& rhs);
  f32 magnitude() const;
  void Absolute();
  void normalise();

  f32  operator[](u32 index) const;
  f32& operator[](u32 index);
  
  vec2 operator-() const;
  
  vec2 operator+=(const vec2& rhs);
  vec2 operator-=(const vec2& rhs);
  vec2 operator/=(const vec2& rhs);
  vec2 operator*=(const vec2& rhs);

  vec2 operator+=(f32 rhs);
  vec2 operator-=(f32 rhs);
  vec2 operator/=(f32 rhs);
  vec2 operator*=(f32 rhs);
};

vec2 operator+(vec2 lhs, const vec2& rhs);
vec2 operator-(vec2 lhs, const vec2& rhs);
vec2 operator*(vec2 lhs, const vec2& rhs);
vec2 operator/(vec2 lhs, const vec2& rhs);
vec2 operator*(f32 lhs, const vec2& rhs);
vec2 operator*(const vec2& rhs, f32 lhs);

#endif // VEC2_HPP
