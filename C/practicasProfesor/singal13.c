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
	signal(SIGUSR1,sig_usr1);
	sigset_t set,pendientes;
	sigfillset(&set);   
	sigdelset(&set,SIGUSR1);
	sigprocmask(SIG_BLOCK,&set,NULL); // bloqueo
	
	while(loopeo) {
		printf("main(): seccion critica, pid: %d\n",getpid());
		pause();
	}
	printf("main(): saliendo de seccion critica!\n");
	
	sigpending(&pendientes);  
    for (i=0; i<32; i++){
		if ( sigismember(&pendientes, i)) printf("Llego %i mientras estaba en seccion critica!\n", i);
	}
	return 0;
}

void sig_usr1(int signo) {
	printf("Recibi SIGUSR1 y salgo del loop!\n");
	loopeo = 0;
}


