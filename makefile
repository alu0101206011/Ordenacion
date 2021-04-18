CC = g++
CFLAGS = -g -Wall --std=c++17

OBJ_DIR := ./obj
SRC_DIR := ./src
BIN_DIR := ./bin

EXEC := a.out
EXEC := $(EXEC:%=$(BIN_DIR)/%)

SRCS := $(shell ls $(SRC_DIR))
OBJS := $(SRCS:%=$(OBJ_DIR)/%)
OBJS := $(OBJS:.cpp=.o)

SRCS := $(SRCS:%=$(SRC_DIR)/%)


all: $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $^

./obj/%.o: ./src/%.cpp 
	$(CC) -c -o $@ $<

run: clean all
	$(EXEC)

debug: $(SRCS)
	$(CC) $(CFLAGS) -o $(EXEC) $^

.PHONY: clean

clean:
	rm -f ./bin/*.out
	rm -f ./obj/*.o