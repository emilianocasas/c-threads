#include <stdio.h>
 
int main()
{
//int a=5;
//int *pa = &a;

char e = 'e';
char *pc;
pc = &e;
 
//int array[10]={0,2,3,5,5,6,7,8,9,0}; //Declarar e inicializar un array.
//int *puntero = &array[0]; //Le damos la dirección de inicio del array
//int i; //variable contadora...
 
pc[0]='a';
 
 
//for (i=0;i<10;i++)
//printf("%d y %i y %p y %p\n",*(puntero+i),*puntero, puntero, (puntero+1)); //imprimimos los valores del puntero. 
//printf("La direccion es %p y tiene un %i\n", pa, *pa);
//printf("Muestro %c y la direccion %p\n", pc[i], pc);
 
return 0;
}



