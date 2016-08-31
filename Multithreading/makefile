PHONY: clean all

CC=gcc
CCFLAGS= -w
CPP=g++
CPPFLAGS= -g -Wall -std=c++11 -pthread 

TARGETS = squareroot

all: $(TARGETS)

#%.o : %.c
#        $(CC) -c $(CCFLAGS)     $<
        
#%.o : %.cpp
#        $(CPP) -c $(CPPFLAGS)     $<

squareroot: squareroot.cpp
		$(CPP) $(CPPFLAGS) -o $@ $^	
        
clean:
	rm -rf  *.o  $(TARGETS) 
