#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int count = 1;
struct sigaction action, sa;

void SigHandler(int s){
	printf("I got SIGINT %d time(s)\n", count++);
	if(count == 5){
		action.sa_handler = SIG_DFL;
		sigaction(SIGINT, &action, &sa);
	}
}

int main(int argc, char const *argv[]){
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	if(sigprocmask(SIG_UNBLOCK, &sigset, NULL) == -1){
		printf("sigprocmask() error\n");
		return -1;
	}
	action.sa_handler = SigHandler;
	sigaction(SIGINT, &action, &sa);
	while(1);
	return 0;
}