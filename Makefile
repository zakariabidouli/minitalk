.PHONY: all clean fclean re

NAME 	= minitalk.a

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror


SRC 	 =  server.c utils.c 

OBJS = $(SRC:%.c=%.o)
	
all: $(NAME)

$(OBJS): $(SRC)
	 $(CC) $(FLAGS) -c $(SRC) 

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all