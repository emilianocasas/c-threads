#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void sig_usr1(int signo);
void sig_usr2(int signo);

volatile int loopeo = 1;

int main(int argc, char **argv) {
	int i = 0;
	
	signal(SIGUSR1,sig_usr1); //handlers
	signal(SIGUSR2,sig_usr2);
	
	sigset_t set,pendientes; //declaro los sets
	sigfillset(&set);  // lleno, para vacio: sigemptyset(&set); 
	
	sigdelset(&set,SIGUSR1); // quito SIGUSR1,SIGUSR2
	sigdelset(&set,SIGUSR2); // agrego señales: sigaddset(&set,SIGUSR1);

	sigprocmask(SIG_BLOCK,&set,NULL); // bloqueo
		
	while(loopeo) {
			printf("main(): bloqueo proceso a la espera de senial (pid=%d)!\n",getpid());
			pause();
		}
		
	printf("main(): saliendo del bloqueo!\n");
		
	sigpending(&pendientes);  // señales que llegaron durante el bloqueo
	
	for (i=0; i<32; i++){
		if ( sigismember(&pendientes, i)) printf("Llego %i mientras estaba en seccion critica!\n", i);
	}
	
	return 0;
}

void sig_usr1(int signo) {
	printf("Recibi SIGUSR1 !\n");
}

void sig_usr2(int signo) {
	printf("Recibi SIGUSR2 y salgo de loop!\n");
	loopeo=0;
}
