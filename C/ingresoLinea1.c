#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


char *ingresoLinea(); //No tiene argumentos por que devuelve lo que ingresa el usuario
void mostrarLinea(char *comando);

char *parseoLinea(char* comando);
void mostrarTokens(char *str);

void libero(char* comando);

int main(int argc, char **argv){
       printf("Ingrese una linea:\n");
       char *p = ingresoLinea();
       mostrarLinea(p);
       //printf("\n%s\n",p);
       //printf("%i\n",*p);
       //free(p);
       //char *arg1 = parseoLinea(p); 
       
       return 0;
}


char *ingresoLinea()
{
       char c = ' ';
       int nbytes = sizeof(char); //
       int blocksize = nbytes*10;  // buffer size es de solo 10 caracteres, ampliarlo para mejorar performance
       int nbuf = 0; // cuenta caracteres almacenados en buf
       int nbufsize = blocksize; // tamanio actual del buffer
       char *buf = (char *) malloc(blocksize);
       while (c != '\n'){
               c = (char) getc(stdin);
               buf[nbuf++] = c;
               if ( (nbuf % blocksize) == 0 )
               {
                       nbufsize+=blocksize;
                       buf = realloc(buf,nbufsize);
               }
       }
       buf[nbuf]='\0';
       //printf("La zona de memoria de buf es %p\n", buf);
       return buf;
}

void mostrarLinea(char *comando){
  //int i = 0;
  //while (comando[i] != '\0'){
    //printf("%c", comando[i]);
    //i += 1;
  //}
  printf("%s\n", comando);
}

char *parseoLinea(char* comando){
   int i = 0;
   int nbytes = sizeof(char);
   int blocksize = nbytes*10;   
   char *arg = (char *) malloc(blocksize);
   char *token = (char *) malloc(strlen(comando)+1);
   
   strcpy(token, comando);
   token = strtok(comando, " "); //Obtiene el primer token
   
   while( i<64 && token != NULL ) { //Recorre los otros tokens  
      printf( "%s\n", token );
	  arg[i] = token;
	  token = strtok(NULL, " ");
	  i++;
   }
   
   return arg;
}

void mostrarTokens(char *str){
  int i = 0;
  while (str[i] != '\0'){
    putchar(str[i]);
    i += 1;
  }
  printf("\n");
}

void libero(char* comando){
	printf("Libero la zona de memoria %p", comando);
	free(comando);
}
