// Espero la señal SIGUSR1, en forma activa (comente pause())
//Cuento la cantidad de recepciones de la señal SIGUSR1 hasta 5 veces
//Si no llegan las señales SIGUSR1 antes de 10 segundos, el programa 
//ejecuta el handle de la alarma y continua, pero la alarma no vuelve a ejecutarse
 
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_usr(int signo);
void sig_alarma(int signo);

int main(int argc, char **argv)
{
	signal(SIGUSR1, sig_usr);
	signal(SIGALRM, sig_alarma);
	alarm(10);  // programo señal de alarma para dentro de 10 segundos 
	while(1) {
		printf("Bloqueo proceso %d a la espera de senial\n",getpid());
		//pause();
		printf("Proceso %d sali de bloqueo!\n",getpid());
	}
	return 0;
}

// HANDLE de la señal SIGUSR1
void sig_usr(int signo)	{	/* signo=nro de señal */
	static int nvez=0;
	nvez++;
	if ( nvez == 6 ) {
		signal(SIGUSR1, SIG_DFL);
	} else {
		printf("sig_usr():recibi señal %d, %d veces\n",signo,nvez);
		sleep(1);
	}
}

// HANDLE de la señal SIGALRM
void sig_alarma(int signo)	{	/* signo=nro de señal */
	printf("sig_alarma(): senial %d\n",signo);
	sleep(3);
}
