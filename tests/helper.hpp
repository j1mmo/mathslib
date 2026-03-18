#ifndef HELPER_H
#define HELPER_H

#include "maths/mat4.hpp"

void expect_vector(const vec4& vec, f32 x, f32 y, f32 z, f32 w);
void expect_equal(const mat4& mat,
    f32 m00, f32 m02, f32 m03, f32 m04,
    f32 m10, f32 m12, f32 m13, f32 m14,
    f32 m20, f32 m22, f32 m23, f32 m24,
    f32 m30, f32 m32, f32 m33, f32 m44);

#endif //HELPER_H
