/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 4.BST.c
*       &Created Time: 2020年05月20日 星期三 17时05分05秒
*                      
*       
****************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	int num;
	struct Node *lchild, *rchild;
}Node;

Node *init(int num) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->num = num;
	p->lchild = p->rchild = NULL;
	return p;
}

Node *insert(Node *root, int num) {
	if(root == NULL) return init(num);
	if(num > root->num) root->rchild = insert(root->rchild, num);
	else  root->lchild = insert(root->lchild, num);
	return root;
}

Node *predecessor(Node *node) {
	Node *t = node->lchild;
	while(t->rchild) t = t->rchild;
	return t;
}

Node *erase(Node *node, int num) {
	if(node == NULL) return node;
	if(num > node->num) node->rchild = erase(node->rchild, num);
	else if(num < node->num) {
			node->lchild = erase(node->lchild, num);
	} else {
		if(node->lchild == NULL || node->rchild == NULL) {
			Node *temp = node->lchild ? node->lchild : node->rchild;
			free(node);
			return temp;
		} else {
			Node *temp = predecessor(node);
			node->num = temp->num;
			node->lchild = erase(node->lchild,  temp->num);
		}

	}
}

void output(Node *node) {
	if(node == NULL) return ;
	output(node->lchild);
	printf("%d ", node->num);
	output(node->rchild);
} 

void clear(Node *root) {
	if(root == NULL) return ;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
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
	printf("根节点： %d\n", root->num);
	root = erase(root, root->num);
	output(root);

	return 0;
}
