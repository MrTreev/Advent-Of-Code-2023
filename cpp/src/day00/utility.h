#include <array>
#include <string>

const char ascii_min_numeric = 48;
const char ascii_max_numeric = 57;
const std::array<const std::string, 9> numbers_as_words = {"one", "two",   "three", "four", "five",
                                                           "six", "seven", "eight", "nine"};

int str_to_int(std::string in_string);
