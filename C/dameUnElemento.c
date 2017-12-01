

#include <stdio.h>

int main(int argc, char **argv){


	static char letra = 'A';
	
	printf("%c", letra++);
	printf("%c", letra);
	return 0;
}

