#include "minitalk.h"



int main(int argc, char  *argv[])
{
	char	*str;
	int	i;

	i = -1;
	str = malloc(sizeof(char) * 9);
	if(!str)
		return(0);
	str = argv[2];
	str [9] = '\0';
	// while(1)
	// {
		while(1)
		{
			if(str[i])
			{
				printf("123");
				while(++i && i <=  8)
				{
					if((str[i] & 1) == 1)
					{
						if(kill(atoi(argv[1]), SIGUSR1) == -1)
						{
							printf("SEND1");
							return(0);
						}
					}
					else if((str[i] & 1) == 0)
					{
						if(kill(atoi(argv[1]), SIGUSR2) == -1)
						{
							printf("SEND0");
							return(0);
						}
					}
					str[i] >>= i;
					usleep(200);
				}
			}
			break;
		}
	// }	
	return 0;
}
