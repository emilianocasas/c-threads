#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_usr(int signo);
int volatile i = 1;

int main(int argc, char **argv){
	
	
	signal(SIGUSR2, sig_usr);
	while(i) {
		printf("Bloqueo proceso %d a la espera de senial\n",getpid());
		pause();
		printf("Proceso %d sali de bloqueo!\n",getpid());
	}
	
	return 0;
}

// HANDLE de la señal SIGUSR1
void sig_usr(int signo)	{	/* signo=nro de señal */
	printf("sig_usr():recibi señal %d\n", signo);
	i = 0;
	sleep(1);
}
