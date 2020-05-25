/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 1.RBT.c
*       &Created Time: 2020年05月23日 星期六 00时34分25秒
*                      
*       
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1
#define DBLACK 2

typedef struct Node {
	int num, color;  // 0, 1. 2, 红 黑 双重黑
	struct Node *lchild, *rchild;
}Node;

Node _NIL, *NIL = &_NIL;

__attribute__((constructor))
void NIL_init() {
	NIL->num = 0;
	NIL->color = BLACK;
	NIL->lchild = NIL->rchild = NIL;
	return ;
}

Node *init(int num) {
	Node *node =(Node *)malloc(sizeof(Node));
	node->num = num;
	node->color = RED;
	node->lchild = node->rchild = NIL;
	return node;
}

int hasRedChild(Node *node) {
	return node->lchild->color == RED || node->rchild->color == RED;
}

Node *insert_maintain(Node *node) {
	if(!hasRedChild(node)) return node;


	return node;
}

Node *__insert(Node *node, int num) {
	if(node == NIL) return init(num);
	if(node->num == num) return node;
	if(num > node->num) node->rchild = __insert(node->rchild, num);
	else node->lchild = __insert(node->lchild, num);
	return insert_maintain(node);
}

Node *insert(Node *root, int num) {
	root = __insert(root, num);
	root->color = BLACK;
	return root;
}


void clear(Node *node) {
	if(node == NIL) return ;
	clear(node->lchild);
	clear(node->rchild);
	free(node);
	return ;
}

int main() {

	return 0;
}
