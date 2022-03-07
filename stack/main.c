#include <stdio.h>

#define MAX 10
#define ERROR -1

typedef int KEY_TYPE;

typedef struct{
	KEY_TYPE key;
}RECORD;

typedef struct{
	RECORD A[MAX+1];
	int numberRecords;
}STACK;

int inicitialize(STACK* p){
	p->numberRecords = 0;
	int i = 0;
	for (i = 0; i < MAX-2; i++){ 
		p->A[i].key = i*2;
	}
	p->numberRecords = i;
}

int insert_queue(int value, STACK* p){
	if( p->numberRecords < MAX ){
		p->A[p->numberRecords].key = value;
		p->numberRecords++;
		return 1;
	}else{
		return 0;
	}
}

void remove_queue(STACK* p){
	p->numberRecords--;
}

void show_queue(STACK* p){
	int i = p->numberRecords-1;
	printf("\nQueue:\n");
	for (i = p->numberRecords-1; i >= 0; i--){
		printf("%d = [ %d ]\n", i, p->A[i].key);
	}
	printf("------------------\n");
}

int search_queue(int key, STACK* p){
	p->A[p->numberRecords].key = key;
	int aux = 0;
	while( p->A[aux].key != key)
		aux++;
	if( aux == p->numberRecords )
		return ERROR;
	return aux;
}

int main(){
	STACK stack;
	inicitialize(&stack);

	show_queue(&stack);
	if(insert_queue(10, &stack)){
		printf("successfully inserted!");
	}else{
		printf("Full stack!");
	}
	
	show_queue(&stack);
	remove_queue(&stack);
	show_queue(&stack);
	
	int aux = search_queue(20, &stack);
	if( aux != -1 ){
		printf("Value 20 found in stack position %d\n", aux);
	}else{
		printf("value not found!\n");
	}
}