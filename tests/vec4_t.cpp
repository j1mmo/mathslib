#include <gtest/gtest.h>
#include "helper.hpp"
#include "maths/vec4.hpp"



TEST(vector, initialisation) {
    vec4 v = vec4(1, 2, 3, 4);
    expect_vector(v, 1, 2, 3, 4);
    v = {2, 3, 4, 5};
    expect_vector(v, 2, 3, 4, 5);
}

TEST(vector, copy_operator) {
    vec4 v1 = vec4(1, 2, 3, 4);
    vec4 v2 = v1;
    EXPECT_EQ(v1[0] = v2[0], 1.0f);
    EXPECT_EQ(v1[1] = v2[1], 2.0f);
    EXPECT_EQ(v1[2] = v2[2], 3.0f);
    EXPECT_EQ(v1[3] = v2[3], 4.0f);
}

TEST(vector, dot_product) {
    vec4 v1 = vec4(1, 2, 3, 4);
    vec4 v2 = vec4(1, 2, 3, 4);
    f32 dot_product = vec4::dot_product(v1, v2);
    EXPECT_EQ(dot_product, 30.0f);
}

TEST(vector, cross_product) {
    vec4 v1 = vec4(1, 2, 3, 4);
    vec4 v2 = vec4(1, 2, 3, 4);
    vec4 cross_product = vec4::cross_product(v1, v2);
    expect_vector(cross_product, 0.0f, 0.0f, 0.0f, 0.0f);
}

TEST(vector, magnitude) {
    vec4 v1 = vec4(1, 2, 3, 4);
    f32 mag = v1.magnitude();
    EXPECT_GE(mag, 5.46f);
    EXPECT_LE(mag, 5.48f);
}

TEST(vector, index_operator) {
    vec4 v1 = vec4(1, 2, 3, 4);
    v1[2] = 1.0f;
    EXPECT_EQ(v1[2], 1.0f);
}

TEST(vector, plus_equal_operator) {
    vec4 v1 = vec4(1, 2, 3, 4);
    v1 += vec4(1, 2, 3, 4);
    expect_vector(v1, 2, 4, 6, 8);
}

TEST(vector, minus_equal_operator) {
    vec4 v1 = vec4(1, 2, 3, 4);
    v1 -= vec4(1, 2, 3, 4);
    expect_vector(v1, 0.0f, 0.0f, 0.0f, 0.0f);
}

TEST(vector, divide_equal_operator) {
    vec4 v1 = vec4(10, 20, 30, 40);
    v1 /= vec4(10, 20, 30, 40);
    expect_vector(v1, 1.0f, 1.0f, 1.0f, 1.0f);
}

TEST(vector, multiple_equal_operator) {
    vec4 v1 = vec4(10, 20, 30, 40);
    v1 *= vec4(10, 10, 10, 10);
    expect_vector(v1, 100.0f, 200.0f, 300.0f, 400.0f);
}

TEST(vector, add_operator) {
    vec4 v1 = vec4(1, 2, 3, 4);
    vec4 v2 = v1 + vec4(1, 2, 3, 4);
    expect_vector(v2, 2.0f, 4.0f, 6.0f, 8.0f);
}

TEST(vector, minus_oeprator) {
    vec4 v1 = vec4(1, 2, 3, 4);
    vec4 v2 = v1 - vec4(1, 2, 3, 4);
    expect_vector(v2, 0.0f, 0.0f, 0.0f, 0.0f);
}

TEST (vector, multiply_operator) {
    vec4 v1 = vec4(1, 2, 3, 4);
    vec4 v2 = v1 * vec4(1, 2, 3, 4);
    expect_vector(v2, 1.0f, 4.0f, 9.0f, 16.0f);
}

TEST (vector, divide_operator) {
    vec4 v1 = vec4(1, 2, 3, 4);
    vec4 v2 = v1 / vec4(1, 2, 3, 4);
    expect_vector(v2, 1.0f, 1.0f, 1.0f, 1.0f);
}

TEST (vector, add_operator_f32) {
    vec4 v1 = vec4(1, 2, 3, 4);
    v1 += 2.0f;
    expect_vector(v1, 3.0f, 4.0f, 5.0f, 6.0f);
}

TEST (vector, minus_operator_f32) {
    vec4 v1 = vec4(1, 2, 3, 4);
    v1 -= 2.0f;
    expect_vector(v1, -1.0f, 0.0f, 1.0f, 2.0f);
}

TEST (vector, divide_operator_f32) {
    vec4 v1 = vec4(2, 4, 6, 8);
    v1 /= 2.0f;
    expect_vector(v1, 1.0f, 2.0f, 3.0f, 4.0f);
}

TEST (vector, multiple_operator_f32) {
    vec4 v1 = vec4(1, 2, 3, 4);
    v1 *= 2.0f;
    expect_vector(v1, 2.0f, 4.0f, 6.0f, 8.0f);
}
