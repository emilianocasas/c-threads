#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv){
	
	pid_t t = fork();
	//char argumentos [] = {"ps", NULL};
	int estado = 0;
	
	if (t > 0) printf("Ejecuto ps\n");
	
	if (t==0) estado = execvp("ps", NULL);
	
	
	
	return 0;
}

