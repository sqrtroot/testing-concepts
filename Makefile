.PHONY: run compiledb
main: main.cpp concepts.hpp ema.hpp vector2.hpp
	g++ -std=c++20 -O3 $< -o main

run: main
	./main

clean:
	rm -f main

compiledb:
	compiledb make
