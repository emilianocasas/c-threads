#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_usr(int signo);

int main(int argc, char **argv)
{
	signal(SIGUSR1, sig_usr);
	while(1) {
		printf("Bloqueo proceso %d a la espera de senial\n",getpid());
		pause();
		printf("Proceso %d sali de bloqueo!\n",getpid());
	}
	return 0;
}

// HANDLE de la señal SIGUSR1
void sig_usr(int signo)	{	/* signo=nro de señal */
	static int nvez=0;
	nvez++;
	if ( nvez == 3 ) {
		signal(SIGUSR1, SIG_IGN);
	} else {
		printf("sig_usr():recibi señal %d, %d veces\n",signo,nvez);
		sleep(1);
	}
}
