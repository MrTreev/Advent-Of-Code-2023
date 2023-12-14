#include "utility.h"

int str_to_int(std::string in_string) {
    int out_int = 0;
    for (std::string::iterator iter = in_string.begin(); iter != in_string.end(); ++iter) {
        if (ascii_min_numeric <= *iter && *iter <= ascii_max_numeric) {
            out_int *= 10;
            out_int += *iter - ascii_min_numeric;
        }
    }
    return out_int;
}

