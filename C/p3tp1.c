#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <string.h>

int main(void) {
	int a=4;
	printf("padre: id de proceso=%d\n",(int) getpid());
	printf("padre: a=%d\n",a);
	printf("padre:lanzo fork()!\n");
	pid_t pid = fork(); 
	switch (pid) {
		case -1: // error, padre
			printf("padre:Error en fork()!\n");
		break;
		case 0: // hijo
			printf("hijo: id de proceso=%d\n",(int) getpid());
			printf("hijo: a=%d\n",a);
			printf("hijo: sumo 1 a variable a\n");
			a++;
			printf("hijo: a=%d\n",a);
		break;
		default: // padre
			printf("padre: sumo 10 a variable a\n");
			a+=10;
			printf("padre: a=%d\n",a);
			break;
   }
			return 0;
 }
