#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

void *productor(void *);
int contador_global = 0;

int main(int argc, char *argv[]){
	int i = 0;
	int estado = 0;
	int numHilos = atoi(argv[1]);
	printf("El numero de hilos es %i\n", numHilos);
	
	for (i=0; i<numHilos; i++){
	printf("main (): creando thread %i\n", i);
	//int estado = 0;
	pthread_t a;	  
    //pthread_attr_t attr;
	//pthread_attr_init(&attr);
	//pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	//pthread_create(&a,&attr,productor,NULL);
	pthread_create(&a,NULL,productor,NULL);
	pthread_join(a,&estado);
	printf("Termino join del hilo %i con status %i\n", i, estado);
	//pthread_attr_destroy(&attr);
	}

	printf("Fin main():1\n");
	pthread_exit(NULL);
	printf("Fin main():2\n");
	return 0;
}

void *productor(void *p) {
		printf("Mensaje del thread %i!\n", contador_global);
		sleep(3);
		printf("Fin mensaje del thread %i!\n", contador_global);
		contador_global++;
		pthread_exit(contador_global);
}








