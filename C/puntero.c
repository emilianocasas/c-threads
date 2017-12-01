#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <string.h>

int main(int argc, char **argv)
{
	
	//int a=6;
	//La variable puntero tendra una direccion de memoria donde se almcenara un int
	//int *puntero;
	//puntero = &a;
	//Si nos referimos a puntero, hablamos de la direccion de memoria, si no referimos a 
	// *puntero, hablamos del valor alojado en la seccion de memoria donde apunta
	
	//En a y *puntero esta el dato que esta siendo apuntado
	//printf("El valor de a es: %d. \n El valor de *puntero es: %d. \n",a,*puntero);
	//En &a y puntero esta la direccion de memoria del dato que esta siendo apuntado.
    //printf("La direccion de memoria de *puntero es: %p. En a hay un %p \n",puntero, &a);
	//int i = 0;
	//int bytes = sizeof(char);
	//char a = 'a';
	//char *p = &a; 
	//int byte = sizeof(int);
	//printf("En byte hay %i\n", byte);
	//p =  (char *) malloc(bytes);
	
	//printf("Malloc nos dio la posicion de memoria %p, la cual es de tamaño %i BYTES\n", p, bytes);

	//printf("Malloc nos dio la posicion de memoria %p\n", p);
	
	//printf("La direccion es %p y tiene un %c\n", p, *p);
	int a;
	printf("Muestro valor %p\n", &a); 
	
	//for (i=0; i<25; i++){
	//printf("Muestro posicion: %c\n", p[i]);
	//}
	return 0;
}

