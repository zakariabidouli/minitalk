#ifndef MINITALK_H
# define MINITALK_H

#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

typedef struct s_char
{
	int	bit;
	int	ch;
}	t_char;

t_char	get_char;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		ft_isspace_isdigit(char c, int flag);

#endif

