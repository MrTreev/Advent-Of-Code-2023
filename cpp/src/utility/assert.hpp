#pragma once

#define aoc_static_assert_inside(val, min, max, msg) static_assert(min <= val && val < max, msg)
#define aoc_static_assert_max(val, max, msg) aoc_static_assert_inside(val, 0, max, msg)

#define aoc_static_assert_ge(val, cmp, msg) static_assert(val >= cmp, msg)
#define aoc_static_assert_gt(val, cmp, msg) static_assert(val > cmp, msg)
#define aoc_static_assert_le(val, cmp, msg) static_assert(val <= cmp, msg)
#define aoc_static_assert_lt(val, cmp, msg) static_assert(val < cmp, msg)

//! shortcuts
#define aoc_sa_inside aoc_static_assert_inside
#define aoc_sa_max aoc_static_assert_max

#define aoc_sa_ge aoc_static_assert_ge
#define aoc_sa_gt aoc_static_assert_gt
#define aoc_sa_le aoc_static_assert_le
#define aoc_sa_lt aoc_static_assert_lt
