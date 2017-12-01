/*
 * gets.c
 * 
 * Copyright 2015 Emiliano <emiliano@emiliano-To-be-filled-by-O-E-M>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <string.h>


int main(int argc, char **argv)
{	char n[10] ;
	int i = 0;
	int longitud = 0;
	int palabras = 0;
	
	printf("Introducir una cadena.\n");
	scanf("%s", n);
	//gets(n);
	printf("Se introdujo %s.\n",n);
	
	 //if (n != 32){
		//printf("No es vacio.\n");
	 //} else {
		// printf("Si es vacio.\n");
	 //}
	 
	 //printf("%c .\n",n[0]);
	 
	   //for (i=0; i<3; i++){
		//	printf("%c\n",n[i]);

	   //}
	
	longitud = strlen(n);
	printf("La cadena tiene longitud %i.\n", longitud);   
	   
	   for (i=0; i<longitud; i++){
			printf("%c\n",n[i]);
				if ( n[i]== 32 ){
						palabras = palabras + 1;
				 }
	   }
	   
	printf("Se ingresaron %i palabras.\n", palabras);
	return 0;
}

