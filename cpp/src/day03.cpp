#define AOC_LOGGING_IMPL
#define AOC_CONVERT_IMPL
#define AOC_CHECKS_IMPL
#include "utility/cases.hpp"
#include "utility/logging.hpp"
#include "utility/queues.hpp"
#include <algorithm>
#include <cassert>
#include <string>

static aoc::logging::logger logger(aoc::logging::log_level::DEBUG);

namespace day {
using linebuffer = aoc::queue::FixedQueue<std::string, 3>;
}

bool is_symbol(const char item) {
    switch (item) {
        case '.': return false;
        case aoc_numeric: return false;
        default: return true;
    }
}

void process_number(std::string::iterator li, std::string line) {
    // TODO
    // extract number
    // replace with '.' characters
    li++;
    line += "hi";
}

void process_line(day::linebuffer linebuf) {
    assert(sizeof(linebuf[0]) == sizeof(linebuf[1]) == sizeof(linebuf[2]));
    for (                                                                                                //
        std::string::iterator pi = linebuf[0].begin(), li = linebuf[1].begin(), ni = linebuf[2].begin(); //
        pi != linebuf[0].end() && li != linebuf[1].end() && ni != linebuf[2].end();                      //
        pi++, li++, ni++                                                                                 //
    ) {
        if (std::any_of(pi - 1, pi + 1, is_symbol) || //
            std::any_of(li - 1, li + 1, is_symbol) || //
            std::any_of(ni - 1, ni + 1, is_symbol)) { //
            process_number(li, linebuf[1]);
        }
    }
}

int main() {
    std::string     line;
    day::linebuffer linebuf;
    for (; std::getline(std::cin, line);) {
        linebuf.push(line);
        if (linebuf.is_full()) { process_line(linebuf); }
    }
    return 0;
}
