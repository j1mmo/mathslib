#ifndef MAT4_H
#define MAT4_H

#include "vec3.hpp"
#include "vec4.hpp"
#include <cstddef>

struct projection {
  f32 left, right, bottom, top, near, far;
};

struct mat4
{
  f32 data[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
  };

  enum class col { vec4 };
  enum class row { vec4 };

  mat4();
  explicit mat4(f32 value);
  mat4(f32 m00, f32 m01, f32 m02, f32 m03,
       f32 m10, f32 m11, f32 m12, f32 m13,
       f32 m20, f32 m21, f32 m22, f32 m23,
       f32 m30, f32 m31, f32 m32, f32 m33);

  float& operator[](uint32_t index);
  float  operator[](uint32_t index) const;

  float& operator()(size_t row, size_t col);
  float  operator()(uint32_t row, uint32_t col) const;
  vec4   operator()(row row, size_t index) const;
  vec4   operator()(col col, size_t index) const;
  mat4&  operator*=(const mat4& other);
  mat4&  operator+=(const mat4& other);
  mat4&  operator-=(const mat4& other);

  void setIdentity();

  void rotateX(f32 degrees);
  void rotateY(f32 degrees);
  void rotateZ(f32 degrees);
  void set_row(const vec4& vector, uint32_t row);
  void set_orthographic(const projection& projection);
  void set_frustum(const projection& projection);
  void setLookAt(const vec3& eye, const vec3& centre, const vec3& up);

  static mat4 setPerspective(float fov, float aspectRatio, float near, float far);
  static mat4 lookAt(const vec3& eye, const vec3& center, const vec3& up);
  
  void print() const;
};


vec4 operator*(mat4 lhs, const vec4& rhs);
mat4 operator*(mat4 lhs, const mat4& rhs);
mat4 operator+(mat4 lhs, const mat4& rhs);
mat4 operator-(mat4 lhs, const mat4& rhs);

#endif //MAT4_H
