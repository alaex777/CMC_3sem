#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd;
	int pid = getpid();
	fd = open("fifo", O_RDWR);
	write(fd, &pid, sizeof(int));
	close(fd);
	return 0;
}