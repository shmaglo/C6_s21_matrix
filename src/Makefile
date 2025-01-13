CC=gcc -std=c11 -D_GNU_SOURCE
CFLAGS=-c -Wall -Wextra -Werror -g
SOURCES=$(wildcard s21*.c)
OBJECTS=$(SOURCES:.c=.o)
LIBRARY=s21_matrix.a
TEST_SOURCES=$(wildcard tests/*.c)
TEST_OBJECTS=$(TEST_SOURCES:.c=.o)
TEST_FLAGS=-lcheck -lm -lpthread
CHECK:=$(shell pkg-config --cflags --libs check)


GCOV_FLAGS=--coverage -Wall -Wextra -Werror

ifeq ($(shell uname -s),Linux)
        TEST_FLAGS += -lrt
endif

all: clean $(LIBRARY)

main: $(OBJECTS)
	$(CC) $(OBJECTS) main.c -o $@
	./main

.c.o:
	$(CC) $(CFLAGS) $< -o $@ $(CHECK)

$(LIBRARY): $(OBJECTS)
	ar -rc $(LIBRARY) $^
	ranlib $(LIBRARY)

test: $(TEST_OBJECTS) $(LIBRARY) 
	$(CC) $^ -o test $(TEST_FLAGS) $(CHECK)
	./test

clean:
	rm -rf *.o *.exe main *.a tests/*.o test *.gcov *.gcda *.gcno *.info report

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i */*.c
	clang-format -i */*.h
	clang-format -i *.c
	clang-format -i *.h
	clang-format -n */*.c
	clang-format -n */*.h
	clang-format -n *.c
	clang-format -n *.h
	$(RM) .clang-format


rebuild: clean all

gcov_report: $(TEST_OBJECTS)
	$(CC) $(GCOV_FLAGS) $(TEST_OBJECTS) $(SOURCES) $(TEST_FLAGS) $(CHECK) -o test
	./test
	gcov *.gcno
	lcov -t "Popa" -o Popa.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report Popa.info --rc lcov_branch_coverage=1
	open report/index.html
