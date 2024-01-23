#pragma once
#include <iostream>
#include <string>

namespace aoc {
namespace logging {

using log_level = enum struct LogLevel : char {
    DEBUG   = 1,
    INFO    = 2,
    WARNING = 3,
    ERROR   = 4,
};

using message_t = std::string;

class logger {
    private:
        log_level _level = log_level::INFO;

    public:
        logger(void);
        logger(log_level);
        void set_logging_level(log_level);
        void debug(message_t);
        void info(message_t);
        void warning(message_t);
        void error(message_t);
        void fatal(message_t);
};
inline logger::logger(log_level init_level) {
    _level = init_level;
}

inline void logger::set_logging_level(log_level new_level) {
    _level = new_level;
}

inline void logger::debug(message_t message) {
    if (logger::_level >= log_level::DEBUG) { std::cerr << "|DEBUG| " + message + '\n'; }
}

inline void logger::info(message_t message) {
    if (logger::_level >= log_level::INFO) { std::cout << "|INFO | " + message + '\n'; }
}

inline void logger::warning(message_t message) {
    if (logger::_level >= log_level::WARNING) { std::cerr << "|WARN | " + message + '\n'; }
}

inline void logger::error(message_t message) {
    if (logger::_level >= log_level::ERROR) { std::cerr << "|ERROR| " + message + '\n'; }
}

inline void logger::fatal(message_t message) {
    if (logger::_level >= log_level::ERROR) { std::cerr << "|FATAL| " + message + '\n'; }
    exit(1);
}

} // namespace logging
} // namespace aoc
