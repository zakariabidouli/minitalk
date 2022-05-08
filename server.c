/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:42:43 by zbidouli          #+#    #+#             */
/*   Updated: 2022/03/17 10:55:38 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, struct __siginfo *info, void *vo)
{
	(void)*vo;
	int pid;

	pid = 0;
	if (pid != info->si_pid)
	{	
		pid = info->si_pid;
		g_char.ch = 0;
		g_char.bit = 0;
	}
	if (signum == SIGUSR1)
	{
		g_char.ch ^= 1 << g_char.bit;
		g_char.bit++;
	}
	else if (signum == SIGUSR2)
			g_char.bit++;
	if (g_char.bit == 8)
	{
		if (g_char.ch == '\0')
			kill(info->si_pid, SIGUSR1);
		else
			ft_putchar_fd(g_char.ch, 1);
		g_char.bit = 0;
		g_char.ch = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_char.bit = 0;
	g_char.ch = 0;
	ft_putstr_fd("Process is running... PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (0);
}
