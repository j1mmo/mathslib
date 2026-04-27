#include "catmullrom.hpp"

vec2 maths::catmull_rom_solver(vec2 p0, vec2 p1, vec2 p2, vec2 p3, f32 t)
{
  const vec2 first  = (2 * p1);
  const vec2 second = (-p0 + p2) * t;
  const vec2 third  = (2 * p0 - 5 * p1 + 4 * p2 - p3) * t * t;
  const vec2 fourth = (-p0 + 3 * p1 - 3 * p2 + p3) * t * t * t;
  const vec2 add = first + second + third + fourth;
  const vec2 divide = 0.5 * add;
  return divide;
}

vec3 maths::catmull_rom_solver(vec3 p0, vec3 p1, vec3 p2, vec3 p3, f32 t)
{
  const vec3 first  = (2 * p1);
  const vec3 second = (-p0 + p2) * t;
  const vec3 third  = (2 * p0 - 5 * p1 + 4 * p2 - p3) * t * t;
  const vec3 fourth = (-p0 + 3 * p1 - 3 * p2 + p3) * t * t * t;
  const vec3 add = first + second + third + fourth;
  const vec3 divide = 0.5 * add;
  return divide;
}
