CXX ?= g++
CXXFLAGS=-g -Wall -Wextra -Werror -pedantic -std=c++17
LDLIBS=-lSDL -lGL -lGLU
SRC=src/*.cc

all:
	$(CXX) ${SRC} ${LDLIBS} -o lsystem

clean:
	$(RM) lsystem
