#
#
#
# Copyright (C) 2018, Takazumi Shirayanagi
# This software is released under the new BSD License,
# see LICENSE

# iutest root directory
IUTEST_DIR = ../..
# iutest include directory
IUTEST_INCLUDE = -I$(IUTEST_DIR)/include

# All iutest headers.  Usually you shouldn't change this
# definition.
IUTEST_HEADERS = $(IUTEST_DIR)/include/*.hpp \
                 $(IUTEST_DIR)/include/impl/*.ipp \
                 $(IUTEST_DIR)/include/internal/*.hpp \
                 $(IUTEST_DIR)/include/listener/*.hpp \
                 $(IUTEST_DIR)/include/util/*.hpp \
                 $(IUTEST_DIR)/include/gtest/*.hpp \
                 $(IUTEST_DIR)/include/gtest/switch/*.hpp

# fused-src directory
FUSED_DIR = $(IUTEST_DIR)/fused-src


default: $(FUSED_DIR) $(IUTEST_HEADERS) fused_iutest_files.py Makefile
	python fused_iutest_files.py $(FUSED_DIR)

min: default
	mv $(FUSED_DIR)/iutest.min.hpp $(FUSED_DIR)/iutest.hpp

clean:
	$(RM) -rf $(FUSED_DIR)

$(FUSED_DIR):
	@if [ ! -d $@ ]; then \
		mkdir -p $@; \
	fi

