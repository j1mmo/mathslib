#include <gtest/gtest.h>
#include "helper.hpp"
#include "maths/mat4.hpp"


const mat4 m =
    {1,2,3,4,
     5,6,7,8,
     9,10,11,12,
     13,14,15,16};


TEST(mat4_t, single_indexing_operator_overloading) {
    ASSERT_EQ(m[0], 1);
    ASSERT_EQ(m[1], 2);
    ASSERT_EQ(m[2], 3);
    ASSERT_EQ(m[3], 4);
    ASSERT_EQ(m[4], 5);
    ASSERT_EQ(m[5], 6);
    ASSERT_EQ(m[6], 7);
    ASSERT_EQ(m[7], 8);
    ASSERT_EQ(m[8], 9);
    ASSERT_EQ(m[9], 10);
    ASSERT_EQ(m[10], 11);
    ASSERT_EQ(m[11], 12);
    ASSERT_EQ(m[12], 13);
    ASSERT_EQ(m[13], 14);
    ASSERT_EQ(m[14], 15);
    ASSERT_EQ(m[15], 16);
}

TEST(mat4_t, single_indexing_operator_overloading_editable) {
    mat4 m{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    m[0]=1;
    m[1]=2;
    m[2]=3;
    m[3]=4;
    m[4]=5;
    m[5]=6;
    m[6]=7;
    m[7]=8;
    m[8]=9;
    m[9]=10;
    m[10]=11;
    m[11]=12;
    m[12]=13;
    m[13]=14;
    m[14]=15;
    m[15]=16;
    ASSERT_EQ(m[0], 1);
    ASSERT_EQ(m[1], 2);
    ASSERT_EQ(m[2], 3);
    ASSERT_EQ(m[3], 4);
    ASSERT_EQ(m[4], 5);
    ASSERT_EQ(m[5], 6);
    ASSERT_EQ(m[6], 7);
    ASSERT_EQ(m[7], 8);
    ASSERT_EQ(m[8], 9);
    ASSERT_EQ(m[9], 10);
    ASSERT_EQ(m[10], 11);
    ASSERT_EQ(m[11], 12);
    ASSERT_EQ(m[12], 13);
    ASSERT_EQ(m[13], 14);
    ASSERT_EQ(m[14], 15);
    ASSERT_EQ(m[15], 16);
}

TEST(mat4_t, multi_indexing_operator_overloading) {
    // first row
    f32 m11 = m(0,0);
    ASSERT_EQ(m11, 1.0f);
    f32 m12 = m(0,1);
    ASSERT_EQ(m12, 2.0f);
    f32 m13 = m(0,2);
    ASSERT_EQ(m13, 3.0f);
    f32 m14 = m(0,3);
    ASSERT_EQ(m14, 4.0f);

    // second row
    f32 m21 = m(1,0);
    ASSERT_EQ(m21, 5.0f);
    f32 m22 = m(1,1);
    ASSERT_EQ(m22, 6.0f);
    f32 m23 = m(1,2);
    ASSERT_EQ(m23, 7.0f);
    f32 m24 = m(1,3);
    ASSERT_EQ(m24, 8.0f);

    // third row
    f32 m31 = m(2,0);
    ASSERT_EQ(m31, 9.0f);
    f32 m32 = m(2,1);
    ASSERT_EQ(m32, 10.0f);
    f32 m33 = m(2,2);
    ASSERT_EQ(m33, 11.0f);
    f32 m34 = m(2,3);
    ASSERT_EQ(m34, 12.0f);

    // fourth row
    f32 m41 = m(3,0);
    ASSERT_EQ(m41, 13.0f);
    f32 m42 = m(3,1);
    ASSERT_EQ(m42, 14.0f);
    f32 m43 = m(3,2);
    ASSERT_EQ(m43, 15.0f);
    f32 m44 = m(3,3);
    ASSERT_EQ(m44, 16.0f);
}

TEST(mat4_t, multi_indexing_operator_overloading_editing) {
    // first row
    mat4 m1 = mat4{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    m1(0,0) += 1;
    f32 m11 = m1(0,0);
    ASSERT_EQ(m11, 2.0f);
    m1(0,1) += 1;
    f32 m12 = m1(0,1);
    ASSERT_EQ(m12, 3.0f);
    m1(0,2) += 1;
    f32 m13 = m1(0,2);
    ASSERT_EQ(m13, 4.0f);
    m1(0,3) += 1;
    f32 m14 = m1(0,3);
    ASSERT_EQ(m14, 5.0f);

    // second row
    m1(1,0) += 1;
    f32 m21 = m1(1,0);
    ASSERT_EQ(m21, 6.0f);
    m1(1,1) += 1;
    f32 m22 = m1(1,1);
    ASSERT_EQ(m22, 7.0f);
    m1(1,2) += 1;
    f32 m23 = m1(1,2);
    ASSERT_EQ(m23, 8.0f);
    m1(1,3) += 1;
    f32 m24 = m1(1,3);
    ASSERT_EQ(m24, 9.0f);

    // third row
    m1(2,0) += 1;
    f32 m31 = m1(2,0);
    ASSERT_EQ(m31, 10.0f);
    m1(2,1) += 1;
    f32 m32 = m1(2,1);
    ASSERT_EQ(m32, 11.0f);
    m1(2,2) += 1;
    f32 m33 = m1(2,2);
    ASSERT_EQ(m33, 12.0f);
    m1(2,3) += 1;
    f32 m34 = m1(2,3);
    ASSERT_EQ(m34, 13.0f);

    // fourth row
    m1(3,0) += 1;
    f32 m41 = m1(3,0);
    ASSERT_EQ(m41, 14.0f);
    m1(3,1) += 1;
    f32 m42 = m1(3,1);
    ASSERT_EQ(m42, 15.0f);
    m1(3,2) += 1;
    f32 m43 = m1(3,2);
    ASSERT_EQ(m43, 16.0f);
    m1(3,3) += 1;
    f32 m44 = m1(3,3);
    ASSERT_EQ(m44, 17.0f);
}

TEST(mat4_t, get_vec4f_row) {
    vec4 r1 = m(mat4::row::vec4, 0);
    expect_vector(r1, 1,2,3,4);
    vec4 r2 = m(mat4::row::vec4, 1);
    expect_vector(r2, 5,6,7,8);
    vec4 r3 = m(mat4::row::vec4, 2);
    expect_vector(r3, 9,10,11,12);
    vec4 r4 = m(mat4::row::vec4, 3);
    expect_vector(r4, 13,14,15,16);
}

TEST(mat4_t, get_vec4f_col) {
    vec4 c1 = m(mat4::col::vec4, 0);
    expect_vector(c1, 1,5,9,13);
    vec4 c2 = m(mat4::col::vec4, 1);
    expect_vector(c2, 2,6,10,14);
    vec4 c3 = m(mat4::col::vec4, 2);
    expect_vector(c3, 3,7,11,15);
    vec4 c4 = m(mat4::col::vec4, 3);
    expect_vector(c4, 4,8,12,16);
}

TEST(mat4_t, matrix_multiplication) {
    mat4 product = m * m;
    expect_equal(product,
        90.0f, 100.0f, 110.0f, 120.0f,
        202.0f, 228.0f, 254.0f, 280.0f,
        314.0f, 356.0f, 398.0f, 440.0f,
        426.0f, 484.0f, 542.0f, 600.0f);
}

TEST(mat4_t, matrix_multiplied_by_vector) {
    vec4 v = m * vec4(1,2,3,4);
    expect_vector(v, 30.0f, 70.0f, 110.0f, 150.0f);
}

TEST(mat4_t, matrix_addition_by_matrix) {
    mat4 product = m + m;
    expect_equal(product,
        2.0f, 4.0f, 6.0f, 8.0f,
        10.0f, 12.0f, 14.0f, 16.0f,
        18.0f, 20.0f, 22.0f, 24.0f,
        26.0f, 28.0f, 30.0f, 32.0f);
}
