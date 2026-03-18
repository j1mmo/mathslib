#ifndef MATRIX_TRANSFORMATIONS_HPP
#define MATRIX_TRANSFORMATIONS_HPP
#pragma once

#include <cmath>

#include "mat4.hpp"
#include "vec3.hpp"

mat4 rotate(const mat4& m, float angle, vec3 axis);
mat4 translate(const mat4& m, const vec3& v);
mat4 scale(const mat4& m, const vec3& v);

#endif // MATRIX_TRANSFORMATIONS_HPP
