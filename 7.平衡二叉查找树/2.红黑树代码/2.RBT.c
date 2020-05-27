/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 2.RBT.c
*       &Created Time: 2020年05月27日 星期三 14时05分26秒
*                      
*       
****************************************************************/
#include<stdio.h>
#include <stdlib.h>

#define RED 0
#define	BLACK 1
#define DBLACK 2

typedef struct Node {
	int num, color;
	struct Node *lchild, *rchild;
}Node;

Node _NIL, *NIL = &_NIL;

__attribute__((constructor))
void NIL_init() {
	NIL->rchild = NIL->rchild = NIL;
	NIL->num = 0;
	NIL->color = BLACK;
}

Node *init(int num) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->num = num;
	temp->lchild = temp->rchild = NIL;
	temp->color = RED;
	return temp;
}

int hasRedChild(Node *node) {
	return node->lchild->color == RED || node->rchild->color == RED;
} 

Node *left_rotate(Node *node) {
	Node *temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	return temp;
}

Node *right_rotate(Node *node) {
	Node *temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;
	return temp;
}

Node *insert_maintain(Node *node) {
	if(!hasRedChild(node)) return node;
	if(node->lchild->color == RED && node->rchild->color == RED) {
		if(!hasRedChild(node->lchild) && !hasRedChild(node->rchild)) return node;
		node->color = RED;
		node->lchild->color = node->rchild->color = BLACK;
	}
	
	if(node->lchild->color == RED) {
		if(!hasRedChild(node->lchild)) return node;
		if(node->lchild->rchild->color == RED) {
			node->lchild = left_rotate(node->lchild);
		}
		node = right_rotate(node);
	} else {
		if(!hasRedChild(node->rchild)) return node;
		if(node->rchild->lchild->color == RED) {
			node->rchild = right_rotate(node->rchild);
		}
		node = left_rotate(node);
	}
		node->color = RED;
		node->lchild->color = node->rchild->color = BLACK;
		return node;	
}

Node *__insert(Node *node, int num) {
	if(node == NIL) return init(num);
	if(num == node->num) return node;
	if(num > node->num) node->rchild = __insert(node->rchild, num);
	else if(num < node->num) node->lchild = __insert(node->lchild, num);
	return insert_maintain(node);
}

Node *insert(Node *node, int num) {
	node = __insert(node, num);
	node->color = BLACK;
	return node;
}

Node *predecessor(Node *node) {
	Node *t = node->lchild;
	while(t->rchild) t = t->rchild;
	return t;
}

Node *erase_maintain(Node *node) {
	if(node->lchild->color != DBLACK && node->rchild->color != DBLACK) return node;
	if(node->lchild->color == DBLACK) {
		if(node->rchild->color == RED) {
			node = left_rotate(node);
			node->color = BLACK;
			node->lchild->color = RED;
			node->lchild = erase_maintain(node->lchild);
			return node;
		}

		if(!hasRedChild(node->rchild)) {
			node->lchild->color -= 1;
			node->color += 1;
			node->rchild->color -= 1;
			return node;
		}

		if(node->rchild->rchild->color != RED) {
			node->rchild = right_rotate(node->rchild);
			node->rchild->color = BLACK;
			node->rchild->rchild->color = RED;
		}
			node = left_rotate(node);
			node->lchild -= 1;
			node->color = node->lchild->color;
			node->lchild->color = node->rchild->color = BLACK;
			return node;

	} else {
		if(node->lchild->color == RED) {
			node = right_rotate(node);
			node->color = BLACK;
			node->rchild->color = RED;
			node->rchild = erase_maintain(node->rchild);
			return node;
		}

		if(!hasRedChild(node->lchild)) {
			node->color += 1;
			node->rchild -= 1;
			node->lchild -= 1;
			return node;
		}
		
		if(node->lchild->lchild != RED) {
			node->lchild = left_rotate(node->lchild);
			node->lchild->color = BLACK;
			node->lchild->lchild = RED;
		}

			node = right_rotate(node);
			node->color = node->rchild->color;
			node->rchild -= 1;
			node->lchild->color = node->rchild->color = BLACK;
			return node;	
	}
}

Node *__erase(Node *node, int num) {
	if(node == NIL) return node;
	if(num > node->num) node->rchild = __erase(node->rchild, num);
	else if(num < node->num) node->lchild = __erase(node->lchild, num);
	else {
		if(node->lchild == NIL || node->rchild == NIL) {
			Node *temp = node->lchild == NIL ? node->rchild : node->lchild;
			temp->color += node->color;
			free(node);
			return temp;
		} else {
			Node *temp = predecessor(node);
			node->num = temp->num;
			node->lchild = __erase(node->lchild, temp->num);
		}
	}
		return erase_maintain(node);
}

Node *erase (Node *node, int num) {
	node = __erase(node, num);
	node->color = BLACK;
	return node;
}


void output(Node *node) {
	if(node == NIL) return ;
	output(node->lchild);
	printf("%d [%d %d] %s\n",
			node->num,
			node->lchild->num,
			node->rchild->num,
			node->color ? "BLACK" : "RED"
			);
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
