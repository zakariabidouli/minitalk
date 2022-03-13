.PHONY: all clean fclean re

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror

all: s s2 c


server.o: server.c utils.c minitalk.h
	$(CC) $(FLAGS) -c server.c utils.c

server2.o: server2.c utils.c minitalk.h
	$(CC) $(FLAGS) -c server2.c utils.c

utils.o: utils.c minitalk.h
	$(CC) $(FLAGS) -c utils.c

client.o: client.c utils.c minitalk.h
	$(CC) $(FLAGS) -c client.c utils.c

s: server.o utils.o
	$(CC) $(FLAGS)  server.o utils.o -o server

s2: server2.o utils.o
	$(CC) $(FLAGS)  server2.o utils.o -o server2

c: client.o utils.o 
	$(CC) $(FLAGS)  client.o utils.o -o client
	
clean:
	rm -rf *.o *~

fclean: clean
	rm -rf client server

re: fclean all
