/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:12:29 by zbidouli          #+#    #+#             */
/*   Updated: 2022/03/17 11:19:02 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_response(int signum)
{
	(void)signum;
	ft_putstr_fd("MESSAGE SENT SUCCESSFULLY", 1);
}

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
				ft_putstr_fd ("ERROR SENDING", 1);
				exit (0);
			}
		}
		else
		{
			if (kill(p, SIGUSR2) == -1)
			{
				ft_putstr_fd ("ERROR SENDING", 1);
				exit (0);
			}
		}
		j++;
		usleep(150);
	}
}

int	main(int ac, char **av)
{
	char	*str;
	int		pid;
	int		i;

	signal(SIGUSR1, server_response);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if ((kill (0, pid) != -1) || pid < 0)
		{
			ft_putstr_fd("ERROR: Wrong PID ", 1);
			exit(0);
		}
		str = av[2];
		i = -1;
		while (str[++i])
			send_signal(str, i, pid);
		return (0);
	}
	else
		ft_putstr_fd ("ERROR Please Enter : PID + \"str\" ", 1);
}
