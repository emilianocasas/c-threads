#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "sh.h"

char* ingresoLinea();
void mostrarString(char *str);
int main(void)
{
  char *cadena = ingresoLinea();
  mostrarString(cadena);
  return 0;
}

char* ingresoLinea(){
  char c = ' ';
  int nbytes = sizeof(char);
  int nbuf = 0; // cuenta caracteres almacenados en buf
  int nbufsize = 0; // tamanio actual del buffer
  char *buf = (char *) malloc(nbytes);
  while (c != '\n'){
    c = (char) getc(stdin);
    buf[nbuf] = c;
    if ( (nbuf % nbytes) == 0 ) {
      nbufsize+= nbytes; // aumento el tamanio del buffer en n bytes
      buf = (char *) realloc(buf,nbufsize);
    }
    nbuf += 1;
  }
   buf[nbuf]='\0'; // agregar un caracter nulo al final:
   return buf;
}

void mostrarString(char *str){
  int i = 0;
  while (str[i] != '\0'){
    putchar(str[i]);
    i += 1;
  }
  printf("\n");
}


