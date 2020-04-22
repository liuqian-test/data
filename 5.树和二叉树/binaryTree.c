/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: binaryTree.c
*       &Created Time: 2020年04月22日 星期三 16时17分39秒
*                      
*       
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
}Node;

Node * init(int num) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = num;
	node->lchild = node->rchild = NULL;
	return node;
}

Node *insert(Node *root, Node *node) {
	if(root == NULL) {
		root = node;
		return root;
	}
	if(root->data == node->data) return root;
	if(node->data < root->data) root->lchild = insert(root->lchild, node);
	else root->rchild = insert(root->rchild, node);
	return root;
}

void inorder(Node *node) {
	if(node == NULL) return ;
	inorder(node->lchild);
	printf("%d ", node->data);
	inorder(node->rchild);

}

void preorder(Node *node) {
	if(node == NULL)return ;
	printf("%d ", node->data);
	preorder(node->lchild);
	preorder(node->rchild);
}

void postorder(Node *node) {
	if(node == NULL) return ;
	postorder(node->lchild);
	postorder(node->rchild);
	printf("%d ", node->data);
}
int main() {
	Node *root = NULL;
	for(int i = 0; i < 10; i++) {
		Node *newNode = init(i);
		root = insert(root, newNode);
	}
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	return 0;
}
