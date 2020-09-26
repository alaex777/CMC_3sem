#include <stdio.h>
#include <stdlib.h>

struct List{
	int elem;
	struct List* nextElem;
};

void PrintList(struct List* list){
	struct List* tmp = list;
	while(tmp != NULL){
		printf("%d\n", (*tmp).elem);
		tmp = (*tmp).nextElem;
	}
}

int length(struct List* list){
	struct List* tmp;
	int count = 0;
	while(tmp != null){
		count++;
		tmp = (*tmp).nextElem;
	}
	return count;
}

void ReverseList(struct List* list){
	struct List* tmp = (struct List*)malloc(sizeof(struct List));
	for(int i = length(list)-1; i >= 0; i--){
		
	}
}

void DeleteList(struct List* list){

}

struct List* MakeList(int N){
	struct List* list;
	struct List* first;
	struct List* last;
	for (int i = 0; i < N; ++i){
		list = (struct List*)malloc(sizeof(struct List));
		(*list).elem = i;
		if (i == 0){
			first = list;
			last = list;
		}
		if(i < N){
			(*last).nextElem = list;
		}else{
			(*last).nextElem = NULL;
		}
		last = list;
	}
	return first;
}

int main(){
	struct List* list1 = MakeList(5);
	PrintList(list1);
	return 0;
}