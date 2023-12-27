#ifndef AOC_UTILITY_H
#define AOC_UTILITY_H
#include <array>
#include <iostream>
#include <string>

#ifdef AOC_LEVEL_DEBUG
#define AOC_DEBUG(log) std::cout << "DEBUG: " << log << std::endl
#else
#define AOC_DEBUG(log)
#endif

// clang-format off
#define AOC_ERROR(log) std::cerr << "ERROR: " << log << std::endl
#define AOC_FATAL(log) std::cerr << "FATAL: " << log << std::endl; exit(1)
#define AOC_LOG(log)   std::cout << log << std::endl

#define AOC_CASE_ALNUM\
        '0':case'1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':\
    case'a':case'b':case'c':case'd':case'e':case'f':case'g':case'h':case'i':case'j':case'k':case'l':case'm':\
    case'n':case'o':case'p':case'q':case'r':case's':case't':case'u':case'v':case'w':case'x':case'y':case'z':\
    case'A':case'B':case'C':case'D':case'E':case'F':case'G':case'H':case'I':case'J':case'K':case'L':case'M':\
    case'N':case'O':case'P':case'Q':case'R':case'S':case'T':case'U':case'V':case'W':case'X':case'Y':case'Z'
#define AOC_CASE_ALPHA\
        'a':case'b':case'c':case'd':case'e':case'f':case'g':case'h':case'i':case'j':case'k':case'l':case'm':\
    case'n':case'o':case'p':case'q':case'r':case's':case't':case'u':case'v':case'w':case'x':case'y':case'z':\
    case'A':case'B':case'C':case'D':case'E':case'F':case'G':case'H':case'I':case'J':case'K':case'L':case'M':\
    case'N':case'O':case'P':case'Q':case'R':case'S':case'T':case'U':case'V':case'W':case'X':case'Y':case'Z'
#define AOC_CASE_UPPER\
        'A':case'B':case'C':case'D':case'E':case'F':case'G':case'H':case'I':case'J':case'K':case'L':case'M':\
    case'N':case'O':case'P':case'Q':case'R':case'S':case'T':case'U':case'V':case'W':case'X':case'Y':case'Z'
#define AOC_CASE_LOWER\
        'a':case'b':case'c':case'd':case'e':case'f':case'g':case'h':case'i':case'j':case'k':case'l':case'm':\
    case'n':case'o':case'p':case'q':case'r':case's':case't':case'u':case'v':case'w':case'x':case'y':case'z'
#define AOC_CASE_NUMBER\
        '0':case'1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9'
// clang-format on

const char aoc_ascii_min_numeric = '0';
const char aoc_ascii_max_numeric = '9';

const std::array<const std::string, 9> aoc_numbers_as_words = {"one", "two",   "three", "four", "five",
                                                               "six", "seven", "eight", "nine"};

int  aoc_str_to_int(std::string in_string);
int  aoc_word_to_int(std::string in_string);
bool aoc_is_numeric(const char character);

#endif

#ifdef AOC_UTILITY_IMPL
bool aoc_is_numeric(const char character) {
    return aoc_ascii_min_numeric <= character && character <= aoc_ascii_max_numeric;
}

int aoc_str_to_int(std::string in_string) {
    int out_int = 0;
    for (std::string::iterator iter = in_string.begin(); iter != in_string.end(); ++iter) {
        if (aoc_is_numeric(*iter)) {
            out_int *= 10;
            out_int += *iter - aoc_ascii_min_numeric;
        }
    }
    return out_int;
}

int aoc_word_to_int(std::string in_string) {
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
#endif
