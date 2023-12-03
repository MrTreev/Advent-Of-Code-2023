#include <iostream>
#include <array>
#include <string>
#include <algorithm>

static const char ascii_num_lo = 48;
static const char ascii_num_hi = 57;

bool is_numeric(const char c){
    return ascii_num_lo <= c && c <= ascii_num_hi;
}

int find_lhs(std::string line){
    for (std::string::iterator iter = line.begin(); iter != line.end(); ++iter){
        if (is_numeric(*iter)){
            return (*iter - ascii_num_lo);
        }
    }
    std::cout << "ERROR: No Number found" << std::endl;
    exit(1);
}

int find_rhs(std::string line){
    for (std::string::reverse_iterator iter = line.rbegin(); iter != line.rend(); ++iter){
        if (is_numeric(*iter)){
            return (*iter - ascii_num_lo);
        }
    }
    std::cout << "ERROR: No Number found" << std::endl;
    exit(1);
}

bool are_words_in(std::string string){
    static const std::array<std::string, 9> numwrds = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", }
    return std::any_of(numwrds.begin(), numwrds.end(),
            [&](const std::string str){return line.find(str) != std::string::npos});
}

size_t find_rhs_word(std::string line){
}

size_t find_lhs_word(std::string line){
    size_t found = line.find(str);
     if (found != std::string::npos){
         return found;
     } else {
         return line.length();
     }
     return 
}

int main(){
    int total = 0;
    int this_line = 0;
    for (std::string line; std::getline(std::cin, line);){
        std::cout << "Line: " << line << "\n";
        this_line = 10 * find_lhs(line) + find_rhs(line);
        total += this_line;
    }
    std::cout << "Final Total: " << total << std::endl;
}
