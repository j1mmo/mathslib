#include <frenet_serret.hpp>

maths::Frenet_Serret maths::get_frent_serret_coords(vec3 current_position, vec3 next_position) {
  Frenet_Serret return_struct;

  return_struct._t = vec3::normalise(next_position - current_position);
  vec3 world_up = {0.0f, 1.0f, 0.0f};
  vec3 cross = vec3::cross_product(return_struct._t, world_up);
  return_struct._b = vec3::normalise(cross);

  return_struct._n = vec3::cross_product(return_struct._b, return_struct._t);

  return return_struct;
}

