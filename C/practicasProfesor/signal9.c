#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void sig_usr1(int signo);
void sig_usr2(int signo);

volatile int loopeo = 1;

int main(int argc, char **argv) {
	
	sigset_t set,pendientes;
	// inicializo vacio
	sigemptyset(&set); 
	// agrego señales:
	sigaddset(&set,SIGALRM);
	sigaddset(&set,SIGQUIT); 
	sigaddset(&set,SIGINT); 

	// handlers de SIGUSR1 y SIGUSR2
	signal(SIGUSR1,sig_usr1);
	signal(SIGUSR2,sig_usr2);

	sigprocmask(SIG_BLOCK,&set,NULL); // bloqueo
		// seccion critica que permite tratar a SIGUSR1, SIGUSR2
		printf("main(): entro en seccion critica (pid=%d)!\n",getpid());
		while(loopeo) {
			printf("main(): seccion critica, duermo 2 seg! (pid=%d)\n",getpid());
			sleep(2);
		}
		printf("main(): saliendo de seccion critica!\n");
	sigpending(&pendientes);  // señales que llegaron durante el bloqueo
	if ( sigismember(&pendientes,SIGINT) ) {
		// recibi SIGINT durante seccion critica
		printf("Llego SIGINT mientras estaba en seccion critica!\n");
	}
	printf("main(): voy a desbloquear señales!\n");
	sigprocmask(SIG_UNBLOCK,&set,NULL); // desbloqueo
	printf("main(): desbloqueo de señales hecho!\n");
	
	return 0;
}

void sig_usr1(int signo) {
	printf("Recibi SIGUSR1 !\n");
}

void sig_usr2(int signo) {
	printf("Recibi SIGUSR2 y salgo de loop!\n");
	loopeo=0;
}
