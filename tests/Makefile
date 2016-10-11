
LFLAGS = -L.. -I.. -lft
FLAGS  = -Wall -Wextra -O0 -g3

.PHONY: all fclean clean io count_digit

all: io count_digit

re: fclean all

io:
	cc $(LFLAGS) $(FLAGS) io.c -o io

count_digit:
	cc $(LFLAGS) $(FLAGS) count_digit.c -o count_digit

clean:
	rm -rf $(wildcard *.o) $(wildcard **.dSYM)

fclean: clean
	rm io count_digit
