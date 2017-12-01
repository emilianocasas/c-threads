#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	
    pid_t pid,pidh;
    int estado=0;
    char linea[256];
	// ingreso comando
    printf(">>");
    gets(linea);
    while ( strcmp(linea,"exit") != 0 ) {
		// tengo un ingreso de comando distinto de exit!
		
		pid = fork();
		if ( pid > 0 ) {
			pidh = wait(&estado);
		} else {
			estado = execlp(linea, linea, NULL);
			printf("Error!, fallo el comando [%s]\n",linea);
			exit(estado);
		}
		// ingreso comando
		printf(">>");
		gets(linea);
	}
	
	return 0;
}
