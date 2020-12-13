#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd;
	int pid;
	mkfifo("fifo", S_IFIFO | 0666);
	fd = open("fifo", O_RDONLY | O_NONBLOCK);
	while(read(fd, &pid, sizeof(int)) == -1){
		printf("Server %d got message from %d !\n", getpid(), pid);
	}
	close(fd);
	unlink("fifo");
	return 0;
}