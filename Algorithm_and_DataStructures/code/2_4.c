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

int pop(stack *S){
    int tmp = S->head->next->element;
	cell *ptr = S->head->next;
	cell *prev = S->head;
	if(ptr != NULL){
		prev->next = ptr->next;
	}
	ptr = ptr->next;
	
    return tmp;
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
    
    char tmp[110];
    
    scanf("%s", tmp);
    
    stack *S = create();
    
    for(int i = 0; tmp[i] !='\0'; i++){
        if('1' <= tmp[i] && tmp[i] <= '9'){
            int value = 0 ;
            while(tmp[i]!='_'){
                value = value * 10 + tmp[i] - '0' ;
                i++;
            }
            push(S, value);
        } else {
            if(tmp[i]=='+'){
                int a = pop(S), b = pop(S);
                push(S, a+b);
            }else if(tmp[i]=='-'){
                int a = pop(S), b = pop(S);
                push(S, b-a);
            }else if(tmp[i]=='*'){
                int a = pop(S), b = pop(S);
                push(S, a*b);
            }else if(tmp[i]=='/'){
                int a = pop(S), b = pop(S);
                push(S, b/a);
            }
        }
    }
    
    print(S);
	printf("\n");
    return 0;
}