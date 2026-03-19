#include <gtest/gtest.h>
#include <matrix_transformations.hpp>

#include "helper.hpp"

TEST(matrix_transformations, rotatation)
{
  mat4 m{};
  m = rotate(m, 45, vec3{0.0f, 0.0f, 1.0f});
}

TEST(matrix_transformations, translate)
{
  vec4 vec{1.0f, 0.0f, 0.0f, 1.0f};
  mat4 trans{};
  trans = translate(trans, vec3{1.0f, 1.0f, 0.0f});
  vec = trans * vec;
  expect_vector(vec4{2.0f, 1.0f, 0.0f, 1.0}, vec);
}


