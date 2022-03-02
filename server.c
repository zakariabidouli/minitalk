#include "minitalk.h"

void	print(void)
{
	while (1)
	{
		pause();
		if (g_ch.bit == 8)
		{
			if (g_ch.ch == '\0')
				ft_putchar_fd('\n', 1);
			else
				ft_putchar_fd(g_ch.ch, 1);
			g_ch.bit = 0;
			g_ch.ch = 0;
		}
	}
}

void	function_1(int signum)
{
	if (signum == SIGUSR1)
	{
		g_ch.ch &= 1 << g_ch.bit;
		g_ch.bit++;
	}
}

void	function_2(int signum)
{
	if (signum == SIGUSR2)
	{
		g_ch.ch &= 1 << g_ch.bit;
		g_ch.bit++;
	}
}

int	main(void)
{
	int	pid;
	int	i;

	pid = getpid();
	g_ch.bit = 0;
	g_ch.ch = 0;
	ft_putstr_fd("Process is running... PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);

	signal(SIGUSR1, function_1);
	signal(SIGUSR2, function_2);

	print();
}