#include <cassert>
#include <iostream>
#include "utility/queues.hpp"

constexpr std::size_t line_length = 140;
constexpr std::size_t buffer_size = 3;

using multiline = aoc::queue::RecycleBuffer<char, line_length, buffer_size>;

template <typename T, std::size_t L>
std::array<T, L> cleanline(std::string line) {
    assert(line.length() == L);
    std::array<T, L> thisline;
    std::copy(line.begin(), line.end(), thisline.data());
    return thisline;
}

int main() {
    multiline buffer;
    for (std::string line; std::getline(std::cin, line);) {
        assert(line.length() == line_length);
        const auto thisline = cleanline<char, line_length>(line);
    }
    return 0;
}
