#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("%d, %d \n", getpid(), getppid());
	fork();
	printf("%d, %d \n", getpid(), getppid());
	return 0;
}