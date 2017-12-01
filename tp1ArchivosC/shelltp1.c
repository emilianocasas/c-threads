#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define simboloSistOp  "¬¬ "

pid_t pid;
pid_t pgid;
int interactivo;
int input;
char *comandoToken;    
char *comando;
char *error;
char *arg[64];
int narg;
int op;
int salir = 0;
char *entrada;
char *salida;

void simboloSO();
void inicio();
void ingreso();

char *ingresoLinea() ;
void parseoLinea();

void proceso();
void ejecutoProceso();

void libero();

int main(int argc, char **argv){
	inicio();
	while (salir != 1 ){
		ingreso();
		proceso();
		libero();
	}
	return 0;
}

void inicio() {
   pid = getpid();       // id de proceso actual
   input = STDIN_FILENO; // descriptor de archivo de stdin
  
   interactivo = isatty(input); 
   comando=NULL;
  
	pgid = getpgrp();
   entrada=NULL;
   salida=NULL;
   error=NULL;
   comandoToken=NULL;
   memset(arg,0,64*sizeof(char *)); //Pongo en 0
   narg=0;
   op=0;
   salir=0;
  // sh.cuentosalida=0;
   entrada=NULL;
   salida=NULL;
   
}

void ingreso(){
	simboloSO();
	ingresoLinea();
	parseoLinea();
	
}

void simboloSO(){
   printf("\n");
   printf(simboloSistOp);
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
        if (salir) {
      free(buf);
      comando=NULL;
		} else comando = buf;
     
		
		return buf;
}

 void parseoLinea() {
	 
   if ( comando == NULL || strlen(comando) == 0 || strcmp(comando,"") == 0 ) { //Retorna si el comando esta vacio
	  strcpy(error,"parseoLinea():Error, no hay comando  a ejecutar");
	   salir = 0;
	   	return;
   }
   
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
      narg = i;					//Actualizo narg
      
      if ( strcmp(arg[i-1],"&") == 0 ) interactivo = 0;
      else interactivo = 1;
     
	  if ( strcmp(arg[0],"exit") == 0 ) op = 0;
	  else op = 1;
	  
	   if ( strcmp(arg[0],"getcwd") == 0 ) op = 2;
		
		 if ( strcmp(arg[0],"cd") == 0 ) op = 3;
		
	 }

 
void proceso(){
	  if (op == 0)		salir = 1;
	  if (op == 1){
					pid = fork();
					if (pid == -1) printf("Error!\n");
	                if (pid > 0){
						if (interactivo){
						    int status = 0;
							pid_t w  = wait(&status);
							}
						}
					if (pid == 0){
							setpgrp();
							pid_t chpid = getpid();
							if (interactivo == 0) printf("Proceso [%d] ejecutado en background", (int) chpid);
							 else ejecutoProceso();
					}
	  }
	 if (op == 2) {
	    long size;
		char *buf;
		char *ptr;
		size = pathconf(".", _PC_PATH_MAX);
		if ((buf = (char *)malloc((size_t)size)) != NULL)
		ptr = getcwd(buf, (size_t)size);
		printf("%s\n",ptr);
		op = 2; 
	}
	
	if (op == 3){
         if (arg[1] == NULL) {
            char *curdir = getcwd(NULL,0);
            if ( curdir != NULL ) printf("%s\n",curdir);
            else {
               printf("proceso(): Error intentando obtener el directorio actual"); 
               }
         } else {
            if (chdir(arg[1]) == -1) {
               printf("proceso(): [%s] directorio invalido",arg[1]); 
            }
         }
      }
}	 
 
 void ejecutoProceso(){
	int estado = 0;
	estado = execvp(arg[0],arg);
	printf("Error, con estado %i\n", estado);
	exit(estado);
 }
 
 void libero() {
   int i;
   if ( comando != NULL ) { free(comando);comando=NULL; }
   for(i=0;i<64;i++) { 
      arg[i]=NULL;
   }
   entrada = NULL;
   salida = NULL;
   if ( comandoToken != NULL ) { free(comandoToken); comandoToken=NULL; }
   if ( error != NULL ) { free(error);error=NULL; }
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 

