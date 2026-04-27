#include <gtest/gtest.h>

#include <catmullrom.hpp>

TEST(catmull_rom_t, vec3_catmull_rom_solver)
{
  vec3 p0{0.0f, 0.0f, 0.0f};
  vec3 p1{2.0f, 3.0f, 1.0f};
  vec3 p2{3.0f, 8.0f, 6.0f};
  vec3 p3{12.0f, 13.0f, 14.0f};
      
  vec3 start = maths::catmull_rom_solver(p0, p1, p2, p3, 0.0f);
  vec3 end = maths::catmull_rom_solver(p0, p1, p2, p3, 1.0f);
  ASSERT_EQ(start[0], 2.0f);
  ASSERT_EQ(start[1], 3.0f);
  ASSERT_EQ(start[2], 1.0f);
  
  ASSERT_EQ(end[0], 3.0f);
  ASSERT_EQ(end[1], 8.0f);
  ASSERT_EQ(end[2], 6.0f);
}
