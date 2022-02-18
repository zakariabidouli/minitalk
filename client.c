#include "minitalk.h"



int main(int argc, char  *argv[])
{
	char	bit;
	char	*str;
	int	i;

	bit = 0b0000001;
	i = 0;
	str = argv[2];
	while(str[i])
	{
		while(1)
		{
			if((bit & str[i]) == 1)
			{
				if(kill(atoi(argv[1]), SIGUSR1) == -1)
					return(0);
			}
			else if((bit & str[i]) == 0)
			{
				if(kill(atoi(argv[1]), SIGUSR2) == -1)
					return(0);
			}
			
		}
		
		usleep(50);
	}
	return 0;
}
