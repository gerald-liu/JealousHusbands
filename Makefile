# Definition of variables
SRCS = main.cpp state.cpp
OBJS = main.o state.o
PROG = jh
CC = g++
CPPFLAGS = -std=c++11
LDFLAGS =
DBGFLAGS = -g -Wall

# Rules' Format
# TARGET: DEPENDENCIES
# [TAB] COMMAND USED TO CREATE THE TARGET

all: $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $*.cpp

# makedepend can find the .h dependencies automatically
depend:;	makedepend $(SRCS)

clean:
	rm -f core $(OBJS)
