#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	if(fork() != 0){
		if(fork() == 0){
			if(fork() != 0){
				if(fork == 0){
					if(fork() != 0){
						while();
						execl("usr/bin/virus", (char 1) 0);		
					}else{
						wait();
					}		
				}
			}
		}
	}
	return 0;
}