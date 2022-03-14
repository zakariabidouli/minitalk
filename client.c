/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:12:29 by zbidouli          #+#    #+#             */
/*   Updated: 2022/03/14 17:25:28 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char  **av)
{
	char	*str;
	int		pid;
	int		i;
	int		j;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		i = -1;
		while(str[++i])
		{
			j = 0;
			while(j < 8)
			{

				if((str[i]>>j  & 1) == 1) // 000 0110 & 1
				{
					if (kill(pid, SIGUSR1) == -1)
					{
						ft_putstr_fd("Message reiceved by server ", 1);
						return(0);
					}
				}
				else 
				{
					if(kill(pid, SIGUSR2) == -1)
						return(0);
				}
				j++;
				usleep(150);
			}
		}	
	}
		ft_putstr_fd("Message reiceved by server ", 1);
		exit(0);
}

//
	// 5 => 0000 0101;
	// 1 => 0000 0001;

	// 10
