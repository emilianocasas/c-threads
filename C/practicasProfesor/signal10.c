#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void sig_usr1(int signo);
void sig_usr2(int signo);
void sig_int(int signo);
void sig_alarm(int signo);
void sig_quit(int signo);

volatile int loopeo = 1;

int main(int argc, char **argv) {

	// handlers de SIGUSR1 y SIGUSR2
	signal(SIGUSR1,sig_usr1);
	signal(SIGUSR2,sig_usr2);
	signal(SIGINT,sig_int);
	signal(SIGALRM,sig_alarm);
	signal(SIGQUIT,sig_quit);

	sigset_t set,pendientes;
	// inicializo lleno
	sigfillset(&set);  // inicializo vacio: sigemptyset(&set); 
	// quito SIGUSR1,SIGUSR2
	sigdelset(&set,SIGUSR1);
	sigdelset(&set,SIGUSR2); // agrego señales: sigaddset(&set,SIGUSR1);

	sigprocmask(SIG_BLOCK,&set,NULL); // bloqueo
		// seccion critica que permite tratar a SIGUSR1, SIGUSR2
		printf("main(): entro en seccion critica (pid=%d)!\n",getpid());
		while(loopeo) {
			printf("main(): seccion critica, duermo 2 seg (pid=%d)!\n",getpid());
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

void sig_int(int signo) {
	printf("Recibi SIGINT !\n");
}

void sig_alarm(int signo) {
	printf("Recibi SIGALRM !\n");
}

void sig_quit(int signo) {
	printf("Recibi SIGQUIT !\n");
}
