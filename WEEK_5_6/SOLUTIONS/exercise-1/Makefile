
all: .mkbuild 
	@echo "==================== Targets ===================="
	@echo "==> clean: to clean the project"
	@echo "==> check: to build and run the test"
	@echo "==> run NUM=xxx: to build and run main"
	@echo "        A number shall be passed to the program"
	@echo "================================================="

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
	@echo "=================================="
	@echo "====== Run The Main Program ======"
	@echo "=================================="
	./build/main $(NUM)

check: .mkbuild build/test
	@echo "=================================="
	@echo "====== Run The Test Program ======"
	@echo "=================================="
	./build/test

.mkbuild:
	@mkdir -p build

clean:
	@rm -rf build; \
	echo "Cleaned the project"

.PHONY: all .mkbuild clean run check