
#include <stdio.h>

int main(int argc, char **argv)
{
	
	return 0;
}

void proceso() {
//...
	switch(sh.op) {
		case 0:
	    sh.salir = 1;
		break;
		case 1:
		pid_t pid = fork();
			switch (pid) {
			case -1:
				printf("Error en fork\n");
			break;
		case 0:
			setpgrp();
			pid_t chpid = getpid();

				if (sh.interactivo)
					tcsetpgrp(sh.input,chpid); // debe controlar la terminal
				else
					printf("Proceso [%d] ejecutado en background\n", (int) chpid);
					ejecutoProceso();
					if (printError()) exit(EXIT_FAILURE); // retorno con error
						else exit(EXIT_SUCCESS); // retorno Ok
		break;
		default:

				if (sh.interactivo) {
					tcsetpgrp(sh.input,pid); 
				int terminationStatus;
				while(waitpid(pid, &terminationStatus,WUNTRACED | WNOHANG) == 0);
				tcsetpgrp(sh.input, sh.pgid);
				
				
}
