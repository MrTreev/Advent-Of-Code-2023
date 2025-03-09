#ifndef INCLUDE_C_AOC_H_
#define INCLUDE_C_AOC_H_
#ifdef __cplusplus
extern "C" {
#endif

#if __STDC__ != 1
#	error "Not a standard compliant compiler"
#endif

#include <stddef.h>

#if defined(AOC_REPRODUCE) || defined(SOURCE_DATE_EPOCH)
#	define __DATE__ 0
#	define __TIME__ 0
#	define __TIMESTAMP__ 0
#endif

#if __STDC_VERSION__ >= 199901L && 199901L
#	include <stdbool.h>
#	ifndef __bool_true_false_are_defined
#		define bool _Bool
#		define false 0
#		define true 1
#		define __bool_true_false_are_defined 1
#	endif
#else
#	ifndef __bool_true_false_are_defined
#		define bool unsigned char;
#		define false 0
#		define true 1
#		define __bool_true_false_are_defined 1
#	endif
#endif

#ifndef AOC_ASSERT
#	include <assert.h>
#	define AOC_ASSERT(x) assert(x)
#endif

#ifndef AOC_CC
#	define AOC_CC "clang"
#endif

#ifndef AOC_C_ARGS
#	define AOC_C_ARGS "-std=c89"
#endif

#ifndef AOC_C_WARN
#	define AOC_C_WARN "-Wall", "-Wextra", "-pedantic"
#endif

#ifndef AOC_PROJ_PATH
#	define AOC_PROJ_PATH "."
#endif

#ifndef AOC_PATH_SEP
#	define AOC_PATH_SEP "/"
#endif

#ifndef AOC_PATH_JOIN
#	define AOC_PATH_JOIN(a, b) a AOC_PATH_SEP b
#endif

#ifndef AOC_SRC_PATH
#	define AOC_SRC_PATH AOC_PATH_JOIN(AOC_PROJ_PATH, "src")
#endif

#ifndef AOC_HDR_PATH
#	define AOC_HDR_PATH AOC_PATH_JOIN(AOC_PROJ_PATH, "src")
#endif

#ifndef AOC_OBJ_PATH
#	define AOC_OBJ_PATH AOC_PATH_JOIN(AOC_PROJ_PATH, "bld")
#endif

#ifndef AOC_SRC_FILE
#	define AOC_SRC_FILE(x) AOC_PATH_JOIN(AOC_SRC_PATH, x ".c")
#endif

#ifndef AOC_HDR_FILE
#	define AOC_HDR_FILE(x) AOC_PATH_JOIN(AOC_SRC_PATH, x ".h")
#endif

#ifndef AOC_OBJ_FILE
#	define AOC_OBJ_FILE(x) AOC_PATH_JOIN(AOC_OBJ_PATH, x ".o")
#endif

#define AOC_UNUSED(value) (void)(value)
#define AOC_TODO(message) implaoc_todo(message, __FILE__, __LINE__)
#define AOC_UNREACHABLE(message) implaoc_unreachable(message, __FILE__, __LINE__)

#define AOC_ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define AOC_ARRAY_GET(array, index) (AOC_ASSERT((size_t)index < AOC_ARRAY_LEN(array)), array[(size_t)index])

#define AOC_MAKE_CMD(name) struct AocBuildCmd name = {NULL, 0, 0};
#define AOC_REBUILD_SELF(argc, argv) implaoc_rebuild_self(argc, argv, __FILE__, NULL)

#define AOC_START() (void)(0)
#define AOC_END() return 0

/* FUNCTION MACROS */
#define aoc_shift(xs, xs_sz) (AOC_ASSERT((xs_sz) > 0), (xs_sz)--, *(xs)++)

/* Structures */
struct AocBuildCmd {
	const char **items;
	size_t count;
	size_t capacity;
};

struct Nob_File_Paths {
	const char **items;
	size_t count;
	size_t capacity;
};

/* Implementation Functions */
void implaoc_todo(const char *message, const char *file, const int line);
void implaoc_unreachable(const char *message, const char *file, const int line);
void implaoc_rebuild_self(int argc, char **argv, const char *source_path, ...);
const char *implaoc_temp_sprintf(const char *format, ...);

#ifdef __cplusplus
}
#endif
#endif // INCLUDE_C_AOC_H_
