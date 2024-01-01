#include "../checks.hpp"

bool aoc::checks::is_numeric(const char character) {
    return '0' <= character && character <= '9';
}
