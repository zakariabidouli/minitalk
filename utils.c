#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}


int	ft_atoi(const char *str)
{
	int	i;
	int	k;
	int	n;

	i = 0;
	k = 1;
	n = 0;
	while (ft_isspace_isdigit(str[i], 0))
		i++;
	if (str[i] == '-')
		k = -k;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isspace_isdigit(str[i], 1))
	{
		n = n * 10 + (str[i++] - '0');
		if (n < 0)
		{
			if (k < 0)
				return (0);
			return (-1);
		}
	}
	return ((int)n * k);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			ft_putchar_fd(s[i++], fd);
	}
}

int	ft_isspace_isdigit(char c, int flag)
{
	if (flag == 0)
		return ((c >= 9 && c <= 13) || c == ' ');
	return (c >= 48 && c <= 57);
}

