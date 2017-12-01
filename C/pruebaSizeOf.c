#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char **argv)
{	int a = sizeof(char);
	printf("%i\n", a);
	
	return 0;
}

