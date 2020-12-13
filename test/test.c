#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	for(int i = 1; i < argc; i++){
		int status;
		if(fork() > 0){
			wait(&status);
			printf("process-father\n");
			continue;
		}
		execlp(argv[i], argv[i], 0);
		exit();
	}
}