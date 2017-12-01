//Espero la señal SIGUSR1, en forma activa (comente pause())
//Cuento la cantidad de recepciones de la señal SIGUSR1 hasta 5 veces
//Si no llegan las señales SIGUSR1 antes de 10 segundos, el programa finalizara

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_usr(int signo);
void handleAlarma(int signo);

int main(int argc, char **argv)
{
	signal(SIGUSR1, sig_usr);
	alarm(15);  // programo señal de alarma para dentro de 10 segundos y no hay handle!
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
	if ( nvez == 2 ) {
		signal(SIGALRM, handleAlarma);
	} else {
		printf("sig_usr():recibi señal %d, %d veces\n",signo,nvez);
	}
}

void handleAlarma(int signo){
	printf("alarmaaaa\n");
}
