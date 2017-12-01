#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

void *funcionHilo1(void *p);
void *funcionHilo2(void *p);

volatile int variableGlobal = 10;

pthread_mutex_t m1;

int main(int argc, char **argv){
	pthread_mutex_init(&m1, NULL);
	pthread_mutex_init(&m1, NULL);
	pthread_t h1;
	pthread_t h2;	
	pthread_create(&h1, NULL, funcionHilo1, NULL);	
	pthread_create(&h2, NULL, funcionHilo2, NULL);	
    return 0;
}

void *funcionHilo1(void *p){
	printf("Soy el hilo1, bloqueo al mutex\n");
	pthread_mutex_lock(&m1);
	printf("Mutex bloqueado, hago un sleep\n");
	sleep(2);
	printf("Mutex bloqueado, hago un sleep\n");
	pthread_mutex_unlock(&m1);
	printf("Mutex desbloqueado\n");
}

void *funcionHilo1(void *p){
	printf("Soy el hilo1, bloqueo al mutex\n");
	pthread_mutex_lock(&m1);
	printf("Mutex bloqueado, hago un sleep\n");
	sleep(2);
	printf("Mutex bloqueado, hago un sleep\n");
	pthread_mutex_unlock(&m1);
	printf("Mutex desbloqueado\n");
}
