#ifndef AOC_CONVERT_HPP_
#define AOC_CONVERT_HPP_
#include <string>

namespace aoc {
namespace convert {

std::size_t str_to_int(std::string in_string);
std::size_t word_to_int(std::string in_string);

} // namespace convert
} // namespace aoc

#ifdef AOC_CONVERT_IMPL
#include "impl/convert.cpp"
#endif

#endif
