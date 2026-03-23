#ifndef GENERAL_H
#define GENERAL_H

#include "preferences.hpp"
#include "vec3.hpp"

namespace maths
{
  inline constexpr f32 pi = 3.1415926535897932384626433832795f;

  f32 radians(f32 degrees);
  f32 degrees(f32 radians);
  vec3 normalise(const vec3& vec);
  vec3 cross(const vec3& a, const vec3& b);
}

#endif //GENERAL_H
