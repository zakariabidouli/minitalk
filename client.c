#include "minitalk.h"



int main(int argc, char  *argv[])
{
	char	*str;
	int		pid;
	int		i;
	int		j;

	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = -1;
	while(str[++i])
	{
		j = 0;
		while(j < 8)
		{
			str[i] >>= j; //0
			if((str[i] & 1) == 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					return(0);
			}
			else
			{
				if(kill(pid, SIGUSR2) == -1)
					return(0);
			}
			j++;
			usleep(200);
		}
	}	
	return 1;
}

//
	// 5 => 0 
	// 1 => 0000 0001

	// 10
