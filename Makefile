.PHONY: all clean fclean re

NAME1 = server

NAME2 = client

SOURCE = utils.c 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCE:.c=.o)

̦DEFS = minitalk.h

all: $(NAME1) $(NAME2)

$(NAME1) : server.c  $(DEFS)
	$(CC) $(CFLAGS) server.c $(SOURCE) -o server
$(NAME2) : client.c $(DEFS)
	$(CC) $(CFLAGS) client.c $(SOURCE) -o client

	
clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME1) $(NAME2)

re: fclean all 