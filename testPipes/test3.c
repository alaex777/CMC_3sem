#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	pipe(fd);
	if(fork() == 0){
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
		execlp("print", "print", 0);
	}
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	execl("/usr/bin/wc", "wc", 0);
	return 0;
}