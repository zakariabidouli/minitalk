.PHONY: all clean fclean re

NAME 	= server client

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror


SRC 	 =  server.c utils.c client.c

all: $(NAME)

server.o: server.c utils.c minitalk.h
    $(CC) $(FLAGS) -c server.c utils.c -o server
    
client.o: client.o utils.o minitalk.h
     $(CC) $(FLAGS) -c client.c utils.c -o client

server: server.o utils.o
	ar -rc server.o utils.o #run server 

client: client.o utils.o
	ar -rc server.o utils.o #pid  #string
 
minitalk : $(CC) $(FLAGS) -c client.o server.o 
        client.o server.o client.o : $(CC) $(FLAGS) -c client.o minitalk.h
    - c client.c server.o : $(CC) $(FLAGS) -c server.o minitalk.h
    - c server.c

clean:
    rm -rf *.o

fclean: clean
    rm -rf $(NAME)

re: fclean all