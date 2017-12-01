#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *Hilo2(void);
void *Hilo1(void);

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER ;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER ;

int main(void) {
	pthread_t h1 ;
	pthread_t h2 ;
	//pthread_create(&h2,NULL,(void *)Hilo2,NULL);
	pthread_create(&h1,NULL,(void *)Hilo1,NULL);
	pthread_join(h1,NULL);
	printf("Fin\n");
	exit(1);	
	return 0;
}

void *Hilo1(void) {
	int i = 0;
	while (i<5){
	  i++;
		pthread_mutex_lock(&m1);
		printf("Hilo1\n"); 
		pthread_mutex_unlock(&m1);
	}
}


void *Hilo2(void){
		pthread_mutex_lock(&m1) ;
		printf("Hilo2\n");
		pthread_mutex_unlock(&m2) ;
}


