#include "minitalk.h"



int main(int argc, char  *argv[])
{
	char	*str;
	int	i;

	i = -1;
	str = argv[2];
	while(1)
	{
		while(str[i])
		{
			while(++i && i <=  8)
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
			}
			sleep(5);
		}
	}	
	return 0;
}
