#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>

void alr(int s){
	printf("\n быстрее!!! \n");
}

int main(int argc, char const *argv[])
{
	char s[80];
	int pid;

	signal(SIGALRM, alr);
	if((pid = fork())){
		for(;;){
			sleep(5);
			kill(pid, SIGALRM);
		}
	}else{
		printf("Введите имя \n");
		for(;;){
			printf("имя: \n");
			if(gets(s) != NULL) break;
		}
		printf("OK!\n");
		kill(getppid(), SIGKILL);
	}
	return 0;
}