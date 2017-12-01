#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

int contador_global = 5;
void *modificarContador(void *threadid);
void *hilo1(void *p);
void *hilo2(void *p);
pthread_mutex_t lock;

int main(int argc, char *argv[]){
	
	//int estadoHilo1;
	//int estadoHilo2;

	pthread_t h1;
	pthread_t h2;
	//pthread_mutex_init(&lock, NULL);
		printf("Comienzo main\n");
	
	pthread_create(&h1, NULL, modificarContador, (void *)  1);
	pthread_create(&h2, NULL, modificarContador, (void *)  2);
	
	
	//pthread_create(&h2, NULL, hilo2, NULL);
	//pthread_create(&h1, NULL, hilo1, NULL);
	//printf("Muestro a y b : %i y %i\n", a, b);
	
	pthread_join(h2, NULL);
	pthread_join(h1, NULL);
	
	
	//printf("Termino main, con estado 1 : %i y con estado 2 : %i\n", estadoHilo1, estadoHilo2);
	//printf("Muestro c y d : %i y %i\n", c, d);
	
	printf("termino main\n");
	return 0;
}



void *modificarContador(void *threadid){
	//pthread_mutex_lock(&lock);
	int tid;
   tid = (int) threadid;
   while(contador_global != 100) {
		++contador_global;
		printf("%i: el contador tiene %i \n", tid, contador_global);
	}
	printf("Termine, soy el hilo %i\n", tid);
	//pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}
	
	







// implemento hilo1
void *hilo1(void *p) {
	while(contador_global != 10) {
		--contador_global;
		printf("hilo1 variable global %d !\n",contador_global);
	}
	printf("TERMINE HILO 1\n");
	//pthread_exit(3); //Devuelve null al join
	pthread_exit(NULL);
}

// implemento hilo2
void *hilo2(void *p) {
	while(contador_global != 10) {
		++contador_global;
		printf("hilo2 variable global %d !\n",contador_global);
		}
	printf("TERMINE HILO 2\n");
pthread_exit(NULL);
	//pthread_exit(2);
}


