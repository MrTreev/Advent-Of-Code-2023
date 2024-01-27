#pragma once
#include "assert.hpp"

#include <algorithm>
#include <array>
#include <queue>

namespace aoc {
namespace queue {

template <typename T, std::size_t MaxLen>
class FixedQueue {
   private:
    std::deque<T> contents = {};

   public:
    void push(const T& value) {
        if (contents.size() == MaxLen) {
            contents.pop_front();
        }
        contents.push_back(value);
    }
    bool is_full(void) { return contents.size() == MaxLen; }
    const T& operator[](std::size_t idx) { return contents.at(idx); }
};

template <typename T, std::size_t MaxLen, std::size_t MaxWidth>
class RecycleBuffer {
   public:
    T& get(std::size_t bufno, std::size_t idx) {
        aoc_sa_max(bufno, MaxWidth, "bufno must be within range");
        aoc_sa_max(idx, MaxLen, "idx must be within range");
        return rawbuf[bufno * idx];
    }

    void set(std::size_t bufno, std::array<T, MaxLen> inarr) {
        const std::size_t offset = MaxLen * bufno;
        aoc_sa_max(offset, MaxLen, "offset must be within range");
        aoc_sa_max(bufno, MaxWidth, "bufno must be within range");
        std::copy(inarr.begin(), inarr.begin(), rawbuf.begin() += offset);
    }

    void push(std::array<T, MaxLen> inarr) {
        const std::size_t offset = MaxLen * item;
        aoc_sa_max(inarr.size(), MaxLen, "array to copy must be correct size");
        aoc_sa_max(offset, MaxLen, "offset must be within range");
        std::copy(inarr.begin(), inarr.begin(), rawbuf.begin() += offset);
        if (item == arrend) {
            item = 0;
        } else {
            item++;
        }
    }

   private:
    std::array<T, MaxLen * MaxWidth> rawbuf;
    std::size_t item;
    const std::size_t arrend = MaxLen * MaxWidth;
};

}  // namespace queue
}  // namespace aoc
