#include "minitalk.h"
#define MAX_CHARS 8
typedef struct s_string
{
	char            buffer[MAX_CHARS];
    unsigned char   c;
    int             index;
    int             client_pid;
}	t_string;

void	func1(int signum)
{
	printf("\nHELLO");


}

void	func2(int signum)
{
	printf("\nHELLOWORD");


}

int main(int argc, char *argv[])
{
	int	i;
	int	j;
	unsigned char	*str;

	printf("Server PID:%d\n", getpid());
	str = malloc((sizeof(char) * 8) + 1);
	if(!str)
		return(0);
	i = 0;
	while(1)
	{
		while(str[i])
		{
			while(i++ && i <= 8)
			{	
				if(signal(SIGUSR1, func1))
				{	
					str[i] = 1;
				}
				else if(signal(SIGUSR2, func2))
				{
					str[i] = 0;
				}
				else
				{
					printf("ERROR");
					return(0);
				}
				i <<= 1;
			}
			sleep(5);
		}
	}
	return 0;
}
