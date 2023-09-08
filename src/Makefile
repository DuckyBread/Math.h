CC = gcc
CFLAGS = -Wall -Werror -Wextra 

GKOVFLAGS = -lgcov --coverage
LINFLAG = -lm -lpthread -lsubunit -lrt
CHECKFLAGS = -lcheck
OS = $(shell uname)
ifeq ($(OS), Linux)
CHECKFLAGS += -lm -lpthread -lsubunit -lrt
endif
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TESTS_SOURSES = $(wildcard ./tests/*.check)
CFLAGS_GCOV =-fprofile-arcs --coverage

all: my_math.a

rebuild: clean all


my_math.a: $(OBJECTS) my_math.h
	ar rc $@ $(OBJECTS)
	ranlib -D $@

lib_cov.a: $(SOURCES) my_math.h
	$(CC) $(CFLAGS) $(CFLAGS_GCOV) -c  $(SOURCES)
	ar rc lib_cov.a $(OBJECTS)
	ranlib lib_cov.a

test: clean $(TESTS_SOURSES) my_math.a
	@checkmk clean_mode=1 ./my_math.h $(TESTS_SOURSES) > test.c
	$(CC) test.c $(CHECKFLAGS) my_math.a -o test
	$(CC) test.c $(CHECKFLAGS) -lm my_math.a -o test
	./test

gcov_report: clean $(TESTS_SOURSES) lib_cov.a
	checkmk clean_mode=1 $(TESTS_SOURSES) > test.c
	$(CC)  test.c -c
	$(CC)  test.o -g $(CHECKFLAGS) lib_cov.a -o test $(GKOVFLAGS)
	./test > /dev/null
	lcov -t "t" -o test.info -c -d . 
	genhtml -o report test.info 
	open ./report/index.html
	rm -f test.c

style:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c
	clang-format -n *.c
	rm .clang-format

leaks: test
	leaks -atExit -- ./test

clean:
	rm -rf *.a *.o *.test *test.c .test.c *.gcda *.gcno *.info test.c report a.out test
