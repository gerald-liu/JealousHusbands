# Definition of variables
SRCS = *.cpp
OBJS = *.o
PROG = jh
CC = g++
CPPFLAGS = -std=c++11
DBGFLAGS = -g -Wall

# Rules' Format
# TARGET: DEPENDENCIES
# [TAB] COMMAND USED TO CREATE THE TARGET

all: $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

*.o:
	$(CC) $(CPPFLAGS) -c *.cpp

# makedepend can find the .h dependencies automatically
depend:
	makedepend $(SRCS)

clean:
	rm -f core $(OBJS) $(PROG)