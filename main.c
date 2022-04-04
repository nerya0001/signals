#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


void sig_handler(int signum)
{
	int i = 5;
	int j = 0;
	int k;
	switch (signum)
	{
	case SIGCHLD:
		printf("child process died\n");
		
		raise(SIGUSR1);

	case SIGUSR1:
		printf("division by zero\n");
		k = i / j;

	case SIGFPE:
		printf("Floating Point Error\n");
		
		abort();

	case SIGABRT:
		printf("Abort Signal\n");
		kill(-1, SIGCONT); // raises a signal to a specific process

	case SIGCONT:
		printf("finale\n");
		exit(1);
	}
}



int main()
{
	int status;
	signal(SIGCHLD, sig_handler);
	signal(SIGUSR1, sig_handler);
	signal(SIGFPE, sig_handler);
	signal(SIGABRT, sig_handler);
	signal(SIGCONT, sig_handler);
	if (!(fork()))
	{
		exit(1);
	}
	wait(&status);
}