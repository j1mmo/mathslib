#include <general.hpp>

namespace m {

    f32 degrees_to_radians(f32 degrees) {
        return degrees * (pi / 180.0f);
    }

    f32 radians_to_degrees(f32 radians) {
        return radians * (180.0f / pi);
    }
}

