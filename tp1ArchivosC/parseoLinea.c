#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *ingresoLinea();
void parseoLinea();
void mostrarTokens();

char *arg[64];
int narg;
char *comandoToken;  
char *comando;
int salir = 0; 

int main(int argc, char **argv){
	ingresoLinea();
	parseoLinea();
	mostrarTokens();
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
        if (salir) {
          free(buf);
          comando=NULL;
		} else comando = buf;
        
        return buf;
}

void parseoLinea(){
 int i=0;
   char *token = (char *)malloc(16 * sizeof(char)) ;
   comandoToken = token;
   comandoToken = strtok(comando, " ");
		while( comandoToken != NULL ){
          arg[i]= comandoToken;
          i++;
          comandoToken = strtok(NULL, " ");
      }
      arg[i] = comandoToken;    //Actualizo arg
      narg = i;
 }
 
 void mostrarTokens(){
	int i=0;
	for (i=0; i<narg; i++){
		printf("token %i:  ", i);
		printf("%s\n", arg[i]);
	}
 }

 
 
 
 
 
