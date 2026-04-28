#ifndef FRENET_SERRET_HPP
#define FRENET_SERRET_HPP

#include "vec3.hpp"

namespace maths {
  struct Frenet_Serret {
    vec3 _t;
    vec3 _b;
    vec3 _n;
  };

  Frenet_Serret get_frent_serret_coords(vec3 current_position, vec3 next_position);
}

#endif // FRENET_SERRET_HPP
