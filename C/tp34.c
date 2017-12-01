#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *funcionHilo(void *threadid);
void uso();

int main (int argc, char *argv[]){
	int status = 0;
   int nhilos = atoi(argv[1]);
   if (nhilos > 0) {
      pthread_t hilos[nhilos];
      pthread_attr_t attr;
      pthread_attr_init(&attr);
      pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
      int s,i;
      for(i=0; i<nhilos; i++){
         printf("main(): creando thread %d\n", i);
          s = pthread_create(&hilos[i], &attr, funcionHilo, (void *) i);
	
         
      }
       pthread_attr_destroy(&attr);
      
      for(i=0; i<nhilos; i++){
        printf("main(): haciendo join con thread %d\n", i);
         s = pthread_join(hilos[i],(void **) &status);
         if (s) printf("error\n");
         printf("main(): termino join con thread %d status= %d\n",i, status);
         }
        
      
   } else printf("Debe ingresar un n�mero mayor que cero\n");
  
   printf("main():fin!\n");
   pthread_exit(NULL);

}

void *funcionHilo(void *threadid){
   int tid;
   tid = (int ) threadid;
   printf("Mensaje de thread %d!\n", tid);
   sleep(3);
   printf("fin Mensaje de thread %d!\n", tid);
   pthread_exit((void *) (tid+1));
}
