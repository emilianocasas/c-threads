

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// hilo a ejecutar
void *productor(void *);
void *consumidor(void *);

// produce un elemento
char dame_un_elemento();

// datos globales compartidos por todos los hilos de este proceso
char buffer[5];
int contador=0;
int cuento_a=0;

int main(int argc, char **argv) {

	pthread_t thrp,thrc;
	int estado = pthread_create(&thrp,NULL,productor,NULL);
	int estado2 = pthread_create(&thrc,NULL,consumidor,NULL);
	
	printf("%i\n", estado);
	printf("%i\n", estado2);

	pthread_join(thrp,NULL);
	pthread_join(thrc,NULL);
	
	return 0;
}

// implemento productor
void *productor(void *p) {
	int in=0;
	int temp;
	while(cuento_a != 4) {
		while(contador == 5) /* do nothing! */ ;
		buffer[in]=dame_un_elemento();
		if ( buffer[in] == 'A' ) cuento_a++;
		printf("p[%c]\n",buffer[in]);
		/* seccion critica */
		// hacemos contador++ en 3 pasos para forzar interrupcion en la seccion critica y provocar fallo
		temp=contador;
		temp=temp+1;
		usleep(200000);
		contador=temp;
		/* fin seccion critica */
		in=(in + 1) % 5; // in=0..4
		//sleep(1);
	}
	pthread_exit(NULL);
}

// implemento consumidor
void *consumidor(void *p) {
	int out=0;
	int temp;
	while(cuento_a != 4) {
		while(contador == 0) {
			if ( cuento_a == 4 ) 
				pthread_exit(NULL);
		}
		printf("c[%c]\n",buffer[out]);
		/* seccion critica */
		temp=contador;
		temp=temp-1;
		contador=temp;
		/* fin seccion critica */
		out=(out + 1) % 5; // out=0..4
		//sleep(2);
	}
	pthread_exit(NULL);
}

// implemento dame_un_elemento
char dame_un_elemento() {
	static char letra = 'A';
	if ( letra == ('Z'+1) ) letra = 'A';
	return letra++;
}

