#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void Hilo2(void);
void Hilo1(void);

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER ;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER ;

int main(void) {
	pthread_t h1 ;
	pthread_t h2 ;
	pthread_mutex_lock(&m1) ;
	pthread_create(&h2,NULL,(void *)Hilo2,NULL);
	pthread_create(&h1,NULL,(void *)Hilo1,NULL);
	pthread_join(h1,NULL);
	pthread_join(h2,NULL);
	printf("Fin\n");
	exit(1);
}

void Hilo1(void) {
	int veces = 1 ;
	while(veces <= 10 ) {
		pthread_mutex_lock(&m2) ;
		printf("%d) Hola ",veces);
		veces ++ ;
		pthread_mutex_unlock(&m1) ;
	}
}

void Hilo2(void){
	int veces = 10 ;
	while(veces != 0 ) {
		pthread_mutex_lock(&m1) ;
		printf("Mundo \n");
		veces -- ;
		pthread_mutex_unlock(&m2) ;
	}
}
