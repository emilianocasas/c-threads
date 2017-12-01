#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


int main(int argc, char **argv){
	int i = 0;
	char *buf = (char*) malloc(20); 
	char c = ' ';
	
	while (c != '\n'){
		c = (char) getc(stdin);
		buf[i++] = c;
		
}
	i = 0;
	while (buf[i] != '\0'){
	printf("%c", buf[i]);	
	i++;
	}
	return 0;
}

