#include "aoc.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void _aoc_impl_todo(const char *message, const char *file, const int line)
{
	fprintf(stderr, "%s:%d: TODO: %s\n", file, line, message);
	abort();
}

void _aoc_impl_unreachable(const char *message, const char *file, const int line)
{
	fprintf(stderr, "%s:%d: UNREACHABLE: %s\n", file, line, message);
	abort();
}

const char *implaoc_temp_sprintf(const char *format, ...)
{
	AOC_TODO("AAA");
	return NULL;
}

void implaoc_rebuild_self(int argc, char **argv, const char *source_path, ...)
{
	const char *binary_path = aoc_shift(argv, argc);
#ifdef _WIN32
	if (!implaoc_sv_end_with(implaoc_sv_from_cstr(binary_path), ".exe")) {
		binary_path = implaoc_temp_sprintf("%s.exe", binary_path);
	}
#endif

	struct Nob_File_Paths source_paths = {0};
	implaoc_da_append(&source_paths, source_path);
	va_list args;
	va_start(args, source_path);
	for (;;) {
		const char *path = va_arg(args, const char *);
		if (path == NULL)
			break;
		implaoc_da_append(&source_paths, path);
	}
	va_end(args);

	int rebuild_is_needed = implaoc_needs_rebuild(binary_path, source_paths.items, source_paths.count);
	if (rebuild_is_needed < 0)
		exit(1);	  // error
	if (!rebuild_is_needed) { // no rebuild is needed
		NOB_FREE(source_paths.items);
		return;
	}

	struct AocBuildCmd cmd = {0};

	const char *old_binary_path = implaoc_temp_sprintf("%s.old", binary_path);

	if (!implaoc_rename(binary_path, old_binary_path))
		exit(1);
	implaoc_cmd_append(&cmd, NOB_REBUILD_URSELF(binary_path, source_path));
	if (!implaoc_cmd_run_sync_and_reset(&cmd)) {
		implaoc_rename(old_binary_path, binary_path);
		exit(1);
	}

	implaoc_cmd_append(&cmd, binary_path);
	implaoc_da_append_many(&cmd, argv, argc);
	if (!implaoc_cmd_run_sync_and_reset(&cmd))
		exit(1);
	exit(0);
}
