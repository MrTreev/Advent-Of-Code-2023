/**
 * @file Utility functions for Advent of Code 2023
 */

#ifndef AOC_UTILITY_H
#define AOC_UTILITY_H

#include <array>
#include <string>

const char ascii_min_numeric = 48;
const char ascii_max_numeric = 57;

const std::array<const std::string, 9> numbers_as_words = {"one", "two",   "three", "four", "five",
                                                           "six", "seven", "eight", "nine"};

/**
 * @brief converts an std::string to an int with the contained value
 *
 * @param in_string: a std::string containing only the number to convert
 *
 */
int aoc_str_to_int(std::string in_string);

#endif
