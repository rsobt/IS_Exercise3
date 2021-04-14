#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
	int element;
	struct _node *right;
	struct _node *left;
}node;

typedef struct _tree{
	node *root;
}tree;

/*空のに分木を作成する関数*/
tree* create(){
	tree *T = (tree*)malloc(sizeof(tree));
	T->root=NULL;
	return T;
}

/*二分探索木Tに、木の高さに対して線形時間でノードnodeを追加する関数*/
void insert_body(node *now,node *add){
	//左に行く
	if(now->element>add->element){
		if(now->left==NULL){now->left=add;}
		else{insert_body(now->left,add);}
	}
	//右に行く
	else{
		if(now->right==NULL){now->right=add;}
		else{insert_body(now->right,add);}
	}
	return;
}
void insert(tree *T, int element){
	node *add =(node*)malloc(sizeof(node));
	add->element = element;
	add->right = NULL;
	add->left = NULL;

	if(T->root==NULL){T->root = add;}
	else{insert_body(T->root, add);}
	return;
}

/*二分探索木Tを深さ優先探索し、ノード数に対して線形時間で通りかけ順(in-oprder)で表現する関数*/
void in_order_body(node *now){
	if(now==NULL){return;}
	in_order_body(now->left);
	printf("%d ",now->element);
	in_order_body(now->right);
	return;
}

void in_order(tree *T){
	in_order_body(T->root);
	printf("\n");
	return;
}

int main(){
	tree *T = create();

	insert(T,7);
	insert(T,3);
	insert(T,10);
	insert(T,1);
	insert(T,4);
	insert(T,8);
	insert(T,6);
	insert(T,5);

	in_order(T);

	return 0;
}