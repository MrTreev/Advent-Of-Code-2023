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
    if (logger::_level >= log_level::DEBUG) { std::cout << "|DEBUG| " + message; }
}

void logger::info(message_t message) {
    if (logger::_level >= log_level::INFO) { std::cout << "|INFO | " + message; }
}

void logger::warning(message_t message) {
    if (logger::_level >= log_level::WARNING) { std::cout << "|WARN | " + message; }
}

void logger::error(message_t message) {
    if (logger::_level >= log_level::ERROR) { std::cout << "|ERROR| " + message; }
}

void logger::fatal(message_t message) {
    if (logger::_level >= log_level::ERROR) { std::cout << "|FATAL| " + message; }
    exit(1);
}

} // namespace logging
} // namespace aoc
