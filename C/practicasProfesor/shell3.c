#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void chequeo_proceso(int signal);

int main(int argc, char **argv) {
	
    pid_t pid;
    int estado=0;
    char linea[256];
    
    // declaro senial
    //cada tres segundos va a hacer la funcion chequeo_proceso
    signal(SIGALRM,chequeo_proceso);
    alarm(10);
    
	// ingreso comando
    printf(">>");
    gets(linea);
    while ( strcmp(linea,"exit") != 0 ) {
		// tengo un ingreso de comando distinto de exit!
		
		pid = fork();
		if ( pid > 0 ) {
			printf("inicie el pid %d\n",pid);
			
		} else {
			// estado devuelve -1 si hubo un error, si no, se cambia la imagen del proceso
			// en excelp, el primer parametro se trata del nombre del programa y se confia en el contenido de la variable de entorno $PATH
			//el primer parametro es el nombre del programa que buscara, y el segundo es el programa. Termina siempre en null
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

// manipulador de la senial de alarma
//el parametro int signal se lo pasa el sistema operativo.
void chequeo_proceso(int signal) {
    pid_t pidh;
    int estado=0;
    printf("Chequeo la finalizacion de procesos\n");
    // con WHNOHANG, si el hijo con pid no especificado cambia de estado, devolver inmediatamente. No se bloque el proceso padre esperando
    // Con el 0, no especificamos ningun pid de los posibles hijos
	while( (pidh = waitpid(0,&estado,WNOHANG)) != 0 ) {
		// termino hijo
		printf("termino el pid %d\n",pidh);
	}
    alarm(3);
}
