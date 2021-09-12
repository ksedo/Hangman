.PHONY: all run runtest clean cleantest format

g = g++
flags = -Wall -c
GTESTDIR = thirdparty/googletest

all: bin/main


bin/main: build/src/main.o build/src/filework.o build/src/draw.o build/src/misstake.o
	$(g) $^ -o bin/main

build/src/main.o:
	$(g)  $(flags) src/main.cpp -o $@

build/src/filework.o:
	$(g)  $(flags) src/filework.cpp -o $@

build/src/draw.o:
	$(g)  $(flags) src/draw.cpp -o $@

build/src/misstake.o:
	$(g)  $(flags) src/misstake.cpp -o $@



test: gtestlib bin/test


gtestlib:
	$(g) -std=c++11 -isystem ${GTESTDIR}/include -I ${GTESTDIR} -pthread -c ${GTESTDIR}/src/gtest-all.cc -o build/test/gtest-all.o
	ar -rv build/test/libgtest.a build/test/gtest-all.o

bin/test: build/test/test.o build/src/filework.o build/src/draw.o build/src/misstake.o
	$(g) -std=c++11 -isystem ${GTESTDIR}/include -pthread $^ build/test/libgtest.a -o $@

build/test/test.o:
	$(g) -std=c++11 $(flags) test/test.cpp -I $(GTESTDIR)/include -o $@


run:
	bin/main

runtest:
	bin/test

clean:
	rm build/src/*.o

cleantest:
	rm build/test/*.a
	rm build/src/*.o
	rm build/test/*.o

format:
	clang-format -i ./src/*.h
	clang-format -i ./src/*.cpp
	clang-format -i ./test/*.cpp
