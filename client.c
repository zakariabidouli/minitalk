#include "minitalk.h"



int main(int argc, char  *argv[])
{
	char	*str;
	int	i;
	int	j;

	str = argv[2];
	i = 0;

	while(str[i++])
	{
				j = 0;
				while(j < 8)
				{
					if((str[i] & 1) == 1)
					{
						if(kill(atoi(argv[1]), SIGUSR1) == -1)
							return(0);
					}
					else if((str[i] & 1) == 0)
					{
						if(kill(atoi(argv[1]), SIGUSR2) == -1)
							return(0);
					}
					str[i] >>= i;
					usleep(200);
				}
	}	
	return 1;
}

	// 5 => 00000 010
	// 1 => 0000 0001

	// 10
