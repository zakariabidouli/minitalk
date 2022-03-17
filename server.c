/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:12:48 by zbidouli          #+#    #+#             */
/*   Updated: 2022/03/17 11:17:23 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print(void)
{
	while (1)
	{
		pause();
		if (g_char.bit == 8)
		{
			if (g_char.ch == '\0')
				ft_putchar_fd('\n', 1);
			else
				ft_putchar_fd(g_char.ch, 1);
			g_char.bit = 0;
			g_char.ch = 0;
		}
	}
}

void	function_1(int signum)
{
	if (signum == SIGUSR1)
	{
		g_char.ch ^= 1 << g_char.bit;
		g_char.bit++;
	}
}

void	function_2(int signum)
{
	if (signum == SIGUSR2)
		g_char.bit++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	g_char.bit = 0;
	g_char.ch = 0;
	ft_putstr_fd ("Process is running... PID: ", 1);
	ft_putnbr_fd (pid, 1);
	ft_putchar_fd ('\n', 1);
	signal(SIGUSR1, function_1);
	signal(SIGUSR2, function_2);
	print ();
	return (1);
}

// 0000	001 << bit
// 0000 000 ^ 0000 001 = 0000 001 
// 0000 000 ^ 0000 010 = 0000 010 
// 						 0000 011	