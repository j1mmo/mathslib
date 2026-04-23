cmake_minimum_required(VERSION 3.24) 
include(FetchContent)
option(BUILD_GMOCK OFF)
option(INSTALL_GTEST OFF)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(maths_lib_tests
	main.cpp
	helper.cpp
	vec3_t.cpp
	vec4_t.cpp
	mat4_t.cpp
	matrix_transformations_t.cpp)

target_link_libraries(maths_lib_tests
	PRIVATE GTest::GTest
	maths)

target_compile_options(maths PRIVATE -Wno-comma-subscript)

add_test(maths_lib_gtests maths_lib_tests)
