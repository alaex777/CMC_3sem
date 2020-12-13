#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	pipe(fd);
	if(fork()){
		close(fd[0]);
		write(fd[1], -1);
		close(fd[1]);
	}else{
		close(fd[0]);
		while(read(fd[0]));
	}
	return 0;
}