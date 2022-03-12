#include "minitalk.h"

void	print(void)
{
	while (1)
	{
		pause();
		if (get_char.bit == 8)
		{
			// if (get_char.ch == '\0')
			// 	ft_putchar_fd('\n', 1);
			// else
				ft_putchar_fd(get_char.ch, 1);
			get_char.bit = 0;
			get_char.ch = 0;
		}
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		get_char.ch ^= 1<<get_char.bit;
		get_char.bit++;
	}
	else 
	{
		if (signum == SIGUSR2)
			get_char.bit++;
	}
}


int	main(void)
{
	int	pid;
	extern void handler();
    struct sigaction act1;
    struct sigaction act2;
    sigset_t set;

	sigemptyset( &set );
    sigaddset( &set, SIGUSR1 );
    sigaddset( &set, SIGUSR2 );

	pid = getpid();
	get_char.bit = 0;
	get_char.ch = 0;
	ft_putstr_fd("Process is running... PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	act1.sa_flags = 0;
    act1.sa_mask = set;
    act1.sa_handler = &handler;
	sigaction(SIGUSR1, &act1, NULL);
	act2.sa_flags = 0;
    act2.sa_mask = set;
    act2.sa_handler = &handler;
	sigaction(SIGUSR2, &act2, NULL);
	
	print();
	
	return (1);

}