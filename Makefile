CXX ?= g++
CXXFLAGS=-g -Wall -Wextra -Werror -pedantic -std=c++17
LDLIBS=-lSDL -lGL -lGLU
SRC=turtle.cc rules.cc main.cc

all:
	$(CXX) ${SRC} ${LDLIBS} -o lsystem

clean:
	$(RM) lsystem
