exec = c_compiler.out
sources = $(wildcard src/*.c)
objects = $(sources:.c = .o)
flags = -g -Wall -lm -ldl -fPIC -rdymnamic

$(exec): $(objects)
	gcc $(objects) $(flgs) -o $(exec)

%.o: %.c include/%.h
	gcc &(flags) $< -o $@

clear:
	-rm *.out

lint:
	clang-tidy src /*.c src/include/*.h