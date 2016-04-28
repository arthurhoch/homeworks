CC=g++

PROGRAM=Ex_Quadrangular_Linux

CXXFLAGS += -O2 -Wall

#My CPU security frags frags
#CXXFLAGS += -march=core-avx-i -pipe

all: $(PROGRAM)

clean:
	rm -rf $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

test: $(PROGRAM)
	@./$(PROGRAM)
	@rm -rf $(PROGRAM)
