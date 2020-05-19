/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 1.BinaryST.c
*       &Created Time: 2020年05月15日 星期五 17时37分25秒
*                      
*       
****************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
}Node;

Node *getNewNode(int key) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = key;
	node->lchild = node->rchild = NULL;
	return node;
}

Node *insert(Node *root, int key) {
	if(root == NULL) return getNewNode(key);
	if(root->data > key) root->lchild = insert(root->lchild, key);
	else  root->rchild = insert(root->rchild, key);
	return root;
}

Node *predecessor(Node *node) {
	Node *temp = node->lchild;
	while(temp->rchild) temp = temp->rchild;
	return temp;
}
Node *erase(Node *root, int key) {
	if(root == NULL) return root;
	if(root->data > key) root->lchild = erase(root->lchild, key);
	else if(root->data < key) root->rchild = erase(root->rchild, key);
	else {
		if(root->lchild == NULL || root->rchild == NULL) {
			Node *temp = root->lchild ? root->lchild : root->rchild;
			free(root);
			return temp;
		} else {
			Node *temp = predecessor(root);
			root->data = temp->data;
			root->lchild = erase(root->lchild, temp->data);
		}
	}
	return root;
}

void output(Node *node) {
	if(node == NULL) return ;
	output(node->lchild);
	printf("%d ", node->data);
	output(node->rchild);
	return ;
} 

void __output(Node *node) {
	output(node);
	printf("\n");
	return ;
}

void clear(Node *root) {
	if(root == NULL) return ;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
	return ;
} 

int main() {
	srand(time(0));
    Node *root = NULL;
	int num;
	for(int i = 1; i < 10; i++) {
		num = rand() % 100;
		root = insert(root, num);
	} 
	__output(root);
	root = erase(root, root->data);
	__output(root);
	clear(root);
	return 0;
}
