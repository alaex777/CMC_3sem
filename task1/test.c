#include <stdio.h>

void readLine(char* buff, int size){
	char c = getchar();
	int a = 0;
	while (c != '\n' && a < size){
		buff[a] = c;
		a++;
		c = getchar();
	}
	buff[a] = '\0';
}

void deleteSpaces(char* buff, int length){
	int a = 0;
	int b = 0;
	while(a+1 != length){
		if (buff[a] != ' ' || buff[a+1] != ' '){
			buff[b] = buff[a];
			b++;
		}
		a++;
	}
	if (buff[0] == ' '){
		a = 0;
		while(a+1 != length){
			buff[a] = buff[a+1];
			a++;
		}
	}
	if (buff[b] == ' '){
		buff[0] = '\0';
	}else{
		buff[b] = '\0';
	}
}

void reverseWords(char* buff, int length){

}

int main()
{
	char* p;
	int length = 256;
	readLine(p, length);
	deleteSpaces(p, length);
	printf("%s\n", p);
	return 0;
}