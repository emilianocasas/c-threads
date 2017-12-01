#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t childPid = 0;
	childPid = fork();
	
	if (childPid > 0){
		//Para el padre, en childPid, esta el pid del hijo.
		printf("Soy el padre, mi pid es %i y el de mi hijo es %i. Mi groupID es %i\n", getpid(), childPid, getpgrp());  
		//El padre crea al grupo, luego, su groupID es igual a su pid.
	}else{
		//Para el hijo, en childPid hay un 0.
		printf("Soy el hijo, mi pid es %i y el de mi hijo es %i. Mi groupID es %i\n", getpid(), getppid(), getpgrp()); 	
		//El hijo hereda el groupID de su padre, que en este caso particular, es igual a su pid.
	}
	return 0;
}

