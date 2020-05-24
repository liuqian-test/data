/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 3.AVL.c
*       &Created Time: 2020年05月24日 星期日 20时23分55秒
*                      
*       
****************************************************************/
#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
	int num, h;
	struct Node *lchild, *rchild;
}Node;

Node _NIL, *NIL = &_NIL;

__attribute__((constructor))
void NIL_init() {
	NIL->lchild = NIL->rchild = NIL;
	NIL->num = 0;
	NIL->h = 0;
}

Node *init(int num) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->num = num;
	node->lchild = node->rchild = NIL;
	node->h = 1;
	return node;
}

void UpdateHeight(Node *node) {
	int h1 = node->rchild->h;
	int h2 = node->lchild->h;
	node->h = (h1 > h2 ? h1 : h2) + 1;
}

Node *left_rotate(Node *node) {
	Node *temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	UpdateHeight(node);
	UpdateHeight(temp);
	return temp;
}

Node *right_rotate(Node *node) {
	Node *temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;
	UpdateHeight(node);
	UpdateHeight(temp);
	return temp;
}

Node *maintain(Node *node) {
	if(abs(node->lchild->h - node->rchild->h) <= 1) return node;
	if(node->lchild->h > node->rchild->h) {
		if(node->lchild->rchild->h > node->lchild->lchild->h) {
			node->lchild = left_rotate(node->lchild);
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
	if(node->num == num) return node;
	if(num > node->num) node->rchild = insert(node->rchild, num);
	else node->lchild = insert(node->lchild, num);
	UpdateHeight(node);
	return maintain(node);
}

Node *predecessor(Node *node) {
	Node *t = node->lchild;
	while(t->rchild) t = t->rchild;
	return t;
}

Node *erase(Node *node, int num) {
	if(node == NIL) return node;
	if(num > node->num) node->rchild = erase(node->rchild, num);
	else if(num < node->num) node->lchild = erase(node->lchild, num);
	else {
		if(node->lchild == NIL || node->rchild == NIL) {
			Node *temp = node->lchild ? node->lchild : node->rchild;
			free(node);
			return temp;
		} else {
			Node *temp = predecessor(node);
			node->num = temp->num;
			node->lchild = erase(node->lchild, temp->num);
		}
	
	}
		UpdateHeight(node);
		return maintain(node);
}

void output(Node *node) {
	if(node == NIL) return ;
	output(node->lchild);
	printf("%d [%d %d]\n", node->num, node->lchild->num, node->rchild->num);
	output(node->rchild);
}

void clear(Node *node) {
	if(node == NIL) return ;
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
