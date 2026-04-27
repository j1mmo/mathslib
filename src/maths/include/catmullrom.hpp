#ifndef CATMULLROM_HPP
#define CATMULLROM_HPP

#include "preferences.hpp"
#include "vec2.hpp"
#include "vec3.hpp"
namespace maths
{
  vec2 catmull_rom_solver(vec2 p1, vec2 p2, vec2 p3, vec2 p4, f32 t);
  vec3 catmull_rom_solver(vec3 p1, vec3 p2, vec3 p3, vec3 p4, f32 t);
}

#endif // CATMULLROM_HPP
