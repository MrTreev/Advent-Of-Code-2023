#include <string>

#include "utility/cases.hpp"
#include "utility/logging.hpp"

static aoc::logging::logger logger(aoc::logging::log_level::DEBUG);
static const std::size_t r_cubes_max = 12;
static const std::size_t g_cubes_max = 13;
static const std::size_t b_cubes_max = 14;
static std::size_t r_no = 0;
static std::size_t g_no = 0;
static std::size_t b_no = 0;
static std::size_t r_max = 0;
static std::size_t g_max = 0;
static std::size_t b_max = 0;
static std::size_t this_no = 0;
static std::string::iterator word_break;

std::size_t get_game_id(std::string line) {
    std::size_t retval = 0;
    for (std::string::iterator iter = line.begin() + 4;
         *iter != ':' && iter != line.end(); ++iter) {
        if ('0' <= *iter && *iter <= '9') {
            retval *= 10;
            retval += (*iter - '0');
        }
    }
    return retval;
}

std::size_t process_amount(const char first, const char secnd) {
    std::size_t retval = 0;
    if ('0' <= first && first <= '9') {
        retval = first - '0';
    }
    if ('0' <= secnd && secnd <= '9') {
        retval *= 10;
        retval += (secnd - '0');
    } else {
        logger.fatal("Invalid ASCII value");
        return retval; /* unreachable, but silences incorrect warning */
    }
    return retval;
}

void process_word(std::string::iterator iter) {
    std::string this_word = std::string(word_break, iter);
    if (this_word == "red") {
        r_no += this_no;
    } else if (this_word == "green") {
        g_no += this_no;
    } else if (this_word == "blue") {
        b_no += this_no;
    } else {
        logger.fatal("Failed to identify colour");
    }
    this_no = 0;
}

bool validate_game(const bool is_valid) {
    bool local_valid = true;
    if (r_no > r_cubes_max) {
        local_valid = false;
    }
    if (g_no > g_cubes_max) {
        local_valid = false;
    }
    if (b_no > b_cubes_max) {
        local_valid = false;
    }
    if (r_no > r_max) {
        r_max = r_no;
    }
    if (g_no > g_max) {
        g_max = g_no;
    }
    if (b_no > b_max) {
        b_max = b_no;
    }
    logger.debug(
        std::string("Valid: ") + (local_valid ? "YES " : "NO  ") +
        "\tR:" + std::to_string(r_no) + "/" + std::to_string(r_cubes_max) +
        "\tG:" + std::to_string(g_no) + "/" + std::to_string(g_cubes_max) +
        "\tB:" + std::to_string(b_no) + "/" + std::to_string(b_cubes_max) +
        "\tMax: R" + std::to_string(r_max) + " G" + std::to_string(g_max) +
        " B" + std::to_string(b_max));
    r_no = 0, g_no = 0, b_no = 0;
    return is_valid && local_valid;
}

std::size_t valid_game_no(std::string& line) {
    const std::size_t game_id = get_game_id(line);
    const std::size_t g_token = line.find(':') + 2;
    if (g_token == std::string::npos) {
        logger.fatal("No ':' found\nIn line: " + line);
    }
    this_no = 0;
    r_no = 0, g_no = 0, b_no = 0;
    bool is_valid = true;
    for (std::string::iterator iter = line.begin() + g_token;
         iter != line.end(); iter++) {
        switch (*iter) {
            case ';':
                process_word(iter);
                is_valid = validate_game(is_valid);
                word_break = iter + 2;
                break;
            case ',':
                process_word(iter);
                word_break = iter + 2;
                break;
            case ' ':
                if (*(iter - 1) != ',' && *(iter - 1) != ';') {
                    this_no = process_amount(*(iter - 2), *(iter - 1));
                    word_break = iter + 1;
                }
                break;
            case aoc_numeric:
                break;
            case aoc_alpha:
                break;
            default:
                logger.fatal("Unrecognised Character: '" +
                             std::to_string(*iter) + "'\nIn line: " + line);
        }
    }
    process_word(line.end());
    is_valid = validate_game(is_valid);
    if (is_valid) {
        return game_id;
    }
    return 0;
}

int main() {
    std::size_t total = 0;
    std::size_t power = 0;
    for (std::string line; std::getline(std::cin, line);) {
        const std::size_t this_game_no = valid_game_no(line);
        const std::string this_game = line.substr(5, 3);
        const std::size_t this_power = r_max * g_max * b_max;
        total += this_game_no;
        power += this_power;
        logger.info(std::string("Valid: ") +
                    ((this_game_no != 0) ? "YES" : "NO ") +
                    " Power: " + std::to_string(this_power) +
                    "\tTotal: " + std::to_string(total) + line);
        r_max = 0, g_max = 0, b_max = 0;
    }
    logger.info("Final Total: " + std::to_string(total));
    logger.info("Final Power: " + std::to_string(power));
    return 0;
}
