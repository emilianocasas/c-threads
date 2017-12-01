#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void Hilo1(void);

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER ;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER ;

int main(void) {
	pthread_t h1 ;
	//pthread_mutex_lock(&m1) ;
	pthread_create(&h1,NULL,(void *)Hilo1,NULL);
	pthread_join(h1,NULL);
	printf("Fin\n");
	exit(1);
}

void Hilo1(void) {
 int i = 0;
 while(i<3){
	 i++;
	 pthread_mutex_lock(&m1) ;
	 printf("Hola\n");
 }
}

