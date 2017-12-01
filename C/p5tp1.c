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
			printf("hijo: a=%d\n",a);
			const char *programa = "ls";
			char *argumentos[] = { "ls","-l","afafjakfjasfkjasñlfjkasklñ",NULL };
			int ret = execvp(programa,argumentos);
			printf("hijo: termine de ejecutar execv()=%d!\n",ret);
			break;
		break;
		default: // padre
			printf("padre: sumo 10 a variable a\n");
			a+=10;
			printf("padre: a=%d\n",a);
			printf("padre: id proceso hijo=%d\n",(int) pid);
			printf("padre: esperando que hijo termine...\n");
			int estado;
			waitpid(pid,&estado,WUNTRACED);
			printf("padre: hijo termino con estado=%d\n",estado);
			break;
			}
			return 0;
 }
