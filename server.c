#include "minitalk.h"

void	print(void)
{
	while (1)
	{
		pause();
		if (get_char.bit == 8)
		{
			if (get_char.ch == '\0')
				ft_putchar_fd('\n', 1);
			else
				ft_putchar_fd(get_char.ch, 1);
			get_char.bit = 0;
			get_char.ch = 0;
		}
	}
}

void	function_1(int signum)
{
	if (signum == SIGUSR1)
	{
		get_char.ch ^= (1 << get_char.bit);
		get_char.bit++;
	}
}

void	function_2(int signum)
{
	if (signum == SIGUSR2)
	{
	
		get_char.bit++;
	}
}

int	main(void)
{
	int	pid;
	int	i;

	pid = getpid();
	get_char.bit = 0;
	get_char.ch = 0;
	ft_putstr_fd("Process is running... PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);

	signal(SIGUSR1, function_1);
	signal(SIGUSR2, function_2);

	print();
}