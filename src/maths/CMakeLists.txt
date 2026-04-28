set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_library(maths STATIC
	vec2.cpp
	vec3.cpp
	vec4.cpp
	mat4.cpp
	matrix_transformations.cpp
	catmullrom.cpp
	frenet_serret.cpp
	general.cpp)

target_include_directories(maths PUBLIC
				 ${CMAKE_CURRENT_SOURCE_DIR}/include)
