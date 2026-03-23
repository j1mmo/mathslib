#include <general.hpp>

#include <cmath>

f32 maths::radians(f32 degrees)
{
  return degrees * (maths::pi / 180.0f);
}

f32 maths::degrees(f32 radians)
{
  return radians * (180.0f / maths::pi);
}

vec3 maths::normalise(const vec3& vec)
{
  const float length =
    sqrtf(vec[0] * vec[0] +
	  vec[1] * vec[1] +
	  vec[2] * vec[2]);
  return vec3{
    vec[0] / length,
    vec[1] / length,
    vec[2] / length};
}

