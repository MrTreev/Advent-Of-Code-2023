#include "../convert.hpp"
#include "../checks.hpp"

std::size_t aoc::convert::str_to_int(std::string in_string) {
    int out_int = 0;
    for (std::string::iterator iter = in_string.begin(); iter != in_string.end(); ++iter) {
        if (aoc::checks::is_numeric(*iter)) {
            out_int *= 10;
            out_int += *iter - '0';
        }
    }
    return out_int;
}

std::size_t aoc::convert::word_to_int(std::string in_string) {
    if (in_string == "one") {
        return 1;
    } else if (in_string == "two") {
        return 2;
    } else if (in_string == "three") {
        return 3;
    } else if (in_string == "four") {
        return 4;
    } else if (in_string == "five") {
        return 5;
    } else if (in_string == "six") {
        return 6;
    } else if (in_string == "seven") {
        return 7;
    } else if (in_string == "eight") {
        return 8;
    } else if (in_string == "nine") {
        return 9;
    } else {
        return 0;
    }
}
