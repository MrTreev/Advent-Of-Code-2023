#define AOC_UTILITY_IMPL
#define AOC_LEVEL_DEBUG
#include "aoc-utility.h"

int main() {
    for (std::string line; std::getline(std::cin, line);) {
        AOC_DEBUG(line);
    }
    return 0;
}
