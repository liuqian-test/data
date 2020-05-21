/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 1.VAL.c
*       &Created Time: 2020年05月20日 星期三 17时31分12秒
*                      
*       
****************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int num, h ;
	struct Node *lchild, *rchild;
}Node;

Node _NIL, *NIL = &_NIL;

__attribute__((constructor)) //先于主函数执行
	void init_NIL() {
		NIL->num = 0;
		NIL->h = 0;
		NIL->lchild = NIL->rchild = NIL;
		return ;
	}


Node *init(int num) {
	Node *p = malloc(sizeof(Node));
	p->num = num;
	p->lchild = p->rchild = NIL;
	p->h = 1;
	return p;
}

void UpdateHeight(Node *node) {
	int h1 = node->lchild->h;
	int h2 = node->rchild->h;
	node->h = (h1 > h2 ? h1 : h2) + 1;
	return ;
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
		if(node->lchild->lchild->h < node->lchild->rchild->h){
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

Node *insert(Node *root, int key) {
	if(root == NIL) return init(key);
	if(key > root->num) root->rchild = insert(root->rchild, key);
	else root->lchild = insert(root->lchild, key);
	UpdateHeight(root);
	return maintain(root);
}

Node *predecessor(Node *node) {
	Node *temp = node->lchild;
	while(temp->rchild) temp = temp->rchild;
	return temp;
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



void clear(Node *node) {
	if(node == NIL) return ;
	clear(node->lchild);
	clear(node->rchild);
	free(node);
	return ;
}

int mian() {
	 

	return 0;
}
