# Write a Makefile without using variables, functions and pattern rules to build and run the main and the test programs.

#     There shall be a rule to clean the project.
#     The generated files shall be stored in a directory named build.
#     There shall be a target named run to build and run the main program
#         A integer number in the range of 1 and 255 shall be passed to the program as an argument.
#             E.g. make run NUM=123
#     There shall be a target named check to build and run the test.

# Download and extract the zip file and write the solution in Makefile.

all: .mkbuild #what is .mkbuild? a dependency target. 
	@echo "=> clean:"
	@echo "=> run NUM=XXX:"
	@echo "=> check"

#if build/main doesnt exist, or these files are updated execute the commands below.
build/main: build/main.o build/fizzbuzz.o
	g++ build/main.o build/fizzbuzz.o -o build/main

build/test: build/test.o build/fizzbuzz.o build/unity.o
	g++ build/test.o build/fizzbuzz.o build/unity.o -o build/test

build/main.o: src/main.cpp lib/fizzbuzz/fizzbuzz.h
	g++ -c src/main.cpp -I./lib/fizzbuzz -o build/main.o

build/test.o: test/test.cpp lib/fizzbuzz/fizzbuzz.h lib/unity/unity.h lib/unity/unity_internals.h
	g++ -c test/test.cpp -I./lib/fizzbuzz -I./lib/unity -o build/test.o

build/fizzbuzz.o: lib/fizzbuzz/fizzbuzz.cpp lib/fizzbuzz/fizzbuzz.h
	g++ -c lib/fizzbuzz/fizzbuzz.cpp -I./lib/fizzbuzz -o build/fizzbuzz.o

build/unity.o: lib/unity/unity.cpp lib/unity/unity.h lib/unity/unity_internals.h
	g++ -c lib/unity/unity.cpp -I./lib/unity -o build/unity.o


run: .mkbuild build/main
	@echo "run main"
	./build/main $(NUM)

check: .mkbuild build/test
	@echo "==> TEST"
	./build/test

.mkbuild:
	@mkdir -p build 

clean: 
	@rm -rf build \
	echo "Cleaned the project"

.PHONY: all .mkbuild clean run check