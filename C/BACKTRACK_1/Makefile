TARGET = main
INCLUDE_DIR = -I include

CC=gcc
CCFLAGS += -march=core-avx-i -O2 -pipe -Wall $(INCLUDE_DIR)
OBJS = $(patsubst src/%.c,obj/%.o,$(wildcard src/*.c))

.PHONY : clean all

all: $(TARGET)

clean:
	rm main
	rm obj/*

obj/%.o: src/%.c include/%.h
	$(CC) $(CCFLAGS) -c $< -o $@


$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(TARGET)

run:
	./$(TARGET)
