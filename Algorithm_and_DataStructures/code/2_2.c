#include<stdio.h>
#include<stdlib.h>

typedef struct _cell{
    int element;
    struct _cell *next;
}cell;

typedef struct _stack{
    cell *head;
}stack;

/*空のstackを作成する関数*/
stack* create(){
    stack *S = (stack*)malloc(sizeof(stack));
    S->head=(cell*)malloc(sizeof(cell));
    S->head->next = NULL;
    S->head->element=-1;
    return S;
}

/*stack Sの先頭に、要素elementを持つセルを定数時間で追加する関数*/
void push(stack *S, int element){
    cell *add = (cell*)malloc(sizeof(cell));
    add->element = element;
    add->next = S->head->next;
    S->head->next = add;
}

void pop(stack *S){
	cell *ptr = S->head->next;
	cell *prev = S->head;
	if(ptr != NULL){
		prev->next = ptr->next;
	}
	ptr = ptr->next;
}

/*stack Sを先頭から順に表示する関数*/
void print(stack *S){
    cell *ptr = S->head->next;
    while(ptr !=NULL){
        printf("%d ", ptr->element);
        ptr = ptr->next;
    }
    printf("\n");

}

int main(void){
    stack *S = create();
    
    push(S,5);
    push(S,3);
    push(S,6);
    print(S);
    
	pop(S);
    push(S,3);
    push(S,7);
    print(S);
    
    return 0;
}