#include <iostream>
#include <array>
#include <string>
#include <algorithm>

static const char ascii_num_lo = 48;
static const char ascii_num_hi = 57;
static const std::array<std::string, 9> numwrds = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

bool is_numeric(const char character){
    return ascii_num_lo <= character && character <= ascii_num_hi;
}

bool are_words_in(std::string full_string){
    return std::any_of(numwrds.begin(), numwrds.end(),
            [&](const std::string str){return full_string.find(str) != std::string::npos;});
}

std::string tokenise(std::string orig_string){
    std::string new_string;
    new_string.append();
    return new_string;
}

int main(){
    int total = 0;
    int this_line = 0;
    for (std::string line; std::getline(std::cin, line);){
        this_line = 0;
        std::cout << "Line: " << line << "\t\tNumber: " << this_line << "\n";
        total += this_line;
    }
    std::cout << "Final Total: " << total << std::endl;
}
