#ifndef AOC_LOGGING_HPP_
#define AOC_LOGGING_HPP_
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
        log_level           _level = log_level::INFO;

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

} // namespace logging
} // namespace aoc

#ifdef AOC_LOGGING_IMPL
#include "impl/logging.cpp"
#endif

#endif
