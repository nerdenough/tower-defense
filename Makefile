CC = g++
CFLAGS = -Wall
LDFLAGS = -framework SDL2 -framework SDL2_image
SRC_FILES = $(wildcard src/*.cc)
OBJ_FILES = $(addprefix obj/,$(notdir $(SRC_FILES:.cc=.o)))
EXECUTABLE = bin/main

all: $(SRC_FILES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o $@

obj/%.o: src/%.cc
	$(CC) $(CFLAGS) -c -o $@ $<
