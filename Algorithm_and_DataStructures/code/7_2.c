#include<stdio.h>
#include<stdlib.h>

typedef struct _cell {
    int element;
    struct _cell* next;
}cell;

typedef struct _list {
    cell* head;
}list;

/*空のリストを作成する関数*/
list* create() {
    list* L = (list*)malloc(sizeof(list));
    L->head = (cell*)malloc(sizeof(cell));
    L->head->next = NULL;
    L->head->element = -1;
    return L;
}

/*リストLの先頭に、要素elementを持つセルを定数時間で追加する関数*/
void addFirst(list* L, int element) {
    cell* add = (cell*)malloc(sizeof(cell));
    add->element = element;
    add->next = L->head->next;
    L->head->next = add;
}

/*リストLに、要素elementをソートされた状態を保ちながら挿入する関数*/
void addSort(list* L, int element) {
    cell* add = (cell*)malloc(sizeof(cell));
    add->element = element;
    cell* ptr = L->head->next;
    cell* prev = L->head;
    while (ptr != NULL) {
        if (ptr->element < element) {
            add->next = ptr;
            prev->next = add;
            return;
        }
        else {
            prev = ptr;
        }
        ptr = ptr->next;
    }
    add->next = ptr;
    prev->next = add;
}

/*リストLから、要素elementを持つすべてのセルを線形時間で削除する関数*/
void del(list* L, int element) {
    cell* ptr = L->head->next;
    cell* prev = L->head;
    while (ptr != NULL) {
        if (ptr->element == element) {
            prev->next = ptr->next;
        }
        else {
            prev = ptr;
        }
        ptr = ptr->next;
    }
}

/*リストLを先頭から順に表示する関数*/
void print(list* L) {
    cell* ptr = L->head->next;
    while (ptr != NULL) {
        printf("%d ", ptr->element);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    
	int n, m;
    int i;
	scanf("%d %d", &n, &m);
	//int** matrix = (int**)malloc(sizeof(int*) * n);
    list* L[n];
    for (i = 0; i < n; i++) {
        L[i] = create();
    }
	int s, t;
	for (i = 0;i < m;i++) {
		scanf("%d %d", &s, &t);
        addSort(L[s], t);
        addSort(L[t], s);
	}
    for (i = 0;i < n;i++) {
        print(L[i]);
    }
    
	return 0;
}