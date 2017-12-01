#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv)
{
	kill(15718, 10); // Mando señal
	return 0;
}

