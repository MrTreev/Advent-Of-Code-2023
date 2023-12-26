SRC_PATH     = src
BLD_PATH     = bld
BIN_PATH     = bin

DAT_PATH     = ../test_data
TST_PATH     = tst

SRC_FILES    = $(wildcard ${SRC_PATH}/day*.cpp)
BIN_FILES    = $(patsubst ${SRC_PATH}/%.cpp,${BIN_PATH}/%,${SRC_FILES})
TST_FILES    = $(patsubst ${SRC_PATH}/%.cpp,${TST_PATH}/%,${SRC_FILES})

CPP = clang++

# Base Flags
CPP_FLAGS    = -ggdb -Og -std=c++23 -march=native -mtune=native
# Options
CPP_FLAGS   += -fstrict-flex-arrays=3
#CPP_FLAGS   += -nostdlib -nostdinc
CPP_FLAGS   += -fdelete-null-pointer-checks -fstack-protector
CPP_FLAGS   += -fsized-deallocation -fstrict-enums
# Warnings
CPP_FLAGS   += -Werror -Wall -Wextra -Wpedantic -Wabi
# Includes
INCLUDES    += -I
