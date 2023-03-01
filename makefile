#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

.PHONY: clean
.PHONY: test

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=./unity

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
#CFLAGS += -Wno-misleading-indentation

TARGET_BASE1=xsort_file
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=\
  src/xsort.c \
  src/file_utils.c\
  src/main.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=-O2

TARGET_XSORT_TEST_BASE=xsort_all_tests
TARGET_XSORT_TEST = $(TARGET_XSORT_TEST_BASE)$(TARGET_EXTENSION)
SRC_FILES_TEST=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  src/xsort.c \
  src/file_utils.c\
  test/test_xsort.c \
  test/test_runners/test_xsort_runner.c \
  test/test_runners/all_tests.c
INC_DIRS_TEST=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS_TEST=-DUNITY_FIXTURE_NO_EXTRAS -O2

all: clean default

default:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)

clean:
	$(CLEANUP) $(TARGET1)
	$(CLEANUP) $(TARGET_XSORT_TEST)

test:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS_TEST) $(SYMBOLS_TEST) $(SRC_FILES_TEST) -o $(TARGET_XSORT_TEST_BASE)
	- ./$(TARGET_XSORT_TEST) -v
	
ci: CFLAGS += -Werror
ci: default
