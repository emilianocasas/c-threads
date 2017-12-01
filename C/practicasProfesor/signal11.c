#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void sig_usr(int signo);
int i=0;

int main(int argc, char **argv)
{
	signal(SIGALRM, sig_usr);
	alarm(3);
	while (1){
			printf("Bloqueo proceso %d a la espera de senial\n",getpid());
			pause();
    }
	return 0;
}

void sig_usr(int signo)	{	// signo=nro de señal
	i++;
	printf("ALARMA!!, sig_usr():recibi señal %d, %i\n", signo, i);
	alarm(3);
}


