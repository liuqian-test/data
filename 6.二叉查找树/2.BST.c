/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 2.BST.c
*       &Created Time: 2020年05月18日 星期一 15时57分50秒
*                      
*       
****************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	int data;
	struct Node *lchild, *rchild;
}Node;

Node *init(int data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = node->rchild = NULL;
	return node;
} 

Node *insert(Node *node, int data) {
	if(node == NULL) return init(data);
	if(node->data < data) node->rchild = insert(node->rchild, data);
	else node->lchild = insert(node->lchild, data);
	return node;
}

Node *predecessor(Node *node) {
	Node *temp = node->lchild;
	while(temp->rchild) temp = temp->rchild;
	return temp;
}

Node *erase(Node *node, int data) {
	if(node == NULL) return node;
	if(node->data < data) {
		node->rchild = erase(node->rchild, data);
	} else if(node->data > data) {
		node->lchild = erase(node->lchild, data);
	} else {
		if(node->lchild == NULL || node->rchild == NULL) {
			Node *temp = node->lchild ? node->lchild : node->rchild;
			free(node);
			return temp;
		} else {
			Node *temp = predecessor(node);
			node->data = temp->data;
			node->lchild = erase(node->lchild, temp->data);
		}

	}
	return node;
}


void output(Node *node) {
	if(node == NULL) return ;
	output(node->lchild);
	printf("%d ", node->data);
	output(node->rchild);
	return ;
}

void clear(Node *node) {
	if(node == NULL) return ;
	clear(node->lchild);
	clear(node->rchild);
	free(node);
}

int main() {
	srand(time(0));
	int num;
	Node *root = NULL;
	for(int i = 0; i < 10; i++) {
		num = rand() % 100;
		root = insert(root, num);
	}
	output(root);
	printf("\n");
	root = erase(root, root->data);
	output(root);
	printf("\n");
	clear(root);
	return 0;
}
