#include "../logging.hpp"
#include <iostream>

namespace aoc {
namespace logging {

logger::logger(log_level init_level){
    _level = init_level;
}

void logger::set_logging_level(log_level new_level) {
    _level = new_level;
}

void logger::debug(message_t message) {
    if (logger::_level >= log_level::DEBUG) { std::cerr << "|DEBUG| " + message + '\n'; }
}

void logger::info(message_t message) {
    if (logger::_level >= log_level::INFO) { std::cout << "|INFO | " + message + '\n'; }
}

void logger::warning(message_t message) {
    if (logger::_level >= log_level::WARNING) { std::cerr << "|WARN | " + message + '\n'; }
}

void logger::error(message_t message) {
    if (logger::_level >= log_level::ERROR) { std::cerr << "|ERROR| " + message + '\n'; }
}

void logger::fatal(message_t message) {
    if (logger::_level >= log_level::ERROR) { std::cerr << "|FATAL| " + message + '\n'; }
    exit(1);
}

} // namespace logging
} // namespace aoc
