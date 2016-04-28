TARGET = build/grafo
INCLUDE_DIR = -I include

CC=gcc
CCFLAGS += -march=core-avx-i -O2 -pipe -Wall $(INCLUDE_DIR)
LFLAGS += -lpthread -ldl -Wl,--export-dynamic
OBJS = $(patsubst src/%.c,obj/%.o,$(wildcard src/*.c))

.PHONY : clean all

all: $(TARGET)

clean:
	rm -f obj/*.o $(TARGET) 

obj/%.o: src/%.c include/%.h
	$(CC) $(CCFLAGS) -c $< -o $@


$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(TARGET) $(LFLAGS)
	
run: $(TARGET)
	./build/grafo
