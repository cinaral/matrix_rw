#ifndef TYPES_HPP_CINARAL_220924_0017
#define TYPES_HPP_CINARAL_220924_0017

#include <string>

namespace matrix_rw
{
using uint_t = unsigned long long int;
#ifdef __USE_SINGLE_PRECISION__
using real_t = float;
#else
using real_t = double;
#endif

constexpr std::string_view delimiter = ",";
} // namespace matrix_rw

#endif