#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv){  
	int estado = 0;
	pid_t childPid;
	childPid = fork();
	
	if (childPid > 0) { //padre
		printf("Soy el padre con pid %d, mi hijo es %d.\n", getpid(), childPid);
	    pid_t pidh = waitpid(0,&estado,WUNTRACED);
	    // pid_t pidh = wait(&estado);
		printf("pidh tiene un %d\n", pidh);
		 //printf("Termino mi hijo %d con un %d.\n", pidh, (estado/256));
		
	} else {
		printf("Hijo saliendo...\n");
		sleep(6);
		printf("Soy el hijo con pid %d, mi padre es %d\n", getpid(), getppid());
		exit(4);
	}
	return 0;
}

