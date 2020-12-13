#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_CNT 100
int target_pid, cnt;
int fd[2];
int status;

void SigHndlr(int s){
	if (cnt < MAX_CNT){
		read(fd[0], &cnt, sizeof(int));
		cnt++;
		write(fd[1], &cnt, sizeof(int));
		kill(target_pid, SIGUSR1);
	}else if(target_pid == getppid()){
		printf("Child is going to be terminated\n");
		close(fd[1]);
		close(fd[0]);
		exit(0);
	}else kill(target_pid, SIGUSR1);
} 

int main(int argc, char const *argv[]){
	pipe(fd);
	signal(SIGUSR1, SigHndlr);
	cnt = 0;
	if (target_pid = fork()){
		write(fd[1], &cnt, sizeof(int));
		while(wait(&status) == -1);
		printf("Parent is going to be terminated\n");
		close(fd[1]);
		close(fd[0]);
	}else{
		read(fd[0], &cnt, sizeof(int));
		target_pid = getppid();
		write(fd[1], &cnt, sizeof(int));
		kill(target_pid, SIGUSR1);
		for(;;);
	}
	return 0;
}