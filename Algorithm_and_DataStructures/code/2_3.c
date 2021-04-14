#include<stdio.h>
#include<stdlib.h>

typedef struct _cell{
    int element;
    struct _cell *next;
}cell;

typedef struct _queue{
    cell *head;
}queue;

/*空のqueueを作成する関数*/
queue* create(){
    queue *Q = (queue*)malloc(sizeof(queue));
    Q->head=(cell*)malloc(sizeof(cell));
    Q->head->next = NULL;
    Q->head->element=-1;
    return Q;
}

void enqueue(queue *Q, int element){
	cell *ptr = Q->head->next;
	if(ptr == NULL){
		cell *add = (cell*)malloc(sizeof(cell));
        add->element = element;
        add->next = Q->head->next;
        Q->head->next = add;
	}else{
		while(ptr->next != NULL){
	    	ptr = ptr ->next;
		}
		cell *add = (cell*)malloc(sizeof(cell));
		add->element = element;
		add->next = NULL;
		ptr->next = add;
	}
}

void dequeue(queue *Q){
	cell *ptr = Q->head->next;
	cell *prev = Q->head;
	if(ptr != NULL){
		prev->next = ptr->next;
	}
	ptr = ptr->next;
}

/*queue Qを先頭から順に表示する関数*/
void print(queue *Q){
    cell *ptr = Q->head->next;
    while(ptr !=NULL){
        printf("%d ", ptr->element);
        ptr = ptr->next;
    }
    printf("\n");

}

int main(void){
    queue *Q = create();
    
    enqueue(Q,5);
    enqueue(Q,3);
    enqueue(Q,6);
    print(Q);
    
	dequeue(Q);
    enqueue(Q,3);
    enqueue(Q,7);
    print(Q);
    
    return 0;
}