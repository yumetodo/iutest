# Copyright (C) 2018, Takazumi Shirayanagi
# This software is released under the new BSD License,
# see LICENSE


# iutest root directory
IUTEST_DIR = ../..
IUTEST_INCLUDE = -I$(IUTEST_DIR)/include

IUTEST_HEADERS = $(IUTEST_DIR)/include/*.hpp \
                 $(IUTEST_DIR)/include/impl/*.ipp \
                 $(IUTEST_DIR)/include/internal/*.hpp \
                 $(IUTEST_DIR)/include/listener/*.hpp \
                 $(IUTEST_DIR)/include/util/*.hpp \
                 $(IUTEST_DIR)/include/gtest/*.hpp \
                 $(IUTEST_DIR)/include/gtest/switch/*.hpp

#
# cppcheck configuration
#

CPPCHECK_DEFINES= \
	IUTEST_HAS_CLOCK=1 \

CPPCHECK_UNDEFINES= \
	_WIN32 \
	_MSC_VER \
	__clang__ \
	__CYGWIN__ \
	__APPLE__ \

CPPCHECK_SUPPRESS= \
	syntaxError \
	missingIncludeSystem \
	ConfigurationNotChecked \
	knownConditionTrueFalse:*/iutest_internal_defs.hpp \
	unmatchedSuppression

CPPCHECK_DEFINES_OPTIONS=$(patsubst %,-D%,$(CPPCHECK_DEFINES))
CPPCHECK_UNDEFINES_OPTIONS=$(patsubst %,-U%,$(CPPCHECK_UNDEFINES))
CPPCHECK_SUPPRESS_OPTIONS=$(patsubst %,--suppress=%,$(CPPCHECK_SUPPRESS))

CPPCHECK_ENABLE_OPTION= --enable=all

DEFAULT_OPTIONS=--inline-suppr -f -j4 --platform=unix64

OPTIONS+= $(DEFAULT_OPTIONS)
OPTIONS+= $(CPPCHECK_ENABLE_OPTION)
OPTIONS+= $(CPPCHECK_DEFINES_OPTIONS)
OPTIONS+= $(CPPCHECK_UNDEFINES_OPTIONS)
OPTIONS+= $(CPPCHECK_SUPPRESS_OPTIONS)

SRC_CPP=$(wildcard ../../src/*.cpp)
SAMPLES=$(wildcard ../../samples/*.cpp)
TESTS=$(wildcard ../../test/*.cpp)

SRCS=$(SRC_CPP) \
	$(TESTS) \
	#$(SAMPLES) \

TARGETS=cppcheck_result.xml

#
#
# build targets.
#

.PHONY: clean default all

default: version $(TARGETS)

all: clean default

clean:
	$(RM) $(TARGETS) check-config.xml

version:
	cppcheck --version

check-config:
	cppcheck $(IUTEST_INCLUDE) $(OPTIONS) $(SRCS) --check-config --xml 2> $@.xml

$(TARGETS): $(SRC_CPP) Makefile
	cppcheck $(IUTEST_INCLUDE) $(OPTIONS) $(SRCS) --xml 2> $@
