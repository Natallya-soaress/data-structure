#include <stdio.h>

#define MAX 14
#define ERROR -1

typedef int KEY_TYPE;

typedef struct{
	KEY_TYPE key;
}RECORD;

typedef struct{
	RECORD A[MAX+1];
	int numberRecords;
}QUEUE;

void initialize(QUEUE* F){
	int i = 0;
	for (i = 0; i < MAX-2; i++){
		F->A[i].key = i*2;
	}
	F->numberRecords = i;
}

void show_queue(QUEUE* F){
	int i = 0;
	printf("QUEUE:\n");
	for (i = 0; i < F->numberRecords; i++){
		printf("[ %d ] ", F->A[i].key);
	}
	printf("\n\n");
}

int insert_queue(KEY_TYPE kt, QUEUE* F){
	if( F->numberRecords >= MAX )
		return 0;
	F->A[F->numberRecords].key = kt;
	F->numberRecords++;
	return 1;
}

int remove_queue(QUEUE* F){
	if( F->numberRecords <= 0 )
		return 0;
	int i = 1;
	for (i; i < F->numberRecords; i++){
		F->A[i-1].key = F->A[i].key;
	}
	F->numberRecords--;
	return 0;
}

int search_queue(KEY_TYPE kt, QUEUE* F){
	F->A[F->numberRecords].key = kt; 
	int i = 0;
	while( F->A[i].key != kt)
		i++;
	if( i >= F->numberRecords )
		return ERROR;
	return i+2;
}

int main(){
	QUEUE fi;
	initialize(&fi);
	show_queue(&fi);

	insert_queue(84, &fi);
	show_queue(&fi);

	remove_queue(&fi);
	show_queue(&fi);

	printf("The key sought is at position %d in the queue\n\n", search_queue(6, &fi) );
	return 0;
}