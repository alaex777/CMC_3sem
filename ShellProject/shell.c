#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 1024;

int main(){
	// вводим первоначальное приглашение к вводу
	printf("%s", "aleksandrbalasov@MacBook-Pro-Aleksandr-2 $");
	// начинаем бесконечный цикл, который можно будет прервать только exit
	while(true){
		char[MAX_STRING_LENGTH] command;
		int count = 0;
		while(true){
			inp = getchar();
			// если идет \\n, то игнорируем, если \n, то завершаем 
			if (inp == '\\'){
				tmp1 = getchar();
				if(tmp1 == 'n'){
					break;
				}
				tmp2 = getchar()
				if (!((tmp1 == '\\') && (tmp2 == 'n'))){
					command[count] = inp;
					count++;
					command[count] = tmp1;
					count++;
					command[count] = tmp2;
					count++;
				}
			}else{
				command[count] = inp;
				count++;
			}
		}
		
	}
	return 0;
}