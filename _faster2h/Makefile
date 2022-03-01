# -*- file: Makefile -*-
# -*- type: Makefile -*-
# -*- coding: utf-8 -*-
# -*- date: 2019 -*-
# -*- author: Greg Henning -*-
# -*- copyright: GH/IPHC 2019 -*-
# -*- purpose: Makefile for faster2h-*-
SHELL := /bin/bash


INCDIR = -I./src -I./src/fasterlib
SOURCES = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp,lib/%.o,$(wildcard src/*.cpp)) $(patsubst src/fasterlib/%.c, lib/%.o,$(wildcard src/fasterlib/*.c))
INCLUDES = $(wildcard src/*.h) $(wildcard src/fasterlib/fasterac/*.h)

CFLAGS = -I$(INCDIR) -O3 -Wall -g -std=c++11
LDFLAGS = -g


default: $(patsubst src/%.cpp, %.dep, $(wildcard src/*.cpp))
	@echo "Makefile for faster2h tools"

clean:
	-@rm -v *.dep
	-@rm -v lib/*.o
	-@rm -v bin/*
	-@rm -v output/*.txt
	-@rm -v output/*.png
	@touch bin/empty.null

-include Makefile.binaries

-include Makefile.test

-include Makefile.dist

%.dep : src/%.cpp 
	@echo Computing dependencies for $<
	@$(CXX) -MM -MT $(patsubst src/%.cpp,lib/%.o,$<)  $(CFLAGS) $< -o $@
	@echo -e '\t $(CXX) $< -c $(CFLAGS) $(INC) -o $(patsubst src/%.cpp,lib/%.o,$<)' >> $@
	@cat $@

-include $(patsubst lib/%.o,%.dep,$(OBJS))

lib/%.o: src/fasterlib/%.c
	cd src/fasterlib; make ../../$@;	cd ../..


.PHONY : clean default
