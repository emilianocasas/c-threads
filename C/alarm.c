#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void sig_alarma(int signo);

int main(int argc, char **argv){
	

	
	signal(SIGALRM, sig_alarma);
	alarm(2);	
	while(1){
		printf("Esperando alarma..\n");

		pause();
		
	}
	
	return 0;
}

void sig_alarma(int signo)	{	/* signo=nro de señal */
	printf("sig_alarma(): senial %d\n",signo);
	//exit(0); // por si deseo terminar el programa aqui, la alarma se ejecutaria 1 sola vez
	sleep(3);
	alarm(2);
}


