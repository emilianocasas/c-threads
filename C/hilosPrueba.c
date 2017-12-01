#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


char *ingresoLinea(); //No tiene argumentos por que devuelve lo que ingresa el usuario
void mostrarLinea(char *comando);


int main()
{
	
	int estado = 0;
   int  i = 0;
   char *token            = (char *)malloc(16 * sizeof(char)) ;
   //char *comandoingresado = (char *)malloc(16 * sizeof(char)) ;
  char *comandotokens [32] ;

	printf("Ingrese una linea:\n");
    char *comandoingresado = ingresoLinea();
    int longitud = strlen(comandoingresado);
    int l = longitud - 1;
    
    int salir = strcmp(comandoingresado, "exit");
    printf("La variable salir tiene un %i\n", salir);
    //if (comandoingresado == "exit") 
    //printf("Es exit\n");
    //else 
    //printf("No es exit\n");
    
    
    if (comandoingresado[l] == '&') 
    printf("El ultimo es un &\n");
    else
     printf("El ultimo no es un &\n");
    //mostrarLinea(comandoingresado);
       
   //printf("MI PROMPT=> ");
   //gets(comandoingresado);

    token = strtok(comandoingresado, " ");
    while( token != NULL )
     {
          comandotokens[i]= token;
          i++;
          token = strtok(NULL, " ");
      }
      //if (token == "&") printf("aaaaaaa\n");
      comandotokens[i] = token;
	
	//printf("%s\n", comandotokens[0]);
	//printf("%s\n", comandotokens[1]);
	//printf("%s\n", comandotokens[2]);	
		
     //estado = execvp(comandotokens[0],comandotokens);

     printf("Error\n");
     exit(estado);
			return 0;
}

char *ingresoLinea() {
       char c = ' ';
       int nbytes = sizeof(char); //
       int blocksize = nbytes*10;  // buffer size es de solo 10 caracteres, ampliarlo para mejorar performance
       int nbuf = 0; // cuenta caracteres almacenados en buf
       int nbufsize = blocksize; // tamanio actual del buffer
       char *buf = (char *) malloc(blocksize);
       c = (char) getc(stdin);
       while (c != 10 && c != 13){
               buf[nbuf++] = c;
               if ( (nbuf % blocksize) == 0 )
               {
                       nbufsize+=blocksize;
                       buf = realloc(buf,nbufsize);
               }
               c = (char) getc(stdin);
       }
       buf[nbuf]='\0';
       //printf("La zona de memoria de buf es %p\n", buf);
       return buf;
}


void mostrarLinea(char *comando){
  printf("%s\n", comando);
}
