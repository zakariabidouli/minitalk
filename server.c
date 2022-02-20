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
	char	str[MAX_CHARS];

	printf("Server PID:%d\n", getpid());

	i = 0;
	
	while(i && i < 255)
	{	
		j = 0;
		while(j < 8)
		{	
			bit = malloc((sizeof(char) * 8) + 1);
			if(!bit)
				return(0);
			bit[8] = '\0';
			if(signal(SIGUSR1, func1))
				bit[j] = 1;;
			else if(signal(SIGUSR2, func2))
				bit[j] = 0;
			bit[j] <<= j;
				usleep(200);
			}
			str[i] = atoi(bit);
			free(bit);
			i++;		
		}
	
	return 1;
}
