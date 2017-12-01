#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t childPid;
	//Ambos procesos tendran childPid1 y childPid2 como variables si se ponen (aca) al principio (pq el proceso principal la tiene, luego con fork,
	//el hijo la copia) con basura si no se cambia o no se hace un fork.
	//pid_t pidh;
	childPid = fork();
	
	
	if (childPid > 0){
		pid_t childPid2;
		pid_t pidh;
		printf("Soy el padre, mi id es %i, el de mi hijo1 es %i\n", getpid(), childPid);
		pidh = waitpid(childPid, NULL, WUNTRACED);
		printf("Soy el padre, estuve esperando por mi hijo1 con id %i\n", pidh);
		
		
		childPid2 = fork();
		
			if (childPid2 > 0){
			pid_t pidh2;
			printf("Soy el padre DENUEVO, mi id es %i, el de mi hijo2 es %i\n", getpid(), childPid2);
			pidh2 = waitpid(childPid2, NULL, WUNTRACED);	
			printf("Soy el padre, estuve esperando  por mi hijo2 con id %i\n", pidh2);
			} else {
			printf("Soy el hijo2, mi id es %i, el de mi padre es %i\n", getpid(), getppid());
			}
	}else{
		printf("Soy el hijo1, mi id es %i, el de mi padre es %i\n", getpid(), getppid());
		//printf("Hago el sleep..\n");
		//sleep(5);
		//printf("Soy el hijo, termino\n");
	}
	

	return 0;
}

