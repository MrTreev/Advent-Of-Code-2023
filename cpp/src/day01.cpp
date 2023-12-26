#include <algorithm>
#include <iostream>

#include "aoc-utility.h"

bool is_numeric(const char character) { return ascii_min_numeric <= character && character <= ascii_max_numeric; }

std::size_t are_words_in(std::string full_string) {
    return std::any_of(numbers_as_words.begin(), numbers_as_words.end(),
                       [&](const std::string str) { return full_string.find(str) != std::string::npos; });
}

int find_lhs(std::string line) {
    for (std::string::iterator iter = line.begin(); iter != line.end();
         ++iter) {
        if (is_numeric(*iter)) {
            return (*iter - ascii_min_numeric);
        }
    }
    std::cout << "ERROR: No Number found" << std::endl;
    exit(1);
}

int find_rhs(std::string line) {
    for (std::string::reverse_iterator iter = line.rbegin();
         iter != line.rend(); ++iter) {
        if (is_numeric(*iter)) {
            return (*iter - ascii_min_numeric);
        }
    }
    std::cout << "ERROR: No Number found" << std::endl;
    exit(1);
}

int part1_main() {
    int total = 0;
    int this_line = 0;
    for (std::string line; std::getline(std::cin, line);) {
        std::cout << "Line: " << line << "\n";
        this_line = 10 * find_lhs(line) + find_rhs(line);
        total += this_line;
    }
    std::cout << "Final Total: " << total << std::endl;
    return 0;
}

int main() {
    int total = 0;
    int this_line = 0;
    for (std::string line; std::getline(std::cin, line);) {
        this_line = 0;
        std::cout << "Line: " << line << "\t\tNumber: " << this_line << "\n";
        total += this_line;
    }
    std::cout << "Final Total: " << total << std::endl;
    return 0;
}
