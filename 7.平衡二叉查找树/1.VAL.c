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

Node *insert(Node *root, int key); {
	if(root == NIL) return init(key);
	if

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
