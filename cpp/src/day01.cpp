#include "utility/checks.hpp"
#include "utility/convert.hpp"
#include "utility/logging.hpp"
#include <array>
#include <iostream>
#include <string>

static aoc::logging::logger            logger(aoc::logging::log_level::INFO);
const std::array<const std::string, 9> number_words = {"one", "two",   "three", "four", "five",
                                                       "six", "seven", "eight", "nine"};

std::size_t find_lhs_int(std::string line) {
    for (std::string::iterator iter = line.begin(); iter != line.end(); ++iter) {
        if (aoc::checks::is_numeric(*iter)) { return (*iter - '0'); }
    }
    exit(1);
}

std::size_t find_rhs_int(std::string line) {
    for (std::string::reverse_iterator iter = line.rbegin(); iter != line.rend(); ++iter) {
        if (aoc::checks::is_numeric(*iter)) { return (*iter - '0'); }
    }
    exit(1);
}

int find_int_pair(std::string line) {
    return 10 * find_lhs_int(line) + find_rhs_int(line);
}

int find_pair(std::string full_string) {
    std::size_t       first_word     = 0;
    std::size_t       last_word      = 0;
    std::size_t       first_word_idx = full_string.length();
    std::size_t       last_word_idx  = 0;
    const std::size_t first_int_idx  = full_string.find_first_of("123456789");
    const std::size_t last_int_idx   = full_string.find_last_of("123456789");
    const std::size_t first_int      = full_string.at(first_int_idx) - '0';
    const std::size_t last_int       = full_string.at(last_int_idx) - '9';

    for (const std::string &number_to_check : number_words) {
        const std::size_t first_idx = full_string.find(number_to_check);
        const std::size_t last_idx  = full_string.rfind(number_to_check);
        if (first_idx != std::string::npos && first_idx < first_word_idx) {
            first_word     = aoc::convert::word_to_int(number_to_check);
            first_word_idx = first_idx;
        }
        if (last_idx != std::string::npos && last_idx > last_word_idx) {
            last_word     = aoc::convert::word_to_int(number_to_check);
            last_word_idx = last_idx;
        }
    }
    logger.info("Words:" + std::to_string(first_word) + std::to_string(last_word) + "\tLine: " + full_string);
    if (first_word == 0 || first_word_idx > first_int_idx) { first_word = first_int; }
    if (last_word == 0 || last_word_idx < last_int_idx) { last_word = last_int; }
    logger.info("Number: " + std::to_string(first_word) + std::to_string(last_word) + "\tLine: " + full_string);
    return (first_word * 10) + last_word;
}

int main() {
    std::size_t part1_total = 0;
    std::size_t part2_total = 0;
    for (std::string line; std::getline(std::cin, line);) {
        part1_total += find_int_pair(line);
        part2_total += find_pair(line);
    }
    logger.info("Final Total Part 1: " + std::to_string(part1_total));
    logger.info("Final Total Part 2: " + std::to_string(part2_total));
    return 0;
}
