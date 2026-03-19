#ifndef GENERAL_H
#define GENERAL_H
#include "preferences.hpp"

namespace maths
{
  inline constexpr f32 pi = 3.1415926535897932384626433832795f;

  f32 radians(f32 degrees);
  f32 degrees(f32 radians);
}

#endif //GENERAL_H
