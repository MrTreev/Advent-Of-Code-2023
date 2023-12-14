#include <algorithm>
#include <iostream>

#include "../day00/utility.h"

bool is_numeric(const char character) { return ascii_min_numeric <= character && character <= ascii_max_numeric; }

std::size_t are_words_in(std::string full_string) {
    return std::any_of(numbers_as_words.begin(), numbers_as_words.end(),
                       [&](const std::string str) { return full_string.find(str) != std::string::npos; });
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
