#include <matrix_transformations.hpp>

mat4 rotate(const mat4& m, float angle, vec3 axis)
{
    axis.normalise();

    float x = axis[0];
    float y = axis[1];
    float z = axis[2];

    float c = cos(angle);
    float s = sin(angle);
    float t = 1.0f - c;

    mat4 r{};

    r(0, 0) = t*x*x + c;
    r(0, 1) = t*x*y + s*z;
    r(0, 2) = t*x*z - s*y;
    r(0, 3) = 0.0f;

    r(1, 0) = t*x*y - s*z;
    r(1, 1) = t*y*y + c;
    r(1, 2) = t*y*z + s*x;
    r(1, 3) = 0.0f;

    r(2, 0) = t*x*z + s*y;
    r(2, 1) = t*y*z - s*x;
    r(2, 2) = t*z*z + c;
    r(2, 3) = 0.0f;

    r(3, 0) = 0.0f;
    r(3, 1) = 0.0f;
    r(3, 2) = 0.0f;
    r(3, 3) = 1.0f;

    return m * r;
}

mat4 translate(const mat4& m, const vec3& v)
{
  mat4 t{};

  t(0, 3) = v[0];
  t(1, 3) = v[1];
  t(2, 3) = v[2];

  t.print();
  return m * t;
}

mat4 scale(const mat4& m, const vec3& v)
{
  mat4 s{};

  s(0, 0) = v[0];
  s(1, 1) = v[1];
  s(2, 2) = v[2];

  return m * s;
}
