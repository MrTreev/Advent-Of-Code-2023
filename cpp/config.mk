SRC_PATH     = src
BLD_PATH     = bld
BIN_PATH     = bin

DAT_PATH     = ../test
TST_PATH     = tst
DEP_PATH     = ${SRC_PATH}/utility/impl

SRC_FILES    = $(wildcard ${SRC_PATH}/*.cpp)
BIN_FILES    = $(patsubst ${SRC_PATH}/%.cpp,${BIN_PATH}/%,${SRC_FILES})
TST_FILES    = $(patsubst ${SRC_PATH}/%.cpp,${TST_PATH}/%,${SRC_FILES})
ARCH         = native
V            = 

CPP = clang++

# Base Flags
CPP_FLAGS   += -Og
CPP_FLAGS   += -ggdb
CPP_FLAGS   += -std=c++14
# Options
CPP_FLAGS   += -pedantic
# Warnings
CPP_FLAGS   += -Wabi
CPP_FLAGS   += -Wall
#CPP_FLAGS   += -Werror
CPP_FLAGS   += -Wextra
CPP_FLAGS   += -Wpedantic
