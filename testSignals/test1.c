#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

//Перехват и обработка сигнала

int count = 0;

void SigHndlr(int s){
	printf("\n I got SIGINT %d time(s) \n", ++count);
	if (count == 5){
		signal(SIGINT, SIG_DFL);
	}
	else{
		signal(SIGINT, SigHndlr);
	}
}

int main(int argc, char const *argv[]){
	signal(SIGINT, SigHndlr);
	while(1);
	return 0;
}