CC=g++

PROGRAM=Jogo_Senha

CXXFLAGS += -O2 -Wall -lcurses

#My CPU security frags
#CXXFLAGS += -march=core-avx-i -pipe

all: $(PROGRAM)

clean:
	rm -rf $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

test: $(PROGRAM)
	@./$(PROGRAM)
	@rm -rf $(PROGRAM)
