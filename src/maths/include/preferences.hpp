#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <cstdint>

// Signed integers
using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

// Unsigned integers
using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

// Floating point
using f32 = float;
using f64 = double;
using f128 = long double; // not always true 128-bit, but largest available

// Boolean
using b8 = bool;

// Character types
using c8  = char;
using c16 = char16_t;
using c32 = char32_t;
using wc  = wchar_t;

#endif //PREFERENCES_H
