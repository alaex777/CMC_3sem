#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void alrm(int s){
	printf("\n жду имя \n");
	alarm(5);
}

int main(int argc, char const *argv[])
{
	char s[80];
	signal(SIGALRM, alrm);
	alarm(5);
	printf("Введите имя \n");
	for(;;){
		printf("имя \n");
		if(gets(s) != NULL) break;
	}
	printf("OK! \n");
	return 0;
}