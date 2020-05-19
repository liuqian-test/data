/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 3.BST.c
*       &Created Time: 2020年05月18日 星期一 16时08分35秒
*                      
*       
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->lchild = erase(root->lchild, key);
    else if (key > root->key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}



void in_order(Node *root) {
	if(root == NULL) return ;
	in_order(root->lchild);
	printf("%d ", root->key);
	in_order(root->rchild);
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {
    
	srand(time(0));
	int num;
    Node *root = NULL;
	for(int i = 0; i < 10; i++) {
		num = rand() % 100;
	   root = insert(root, num);
	}
		printf("%d\n", root->key);
        in_order(root);
		printf("\n");
		root = erase(root, root->key); 
		in_order(root);
		clear(root);
    return 0;
}

