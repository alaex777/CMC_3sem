#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

const char * tempfile = "abc";

void SigHndlr(int s){
	unlink(tempfile);
}

int main(int argc, char const *argv[])
{
	signal(SIGINT, SigHndlr);
	create(tempfile, 0666);
	unlink(tempfile);
	return 0;
}