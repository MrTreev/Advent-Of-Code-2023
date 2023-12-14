#include <iostream>
#include <list>

#include "../day00/utility.h"

const int r_cubes = 12;
const int g_cubes = 13;
const int b_cubes = 14;


int game_number(std::string line) {
    int return_value = 0;
    for (std::string::iterator iter = line.begin() + 5; *iter != ':'; ++iter) {
        if (ascii_min_numeric <= *iter && *iter <= ascii_max_numeric) {
            return_value *= 10;
            return_value += *iter - ascii_min_numeric;
        }
    }
    return return_value;
}

int valid_game_id(std::string line) { return 0; }

std::list<std::string> split_game(std::string line) {
    std::list<std::string> return_list;
    std::string::iterator start_char = line.begin();
    for (std::string::iterator iter = line.begin(); iter != line.end(); ++iter) {
        if (*iter == ';' || *iter == ':') {
            std::string ret_string = std::string(start_char, iter);
            return_list.push_back(ret_string);
            start_char = iter + 2;
        }
    }
    return_list.pop_front();
    return return_list;
}

std::pair<int, char> pair_item(std::string item) {
    std::string::iterator inchar = item.begin();
    for (std::string::iterator initer = item.begin(); initer != item.end(); ++initer) {
        if (*initer == ' ') {
            std::string ret_val = std::string(inchar, initer);
            inchar = initer + 1;
            char ret_char = *(initer + 1);
            auto ret_pair = std::pair(str_to_int(ret_val), ret_char);
            return ret_pair;
        }
    }
    return std::pair(0, 'x');
}

std::list<std::pair<int, char>> get_items(std::string segment) {
    std::list<std::pair<int, char>> ret_list;
    std::string::iterator start_char = segment.begin();
    for (std::string::iterator iter = segment.begin(); iter != segment.end(); ++iter) {
        if (*iter == ',') {
            std::string ret_string = std::string(start_char, iter);
            std::pair ret_item = pair_item(ret_string);
            ret_list.push_back(ret_item);
            start_char = iter + 2;
        }
    }
    return ret_list;
}

int main() {
    int total;
    for (std::string line; std::getline(std::cin, line);) {
        const int game_no = game_number(line);
        std::list<std::string> game_list = split_game(line);
        for (auto iter = std::_List_iterator(game_list.begin()); iter != game_list.end(); ++iter) {
            get_items(*iter);
        }
    }
    std::cout << "Final Total: " << total << std::endl;
    return 0;
}
