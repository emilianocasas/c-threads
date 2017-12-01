#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
	
    pid_t pid, pidh;
    int estado=0;
    pid = fork();
    if ( pid > 0 ) {
		printf("mi pid es %d, PID de mi hijo es %d\n",getpid(),pid);
		pidh = wait(&estado);
		printf("termino mi hijo %d\n",pidh);
		printf("termino mi hijo con estado %d\n",estado/256);
		printf("hago otro wait() adicional. ");
		pidh=wait(NULL);
		printf("Fin wait() adicional!,  pidh=%d\n",pidh);
		exit(2);
	} else {
		estado = execlp("ps", "ps", NULL);
		printf("que paso???? estado=%d\n",estado);
		exit(1);
	}
	return 0;
}
