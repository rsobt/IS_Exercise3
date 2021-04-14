#include<stdio.h>
#include<stdlib.h>

typedef struct _cell{
    int element;
    struct _cell *next;
}cell;

typedef struct _list{
    cell *head;
}list;

/*空のリストを作成する関数*/
list* create(){
    list *L = (list*)malloc(sizeof(list));
    L->head=(cell*)malloc(sizeof(cell));
    L->head->next = NULL;
    L->head->element=-1;
    return L;
}

/*リストLの先頭に、要素elementを持つセルを定数時間で追加する関数*/
void addFirst(list *L,int element){
    cell *add = (cell*)malloc(sizeof(cell));
    add->element = element;
    add->next = L->head->next;
    L->head->next = add;
}

/*リストLから、要素elementを持つすべてのセルを線形時間で削除する関数*/
void del(list *L, int element){
    cell *ptr = L->head->next;
    cell *prev = L->head;
    while(ptr !=NULL){
        if(ptr->element == element){
            prev->next = ptr->next;
        }else{
            prev=ptr;
        }
        ptr = ptr->next;
    }
}

/*リストLを先頭から順に表示する関数*/
void print(list *L){
    cell *ptr = L->head->next;
    while(ptr !=NULL){
        printf("%d ", ptr->element);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(void){
    list *L = create();
    
    addFirst(L,5);
    addFirst(L,3);
    addFirst(L,5);
    addFirst(L,6);
    print(L);
    
    del(L,5);
    addFirst(L,5);
    print(L);
    
    return 0;
}