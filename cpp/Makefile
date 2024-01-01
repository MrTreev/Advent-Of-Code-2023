SHELL := bash
.ONESHELL:
.SHELLFLAGS := -eu -o pipefail -c
.DELETE_ON_ERROR:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules

.PHONY: all test clean debug

include config.mk

all: ${BIN_FILES}
test: ${TST_FILES}

${BIN_PATH}/%: ${SRC_PATH}/%.cpp
	${CPP} ${V} ${CPP_FLAGS} $< -o $@

${TST_PATH}/%: ${BIN_PATH}/%
	$< <$(patsubst ${BIN_PATH}/%,${DAT_PATH}/%.txt,$<) >$@

debug: 
	@echo "SRC_FILES: ${SRC_FILES}"
	@echo "BIN_FILES: ${BIN_FILES}"
	@echo "TST_FILES: ${TST_FILES}"

clean:
	rm -f ${BIN_FILES} ${TST_FILES}
