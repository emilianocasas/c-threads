#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv){
	pid_t pid;
	int estado = 0;
	char linea[256];
	 printf(">>");
	 gets(linea);
	 while ( strcmp(linea,"exit") != 0 ) {
		pid = fork();
		if ( pid > 0 ) {
			printf("inicie el pid %d\n",pid);
			} else {
		estado = execlp(linea, linea, NULL);
			printf("Error!, fallo el comando [%s]\n",linea);
			exit(estado);
		}
		printf(">>");
		gets(linea);
	}
	printf("Termino el shell\n");
	return 0;
}

