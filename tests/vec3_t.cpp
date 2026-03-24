#include <gtest/gtest.h>
#include <vec3.hpp>

void expect_vector(const vec3& vec, f32 x, f32 y, f32 z) {
    EXPECT_EQ(vec[0], x);
    EXPECT_EQ(vec[1], y);
    EXPECT_EQ(vec[2], z);
}


TEST(vec3_t, initialisation) {
    vec3 v = vec3(1, 2, 3);
    expect_vector(v, 1, 2, 3);
    v = {2, 3, 4};
    expect_vector(v, 2, 3, 4);
}

TEST(vec3_t, copy_operator) {
    vec3 v1 = vec3(1, 2, 3);
    vec3 v2 = v1;
    EXPECT_EQ(v1[0] = v2[0], 1.0f);
    EXPECT_EQ(v1[1] = v2[1], 2.0f);
    EXPECT_EQ(v1[2] = v2[2], 3.0f);
}

TEST(vec3_t, dot_product) {
    vec3 v1 = vec3(1, 2, 3);
    vec3 v2 = vec3(1, 2, 3);
    f32 dot_product = vec3::dot(v1, v2);
    EXPECT_EQ(dot_product, 14.0f);
}

TEST(vec3_t, cross_product) {
    vec3 v1 = vec3(1, 2, 3);
    vec3 v2 = vec3(1, 2, 3);
    vec3 cross_product = vec3::cross_product(v1, v2);
    expect_vector(cross_product, 0.0f, 0.0f, 0.0f);
}

TEST(vec3_t, magnitude) {
    vec3 v1 = vec3(1, 2, 3);
    f32 mag = v1.magnitude();
    EXPECT_GE(mag, 3.73f);
    EXPECT_LE(mag, 3.75f);
}

TEST(vec3_t, index_operator) {
    vec3 v1 = vec3(1, 2, 3);
    v1[2] = 1.0f;
    EXPECT_EQ(v1[2], 1.0f);
}

TEST(vec3_t, plus_equal_operator) {
    vec3 v1 = vec3(1, 2, 3);
    v1 += vec3(1, 2, 3);
    expect_vector(v1, 2, 4, 6);
}

TEST(vec3_t, minus_equal_operator) {
    vec3 v1 = vec3(1, 2, 3);
    v1 -= vec3(1, 2, 3);
    expect_vector(v1, 0.0f, 0.0f, 0.0f);
}

TEST(vec3_t, divide_equal_operator) {
    vec3 v1 = vec3(10, 20, 30);
    v1 /= vec3(10, 20, 30);
    expect_vector(v1, 1.0f, 1.0f, 1.0f);
}

TEST(vec3_t, multiple_equal_operator) {
    vec3 v1 = vec3(10, 20, 30);
    v1 *= vec3(10, 10, 10);
    expect_vector(v1, 100.0f, 200.0f, 300.0f);
}

TEST(vec3_t, add_operator) {
    vec3 v1 = vec3(1, 2, 3);
    vec3 v2 = v1 + vec3(1, 2, 3);
    expect_vector(v2, 2.0f, 4.0f, 6.0f);
}

TEST(vec3_t, minus_oeprator) {
    vec3 v1 = vec3(1, 2, 3);
    vec3 v2 = v1 - vec3(1, 2, 3);
    expect_vector(v2, 0.0f, 0.0f, 0.0f);
}

TEST(vec3_t, multiply_operator) {
    vec3 v1 = vec3(1, 2, 3);
    vec3 v2 = v1 * vec3(1, 2, 3);
    expect_vector(v2, 1.0f, 4.0f, 9.0f);
}

TEST(vec3_t, divide_operator) {
    vec3 v1 = vec3(1, 2, 3);
    vec3 v2 = v1 / vec3(1, 2, 3);
    expect_vector(v2, 1.0f, 1.0f, 1.0f);
}

TEST(vec3_t, add_operator_f32) {
    vec3 v1 = vec3(1, 2, 3);
    v1 += 2.0f;
    expect_vector(v1, 3.0f, 4.0f, 5.0f);
}

TEST(vec3_t, minus_operator_f32) {
    vec3 v1 = vec3(1, 2, 3);
    v1 -= 2.0f;
    expect_vector(v1, -1.0f, 0.0f, 1.0f);
}

TEST(vec3_t, divide_operator_f32) {
    vec3 v1 = vec3(2, 4, 6);
    v1 /= 2.0f;
    expect_vector(v1, 1.0f, 2.0f, 3.0f);
}

TEST(vec3_t, multiple_operator_f32) {
    vec3 v1 = vec3(1, 2, 3);
    v1 *= 2.0f;
    expect_vector(v1, 2.0f, 4.0f, 6.0f);
}
