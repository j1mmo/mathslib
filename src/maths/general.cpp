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

vec3 cross(const vec3& a, const vec3& b)
{
  return vec3 {
        (a[1] * b[2] - a[2] * b[1]),
        (a[2] * b[0] - a[0] * b[2]),
        (a[0] * b[1] - a[1] * b[0])};
}

