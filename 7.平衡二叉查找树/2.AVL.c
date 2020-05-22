/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 2.AVL.c
*       &Created Time: 2020年05月22日 星期五 20时53分17秒
*                      
*       
****************************************************************/
#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
	int num, h;
	struct Node *lchild, *rchild;
}Node;

Node _NIL, *NIL = &_NIL;

__attribute__((constructor))
void __NIL_init() {
	NIL->lchild = NIL->rchild = NIL;
	NIL->num = 0;
	NIL->h = 0;
}

Node *init(int num) {
	Node *node = malloc(sizeof(Node));
	node->num = num;
	node->lchild = node->rchild = NIL;
	node->h = 1;
	return node;
}

void UpdateHeight(Node *node) {
	int h1 = node->rchild->h;
	int h2 = node->lchild->h;
	node->h = h1 > h2 ? h1 : h2;
}

Node *right_rotate(Node *node) {
	Node *temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;
	UpdateHeight(temp);
	UpdateHeight(node);
	return temp;
}

Node *left_rotate(Node *node) {
	Node *temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	UpdateHeight(temp);
	UpdateHeight(node);
	return temp;
}

Node *maintain(Node *node) {
	if(abs(node->lchild->h - node->rchild->h) <= 1) return node;
	if(node->lchild->h > node->rchild->h) {
		if(node->lchild->rchild->h > node->lchild->lchild->h) {
			node->lchild = left_rotate(node->rchild);
		}
			node = right_rotate(node);
	} else {
		if(node->rchild->lchild->h > node->rchild->rchild->h) {
			node->rchild = right_rotate(node->rchild);
		}
			node = left_rotate(node);
	}
	return node;
}

Node *insert(Node *node, int num) {
	if(node == NIL) return init(num);
	if(num == node->num) return node;
	if(num > node->num) node->rchild = insert(node->rchild, num);
	else node->lchild = insert(node->lchild, num);
	UpdateHeight(node);  //在回溯过程中更新树高；
	return maintain(node);
}

Node *erase(Node *node, int val) {
	

	return maintain(node);
}


void output(Node *node) {
	if(node == NIL) return ;
	output(node->lchild);
	printf("%d ", node->num);
	output(node->rchild);
}

void clear(Node * node) {
	if(node == NIL) return;
	clear(node->lchild);
	clear(node->rchild);
	free(node);
}


int main() {
	int op, val;
	Node *node = NIL;
	while(~scanf("%d%d", &op, &val)) {
		switch(op) {
			case 1 : node = insert(node, val); break;
			case 2 : node = erase(node, val); break;
		}
		output(node);
	}
	return 0;
}
