#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct Command{
	struct Command* next;
	char word[];
};

void PrintCommand(struct Command* command){
	struct Command* tmp = command;
	while(tmp != NULL){
		printf("%s", (*tmp).word);
		tmp = (*tmp).next;
	}
}

struct Command* SetCommand(int N){
	struct Command* command;
	struct Command* first;
	struct Command* last;
	for (int i = 0; i < N; ++i){
		command = (struct Command*)malloc(sizeof(struct Command));
		scanf("%s", (*command).word);
		if (strncmp((*command).word, "\n", strlen((*command).word)) == 0) break;
		if (i == 0){
			first = command;
			last = command;
		}
		if(i < N){
			(*command).next = command;
		}else{
			(*last).next = NULL;
		}
		last = command;
	}
	return first;
}

int main()
{
	printf("%s", "aleksandrbalasov@MacBook-Pro-Aleksandr-2 $");
	struct Command* cmd = SetCommand(5);
	//PrintCommand(cmd);
	struct Command* tmp = cmd;
	printf("%s", (*tmp).word);
	tmp = (*tmp).next;
	printf("%s", (*tmp).word);
	return 0;
}