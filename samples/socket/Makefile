all: client server

.PHONY: client server

client:
	clang -Wall -Wextra -g -O0 -o client -L../.. -I../.. -lft main_client.c

server:
	clang -Wall -Wextra -g -O0 -o server -L../.. -I../.. -lft main_server.c

fclean:
	rm -rf client server client.dSYM server.dSYM
