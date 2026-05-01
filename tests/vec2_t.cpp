#include <gtest/gtest.h>
#include <vec2.hpp>

void expect_vector(const vec2& vec, f32 x, f32 y) {
    EXPECT_EQ(vec[0], x);
    EXPECT_EQ(vec[1], y);
}

TEST(vec2_t, initialisation) {
    vec2 v = vec2(1, 2);
    expect_vector(v, 1, 2);
    v = {2, 3};
    expect_vector(v, 2, 3);
}

TEST(vec2, normalise) {
  vec2 v = vec2(-1, -1);
  v.normalise();
  expect_vector(v,-0.707106769, -0.707106769);
}

TEST(vec2_t, copy_operator) {
    vec2 v1 = vec2(1, 2);
    vec2 v2 = v1;
    EXPECT_EQ(v1[0] = v2[0], 1.0f);
    EXPECT_EQ(v1[1] = v2[1], 2.0f);
}

TEST(vec2_t, magnitude) {
    vec2 v1 = vec2(1, 2);
    f32 mag = v1.magnitude();
    EXPECT_GE(mag, 2.23f);
    EXPECT_LE(mag, 2.24f);
}

TEST(vec2_t, index_operator) {
    vec2 v1 = vec2(1, 2);
    v1[1] = 1.0f;
    EXPECT_EQ(v1[1], 1.0f);
}

TEST(vec2_t, plus_equal_operator) {
    vec2 v1 = vec2(1, 2);
    v1 += vec2(1, 2);
    expect_vector(v1, 2, 4);
}

TEST(vec2_t, minus_equal_operator) {
    vec2 v1 = vec2(1, 2);
    v1 -= vec2(1, 2);
    expect_vector(v1, 0.0f, 0.0f);
}

TEST(vec2_t, divide_equal_operator) {
    vec2 v1 = vec2(10, 20);
    v1 /= vec2(10, 20);
    expect_vector(v1, 1.0f, 1.0f);
}

TEST(vec2_t, multiple_equal_operator) {
    vec2 v1 = vec2(10, 20);
    v1 *= vec2(10, 10);
    expect_vector(v1, 100.0f, 200.0f);
}

TEST(vec2_t, add_operator) {
    vec2 v1 = vec2(1, 2);
    vec2 v2 = v1 + vec2(1, 2);
    expect_vector(v2, 2.0f, 4.0f);
}

TEST(vec2_t, minus_operator) {
    vec2 v1 = vec2(1, 2);
    vec2 v2 = v1 - vec2(1, 2);
    expect_vector(v2, 0.0f, 0.0f);
}

TEST(vec2_t, multiply_operator) {
    vec2 v1 = vec2(1, 2);
    vec2 v2 = v1 * vec2(1, 2);
    expect_vector(v2, 1.0f, 4.0f);
}

TEST(vec2_t, divide_operator) {
    vec2 v1 = vec2(1, 2);
    vec2 v2 = v1 / vec2(1, 2);
    expect_vector(v2, 1.0f, 1.0f);
}

TEST(vec2_t, add_operator_f32) {
    vec2 v1 = vec2(1, 2);
    v1 += 2.0f;
    expect_vector(v1, 3.0f, 4.0f);
}

TEST(vec2_t, minus_operator_f32) {
    vec2 v1 = vec2(1, 2);
    v1 -= 2.0f;
    expect_vector(v1, -1.0f, 0.0f);
}

TEST(vec2_t, divide_operator_f32) {
    vec2 v1 = vec2(2, 4);
    v1 /= 2.0f;
    expect_vector(v1, 1.0f, 2.0f);
}

TEST(vec2_t, multiple_operator_f32) {
    vec2 v1 = vec2(1, 2);
    v1 *= 2.0f;
    expect_vector(v1, 2.0f, 4.0f);
}
