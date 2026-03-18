#include "helper.hpp"
#include <gtest/gtest.h>

void expect_vector(const vec4& vec, f32 x, f32 y, f32 z, f32 w) {
    EXPECT_EQ(vec[0], x);
    EXPECT_EQ(vec[1], y);
    EXPECT_EQ(vec[2], z);
    EXPECT_EQ(vec[3], w);
}

void expect_vector(const vec4& vec1, const vec4& vec2)
{
  EXPECT_EQ(vec1[0], vec2[0]);
  EXPECT_EQ(vec1[1], vec2[1]);
  EXPECT_EQ(vec1[2], vec2[2]);
  EXPECT_EQ(vec1[3], vec2[3]);
}

void expect_equal(const mat4& mat,
    f32 m00, f32 m01, f32 m02, f32 m03,
    f32 m10, f32 m11, f32 m12, f32 m13,
    f32 m20, f32 m21, f32 m22, f32 m23,
    f32 m30, f32 m31, f32 m32, f32 m43) {
    EXPECT_EQ(mat[0], m00);
    EXPECT_EQ(mat[1], m01);
    EXPECT_EQ(mat[2], m02);
    EXPECT_EQ(mat[3], m03);
    EXPECT_EQ(mat[4], m10);
    EXPECT_EQ(mat[5], m11);
    EXPECT_EQ(mat[6], m12);
    EXPECT_EQ(mat[7], m13);
    EXPECT_EQ(mat[8], m20);
    EXPECT_EQ(mat[9], m21);
    EXPECT_EQ(mat[10], m22);
    EXPECT_EQ(mat[11], m23);
    EXPECT_EQ(mat[12], m30);
    EXPECT_EQ(mat[13], m31);
    EXPECT_EQ(mat[14], m32);
    EXPECT_EQ(mat[15], m43);
}
