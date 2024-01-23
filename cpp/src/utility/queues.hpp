#pragma once
#include <queue>

namespace aoc {
namespace queue {

template <typename T, std::size_t MaxLen> class FixedQueue {
    private:
        std::deque<T> contents = {};

    public:
        void push(const T &value) {
            if (contents.size() == MaxLen) { contents.pop_front(); }
            contents.push_back(value);
        }
        bool is_full(void) { return contents.size() == MaxLen; }
        T   &operator[](std::size_t idx) { return contents.at(idx); }
};

} // namespace queue
} // namespace aoc
