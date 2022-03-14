.PHONY: all clean fclean re

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror

all: c2 s2 c

# server.o: server.c utils.c minitalk.h
# 	$(CC) $(FLAGS) -c server.c utils.c

server2.o: server2.c utils.c minitalk.h
	$(CC) $(FLAGS) -c server2.c utils.c

utils.o: utils.c minitalk.h
	$(CC) $(FLAGS) -c utils.c

client.o: client.c utils.c minitalk.h
	$(CC) $(FLAGS) -c client.c utils.c

client2.o: client2.c utils.c minitalk.h
	$(CC) $(FLAGS) -c client2.c utils.c

# s: server.o utils.o
# 	$(CC) $(FLAGS)  server.o utils.o -o server

s2: server2.o utils.o
	$(CC) $(FLAGS)  server2.o utils.o -o server2

c: client.o utils.o 
	$(CC) $(FLAGS)  client.o utils.o -o client

c2: client2.o utils.o 
	$(CC) $(FLAGS)  client2.o utils.o -o client2
	
clean:
	rm -rf *.o *~

fclean: clean
	rm -rf client client2 server2

re: fclean all
