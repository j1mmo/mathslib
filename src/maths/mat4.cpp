#include <mat4.hpp>
#include <general.hpp>
#include <immintrin.h>

#include <cassert>
#include <cstring>
#include <cmath>
#include <cstdio>


mat4::mat4() : data{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1} {}

mat4::mat4(f32 value) : data{value} {}

mat4::mat4(const f32 m00, const f32 m01, const f32 m02, const f32 m03,
           const f32 m10, const f32 m11, const f32 m12, const f32 m13,
           const f32 m20, const f32 m21, const f32 m22, const f32 m23,
           const f32 m30, const f32 m31, const f32 m32, const f32 m33) :
          data{m00, m01, m02, m03,
               m10, m11, m12, m13,
               m20, m21, m22, m23,
               m30, m31, m32, m33} {}

float& mat4::operator[](const uint32_t index) {
    assert(index < 16);
    return data[index];
}

float mat4::operator[](const uint32_t index) const {
    assert(index < 16);
    return data[index];
}

float& mat4::operator()(const size_t row, const size_t col) {
    assert(row < 4 && col < 4);
    return data[col + row * 4];
}

float mat4::operator()(const uint32_t row, const uint32_t col) const {
    assert(row < 4 && col < 4);
    return data[col + row * 4];
}

vec4 mat4::operator()(const row row, const size_t index) const {
    assert (row == row::vec4);
    assert (index < 4);
    return vec4{data[index * 4], data[index * 4 + 1], data[index * 4 + 2], data[index * 4 + 3]};
}

vec4 mat4::operator()(const col col, const size_t index) const {
    assert (col == col::vec4);
    assert (index < 4);
    return vec4{data[index], data[4 + index], data[8 + index], data[12 + index]};
}

mat4& mat4::operator*=(const mat4& other) {
    mat4 temp = mat4{0.0f};
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            const __m128 rhs_row = _mm_set_ps(data[3 + 4 * row], data[2 + 4 * row], data[1 + 4 * row], data[0 + 4 * row]);
            const __m128 lhs_col = _mm_set_ps(other[col + 12], other[col + 8], other[col + 4], other[col]);
            __m128 calculation = _mm_mul_ps(rhs_row, lhs_col);
            const auto * result = reinterpret_cast<float *>(&calculation);
            for (int i = 0; i < 4; i++) {
                temp(row, col) += result[i];
            }
        }
    }
    *this = temp;
    return *this;
}

mat4 operator*(mat4 lhs, const mat4& rhs) {
    lhs *= rhs;
    return lhs;
}

mat4& mat4::operator+=(const mat4& other) {
    for (size_t i = 0; i < 16; i++) {
        data[i] += other[i];
    }
    return *this;
}

mat4 operator+(mat4 lhs, const mat4& rhs) {
    lhs += rhs;
    return lhs;
}

mat4& mat4::operator-=(const mat4& other) {
    for (size_t i = 0; i < 16; i++) {
        data[i] -= other[i];
    }
    return *this;
}

mat4 operator-(mat4 lhs, const mat4& rhs) {
    lhs += rhs;
    return lhs;
}

vec4 operator*(mat4 lhs, const vec4& rhs) {
  vec4 result{0.0f, 0.0f, 0.0f, 0.0f};
  
  for (int row = 0; row < 4; row++) {
      for (int col = 0; col < 4; col++) {
	  result[row] += lhs[col + row * 4] * rhs[col];
      }
  }

  return result;
}

void mat4::set_frustum(const projection& projection)
{
    const f32 m0 = (2 * projection.near) / (projection.right - projection.left);
    const f32 m5 = (2 * projection.near) / (projection.top - projection.bottom);
    const f32 m8 = (projection.right + projection.left) / (projection.right - projection.left);
    const f32 m9 = (projection.top + projection.bottom) / (projection.top - projection.bottom);
    const f32 m10 = -(projection.far + projection.near) / (projection.far - projection.near);
    const f32 m14 = (-2 * projection.far * projection.near) / (projection.far - projection.near);

    *this = mat4{
         m0,  0,   0,  0,
          0, m5,   0,  0,
         m8, m9, m10, -1,
          0,  0, m14,  0};
}

