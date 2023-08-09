CC=gcc
WWW = -Wall -Wextra -Werror
CFLAGS= -c $(WWW) -std=c11  
FLAGS= -g $(WWW)
ADD_MATH_LIB = $(WWW) -lm

FILES = *.c

TEST_FLAGS=-lcheck --coverage
TEST_FUNC= tests/s21_smartCalc_test.c

OS := $(shell uname -s)
ifeq ($(OS), Linux)
	TEST_FLAGS += -lsubunit -lrt -lm 
	OPEN = echo 'report: C5_s21_smartCalc-2/src/report/index.html'
else
	OPEN=open ./report/index.html
endif

all: clean s21_smartCalc.a

clean:
	rm -rf *.o *.a *.out *.gcda *.info *.gcno tests/*.out greport s21_smartCalc.h.gch .clang-format report gcov */*.o test tests/s21_smartCalc_test.c

s21_smartCalc.a:
	$(CC) $(CFLAGS) -c *.c 
	ar rcs s21_smartCalc.a $(FILES:.c=.o)
	ranlib s21_smartCalc.a
	rm *.o

gcov_report: clean check
	mkdir -p gcov
	gcc $(FILES) $(TEST_FUNC) -o gcov/greport $(TEST_FLAGS)
	./gcov/greport;
	lcov -t "s21_smartCalc" -o s21_smartCalc.info -c -d .
	genhtml -o ./report s21_smartCalc.info
	$(OPEN)

clang:
	clang-format -style="{BasedOnStyle: Google}" -n */*.c *.h

check:
	checkmk clean_mode=1 tests/headers.check tests/*/*.check > tests/s21_smartCalc_test.c

test: s21_smartCalc.a check
	$(CC) $(WWW) -std=c11  tests/s21_smartCalc_test.c s21_smartCalc.a -o test $(TEST_FLAGS)

valgrind: clean check s21_smartCalc.a test
	CK_FORK=no valgrind --tool=memcheck --leak-check=yes ./test