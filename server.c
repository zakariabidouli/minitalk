#include "minitalk.h"


void	func1(int signum)
{
	int i = 0;
	while(i++)
		printf("\n%d",i);

}

void	func2(int signum)
{
		printf("HELLO");
}
int main(int argc, char *argv[])
{
	int	i;
	int	j;
	char	*bit;
	static char	*str;

	printf("Server PID:%d\n", getpid());

	i = -1;
	while(str[++i])
	{	
		bit = malloc((sizeof(char) * 8) + 1);
		if(!bit)
			return(0);
		bit[8] = '\0';
		j = 0;
		while(j < 8)
		{	
			bit[j] <<= j;
			if(signal(SIGUSR1, func1))
				bit[j] = 1;
			else if(signal(SIGUSR2, func2))
				bit[j] = 0;
			usleep(200);
		}
		str[i] = atoi(bit);
		free(bit);
	}
	return 1;
}
