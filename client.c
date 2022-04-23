/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:12:29 by zbidouli          #+#    #+#             */
/*   Updated: 2022/04/23 23:16:40 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(char *s, int i, int p)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if ((s[i] >> j & 1) == 1)
		{
			if (kill(p, SIGUSR1) == -1)
			{
				ft_putstr_fd ("ERROR Please Enter : PID + \"str\" ", 1);
				exit (1);
			}
		}
		else
		{
			if (kill(p, SIGUSR2) == -1)
			{
				ft_putstr_fd ("ERROR Please Enter : PID + \"str\" ", 1);
				exit (1);
			}
		}
		j++;
		usleep(750);
	}
}

int	main(int ac, char **av)
{
	char	*str;
	int		pid;
	int		i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if ((kill (0, pid) != -1) || pid < 0)
		{
			ft_putstr_fd("ERROR: Wrong PID ", 1);
			exit(1);
		}
		str = av[2];
		i = -1;
		while (str[++i])
		{
			send_signal(str, i, pid);
		}	
		ft_putstr_fd ("Message reiceved by server ", 1);
		exit(1);
	}
	else
	{
		ft_putstr_fd ("ERROR Please Enter : PID + \"str\" ", 1);
	}
}

//
	// 5 => 0000 0101;
	// 1 => 0000 0001;

	// 10
