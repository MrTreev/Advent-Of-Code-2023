#pragma once

namespace aoc {
namespace checks {

constexpr bool is_numeric(const char character) {
    return '0' <= character && character <= '9';
}

} // namespace checks
} // namespace aoc
