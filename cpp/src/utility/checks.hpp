#ifndef AOC_CHECKS_HPP_
#define AOC_CHECKS_HPP_

namespace aoc {
namespace checks {

bool is_numeric(const char character);

} // namespace checks
} // namespace aoc

#ifdef AOC_CHECKS_IMPL
#include "impl/checks.cpp"
#endif

#endif
