#include "minitalk.h"
#define MAX_CHARS 100
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
	printf("Server PID:%d\n", getpid());
	signal(SIGUSR1, func1);
	signal(SIGUSR2, func2);

	
	while(1)
	{
		printf("\nPEND");
		sleep(5);
	}
	return 0;
}
