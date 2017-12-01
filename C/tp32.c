#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *funcionHilo(void *threadid);
void uso();

int main (int argc, char *argv[]){
   int nhilos = atoi(argv[1]);
   if (nhilos > 0) {
      pthread_t hilos[nhilos];
      int s, i;
      for(i=0; i<nhilos; i++){
         printf("main(): creando thread %d\n", i);
          s = pthread_create(&hilos[i], NULL, funcionHilo, (void *) i); //Le pasamos como parametro su "numero de hilo", i
         if (s){ 
            printf("main(): Error, pthread_create() retorna %d\n", s);
            exit(-1);
         }
      }
   } else printf("Debe ingresar un número mayor que cero\n");
   printf("main():fin!\n");
   pthread_exit(NULL);
   printf("main():fin 2!\n"); //Esto nunca se va a ejecutar, ya que el main thread termina antes.
}

void *funcionHilo(void *threadid){
   int tid;
   tid = (int ) threadid; //cast
   printf("Mensaje de thread %d!\n", tid);
   sleep(3);
    printf("Fin mensaje de thread %d!\n", tid);
   pthread_exit(NULL);
}
