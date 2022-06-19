#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int id = fork();
	printf("this is process %d\n", id);
	return (0);
}
