#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

void *hilo1(void *p);
void *hilo2(void *p);
void *hilo3(void *p);
void *hilo4(void *p);
int flag = 0;

pthread_cond_t v1;
pthread_cond_t v2;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER ;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER ;

int main(int argc, char **argv){
	pthread_cond_init(&v1, NULL); //Inicializo variable de condicion v1

	pthread_t h1; //declaro hilo1
	pthread_t h2; //declaro hilo2
	
	pthread_create(&h2, NULL, hilo2, NULL);
	pthread_create(&h1, NULL, hilo1, NULL); //Creo hilos
	
	pthread_join(h2, NULL);
	printf("fin main\n");
	return 0;
}

void *hilo1(void *p){
	//int veces = 0;
	//while (veces < 10){
		//i++;
		//pthread_mutex_lock(&m);
		//printf("i) Hola\n", veces);
		//pthread_mutex_unlock(&m2);
	//}
	pthread_mutex_lock(&m1);
	printf("Soy el hilo1, señalizo v1..\n");
	flag = 1;
	pthread_cond_broadcast(&v1);
	printf("Termino hilo1 \n");
	pthread_mutex_unlock(&m1);
	pthread_exit(NULL);
 }

void *hilo2(void *p){
	printf("Soy el hilo2, muestro flag %i\n", flag);
	pthread_mutex_lock(&m2);
	if ( !flag ) printf("esperando v1..\n"); 
	pthread_cond_wait(&v1, &m2);
 	sleep(3);
 	printf("Me desperte! (hilo2), muestro flag %i\n", flag);
 	
	pthread_mutex_unlock(&m2);
	pthread_exit(NULL);
}
