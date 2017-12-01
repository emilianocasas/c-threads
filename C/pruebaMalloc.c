#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int i;
	//char a = 'a';
	//char *buf = &a;
	char *buf = (char *) malloc(sizeof(char));
	
	printf("Se tiene una zona de memoria %p\n", buf);
	buf[0]= 'a';
	buf[1]= 'b';
	buf[2]= 'c';
	buf[3]= 'd';
	buf[4]= 'e';
		
	printf("En buf tengo %c\n", *buf);
	
	for (i =0; i< 5; i++){
	printf("En buf, posicion %i hay un %c, con direccion de memoria %p. En *buf tengo n %c\n", i, buf[i], buf, *buf);
	
	}
	return 0;
}

