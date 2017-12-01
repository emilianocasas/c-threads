#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv)
{
	pid_t pid = fork();


	if (pid == -1) printf("Error!\n");
	
	if (pid > 0){
		int status = 0;
		printf("Soy el padre\n");
		pid_t w = wait(&status);
		while (waitpid(pid, &status, WNOHANG|WUNTRACED) == 0) printf("Sigo esperandochanchananana \n");
		printf("Mi hijo %i volvio con status: %i\n", w, status);
	}
	
	if (pid == 0){
	setpgrp();
	printf("Soy el hijo, ejecuto\n");
	//ejecutoProceso();
	int estado = 0;
	char * argumentos[] = { "ps", NULL };
	estado = execvp(argumentos[0], argumentos );
	printf("Hubo un error\n");
	exit(estado);
	}

	return 0;
}

