
#include <pthread.h>

       #include <string.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <errno.h>
       #include <ctype.h>



// hilo a ejecutar
void *hilo1(void *);
void *hilo2(void *);

int contador_global=5;

int main(int argc, char **argv){
	//int ret1;
	//int ret2;
	pthread_t thr1,thr2;
	
	pthread_create(&thr2,NULL,hilo2,NULL);
	pthread_create(&thr1,NULL,hilo1,NULL);
	
	//pthread_join(thr2,ret2);
	//pthread_join(thr1,ret1); //Espera a que el hilo identificado con el id termine y devuelva algo o no
	//pthread_join(thr2,NULL);
	//pthread_join(thr1,NULL); //Espera a que el hilo identificado con el id termine y devuelva algo o no

	//printf("Hilo 1 devolvio con valor %i\n", ret1);
	//printf("Hilo 2 devolvio con valor %i\n", ret2);
	
	return 0;
}

// implemento hilo1
void *hilo1(void *p) {
	while(contador_global != 10) {
		printf("hilo1 en ejecucion!\n");
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
		printf("hilo2 en ejecucion!\n");
		++contador_global;
		printf("hilo2 variable global %d !\n",contador_global);
		}
	printf("TERMINE HILO 2\n");
pthread_exit(NULL);
	//pthread_exit(2);
}

// implemento hilo3