void mat4::setLookAt(const vec3& eye, const vec3& centre, const vec3& up)
{
    setIdentity();

    vec3 T = up;
    vec3 F = centre - eye;
    F.normalise();
    T.normalise();

    vec3 S = vec3::cross_product(F, T);
    S.normalise();
    vec3 U = vec3::cross_product(S, F);
    U.normalise();

    data[0] = S[0];
    data[4] = S[1];
    data[8] = S[2];

    data[1] = U[0];
    data[5] = U[1];
    data[9] = U[2];

    data[2] = -F[0];
    data[6] = -F[1];
    data[10] = -F[2];

    S[0] *= -1;
    S[1] *= -1;
    S[2] *= -1;

    U[0] *= -1;
    U[1] *= -1;
    U[2] *= -1;

    data[12] = vec3::dot_product(S, eye);
    data[13] = vec3::dot_product(U, eye);
    data[14] = vec3::dot_product(F, eye);
}

inline void mat4::setIdentity()
{
    memset(data, 0, sizeof(float) * 16);
    data[0] = data[5] = data[10] = data[15] = 1;
}

mat4 rotate(mat4 matrix, f32 angle, vec3 axis)
{
    axis.normalise();

    float x = axis[x];
    float y = axis[y];
    float z = axis[z];

    float c = cos(angle);
    float s = sin(angle);
    float t = 1.0f - c;

    return mat4{
        t*x*x + c,     t*x*y - s*z, t*x*z + s*y, 0.0f,
        t*x*y + s*z,   t*y*y + c,   t*y*z - s*x, 0.0f,
        t*x*z - s*y,   t*y*z + s*x, t*z*z + c,   0.0f,
        0.0f,          0.0f,        0.0f,        1.0f
    };
}

inline void mat4::rotateX(const float degrees)
{
    const float
        radians = m::degrees_to_radians(degrees),
        cos_theta = cosf(radians),
        sin_theta = sinf(radians);
    float original[8];

    for (size_t i = 0; i < 4; i++)
    {
        original[i] = data[i + 4];
        original[i + 4] = data[i + 8];
    }

    for (size_t i = 0; i < 4; i++)
    {
        data[i + 4] = original[i] * cos_theta - original[i + 4] * (sin_theta);
        data[i + 8] = original[i] * sin_theta + original[i + 4] * cos_theta;
    }
}

inline void mat4::rotateY(const float degs)
{
    const float
        radians = m::degrees_to_radians(degs),
        cos_theta = cosf(radians),
        sin_theta = sinf(radians);
    float original[8];

    for (size_t i = 0; i < 4; i++)
    {
        original[i] = data[i];
        original[i + 4] = data[i + 8];
    }
    for (size_t i = 0; i < 4; i++)
    {
        data[i] = original[i] * cos_theta + original[i + 4] * sin_theta;
        data[i + 8] = original[i + 4] * cos_theta - original[i] * sin_theta;
    }
}

inline void mat4::rotateZ(const float degs)
{
    const float
        radians = m::degrees_to_radians(degs),
        cos_theta = cosf(radians),
        sin_theta = sinf(radians);
    float original[8];

    for (size_t i = 0; i < 8; i++)
    {
        original[i] = data[i];
    }
    for (size_t i = 0; i < 4; i++)
    {
        data[i] = original[i] * cos_theta + original[i + 4] * sin_theta;
        data[i + 4] = original[i + 4] * cos_theta - original[i] * sin_theta;
    }
}

void mat4::set_row(const vec4& vector, const uint32_t row) {
    assert(row < 4);
    const size_t row_index = row * 4;
    data[row_index]     = vector[0];
    data[row_index + 1] = vector[1];
    data[row_index + 2] = vector[2];
    data[row_index + 3] = vector[3];
}

inline void mat4::set_orthographic(const projection& projection)
{
    const f32 m0  = 2 / (projection.right - projection.left);
    const f32 m5  = 2 / (projection.top - projection.bottom);
    const f32 m10 = -2 / (projection.far - projection.near);
    const f32 m12 = -((projection.right + projection.left) / (projection.right - projection.left));
    const f32 m13 = -((projection.top + projection.bottom) / (projection.top - projection.bottom));
    const f32 m14 = -((projection.far + projection.near) / (projection.far - projection.near));

    *this = mat4{
        m0,    0,   0,  0,
         0,   m5,   0,  0,
         0,    0, m10,  0,
       m12, m13,  m14,  1};
}

void mat4::print() const
{
  printf("[ %f, %f, %f, %f\n%f, %f, %f, %f\n%f, %f, %f, %f\n%f, %f, %f, %f]\n",
	data[0], data[1], data[2], data[3],
	data[4], data[5], data[6], data[7],
	data[8], data[9], data[10], data[11],
	data[12], data[13], data[14], data[15]);
}
