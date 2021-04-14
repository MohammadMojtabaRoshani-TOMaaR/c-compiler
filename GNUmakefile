exec = a.out
sources = $(wildcard src/*.c)
objects = $(sources:.c = .o)
flags = -g -Wall -lm -ldl -fPIC -rdymnamic

$(exec): $objects
	gcc $(objects) $(flgs) -o $(exec)

%.o: %.c include/%.h
	gcc &(flags) $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm *.a

lint:
	clang-tidy src /*.c src/include/*.h