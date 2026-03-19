#include <general.hpp>

f32 maths::radians(f32 degrees) {
  return degrees * (maths::pi / 180.0f);
}

f32 maths::degrees(f32 radians) {
  return radians * (180.0f / maths::pi);
}

