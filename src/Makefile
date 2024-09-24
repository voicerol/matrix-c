.PHONY: all clean test gcov_report style valgrind
CC = gcc -Wall -Wextra -Werror -std=c11
GCOVFLAGS = -L. --coverage
FLAGS = -lcheck -pthread -lrt -lm -lsubunit

OBJDIR = objects
ACTIONSDIR = functions
TESTDIR = tests

# Объектные файлы
OBJS = $(OBJDIR)/s21_create_matrix.o $(OBJDIR)/s21_remove_matrix.o \
       $(OBJDIR)/s21_eq_matrix.o $(OBJDIR)/s21_sum_matrix.o $(OBJDIR)/s21_sub_matrix.o \
       $(OBJDIR)/s21_mult_number.o $(OBJDIR)/s21_mult_matrix.o $(OBJDIR)/s21_transpose.o \
       $(OBJDIR)/s21_calc_complements.o $(OBJDIR)/s21_determinant.o \
       $(OBJDIR)/s21_inverse_matrix.o $(OBJDIR)/s21_helper_functions.o

# Исходные файлы
SRCS = $(ACTIONSDIR)/s21_create_matrix.c $(ACTIONSDIR)/s21_remove_matrix.c \
       $(ACTIONSDIR)/s21_eq_matrix.c $(ACTIONSDIR)/s21_sum_matrix.c $(ACTIONSDIR)/s21_sub_matrix.c \
       $(ACTIONSDIR)/s21_mult_number.c $(ACTIONSDIR)/s21_mult_matrix.c $(ACTIONSDIR)/s21_transpose.c \
       $(ACTIONSDIR)/s21_calc_complements.c $(ACTIONSDIR)/s21_determinant.c \
       $(ACTIONSDIR)/s21_inverse_matrix.c $(ACTIONSDIR)/s21_helper_functions.c

# Цели
all: $(OBJDIR) s21_matrix.a

s21_matrix.a: $(OBJS)
	@ar rcs $@ $(OBJS)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(ACTIONSDIR)/%.c s21_matrix.h $(ACTIONSDIR)/s21_helper_functions.h
	$(CC) -c $< -o $@

$(OBJDIR)/test.o: $(TESTDIR)/test.c s21_matrix.h
	$(CC) -c $< -o $@

clean:
	rm -rf *.a *.gch *.gcno *.gcda *.info *.out test test_html tests/*.log objects/*.o

test: s21_matrix.a $(OBJDIR)/test.o
	$(CC) $(OBJDIR)/test.o s21_matrix.a $(FLAGS) -o test
	./test

gcov_report: s21_matrix.a test
	$(CC) -w $(SRCS) $(TESTDIR)/test.c s21_matrix.a $(FLAGS) $(GCOVFLAGS) -o test
	./test
	lcov -t test -o test.info -c -d .
	genhtml -o test_html test.info
	open ./test_html/index.html
	@echo "Web page was generated..."

style:
	@echo "Check Code Style..."
	@clang-format -i **/*.c **/*.h *.h
	@clang-format -n **/*.c **/*.h *.h

valgrind: s21_matrix.a $(OBJDIR)/test.o
	@if ! command -v valgrind > /dev/null; then \
		echo "Valgrind is not installed. Please install Valgrind to use this target."; \
		exit 1; \
	fi
	$(MAKE) test
	valgrind --leak-check=full --track-origins=yes ./test

