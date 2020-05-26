/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 1.RBT.c
*       &Created Time: 2020年05月23日 星期六 00时34分25秒
*                      
*       
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1
#define DBLACK 2

typedef struct Node {
	int num, color;  // 0, 1. 2, 红 黑 双重黑
	struct Node *lchild, *rchild;
}Node;

Node _NIL, *NIL = &_NIL;

__attribute__((constructor))
void NIL_init() {
	NIL->num = 0;
	NIL->color = BLACK;
	NIL->lchild = NIL->rchild = NIL;
	return ;
}

Node *init(int num) {
	Node *node =(Node *)malloc(sizeof(Node));
	node->num = num;
	node->color = RED;
	node->lchild = node->rchild = NIL;
	return node;
}

int hasRedChild(Node *node) {
	return node->lchild->color == RED || node->rchild->color == RED;
}

Node *right_rotate(Node *node) {
	Node *temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;
	return temp;
}

Node *left_rotate(Node *node) {
	Node *temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	return temp;
}


Node *insert_maintain(Node *node) {
	if(!hasRedChild(node)) return node;
	if(node->lchild->color == RED && node->rchild->color == RED) {
		if(!hasRedChild(node->lchild) && !hasRedChild(node->rchild)) return node;
		node->color = RED;
		node->rchild->color = node->lchild->color = BLACK;
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
	if(node->num == num) return node;
	if(num > node->num) node->rchild = __insert(node->rchild, num);
	else node->lchild = __insert(node->lchild, num);
	return insert_maintain(node);
}

Node *insert(Node *root, int num) {
	root = __insert(root, num);
	root->color = BLACK;
	return root;
}

Node *predecessor(Node *node) {
	Node *temp = node->lchild;
	while(temp->rchild) temp = temp->rchild;
	return temp;
}


Node *erase_maintain(Node *node) {
	if(node->rchild->color != DBLACK && node->lchild->color != DBLACK) return node;
	if(node->lchild->color == DBLACK) {
		if(node->rchild->color == RED) {
			node = left_rotate(node);
			node->color = BLACK;
			node->lchild = RED;
			node->lchild = erase_maintain(node->lchild);
			return node;
		}
		
		if(!hasRedChild(node->rchild)) {
			node->lchild->color -= 1;
			node->color += 1;
			node->rchild->color -= 1;
			return node;
		}

		if(node->rchild->rchild != RED) {
			node->rchild = right_rotate(node->rchild);
			node->rchild->color = BLACK;
			node->rchild->rchild->color = RED;
		}
		
		node = left_rotate(node);
		node->lchild->color -= 1;
		node->color = node->lchild->color;
		node->lchild->color = node->rchild->color = BLACK;
		return node;
	} else {
		if(node->lchild->color == RED) {
			node = right_rotate(node);
			node->color = BLACK;
			node->rchild = RED;
			node->rchild = erase_maintain(node->rchild);
			return node;
		}

		if(!hasRedChild(node->lchild)) {
			node->rchild->color -= 1;
			node->color -= 1;
			node->lchild->color -= 1;
			return node;
		}
		
		if(node->lchild->lchild != RED) {
			node->lchild = left_rotate(node->lchild);
			node->lchild->color = BLACK;
			node->lchild->lchild->color = RED;
		}

		node = right_rotate(node);
		node->rchild->color -= 1;
		node->color = node->rchild->color;
		node->rchild->color = node->lchild->color = BLACK;
		return node;
	}


}

Node *__erase(Node *node, int num) {
	if(node  == NIL) return node;
	if(num > node->num) node->rchild = __erase(node->rchild, num);
	else if(num <  node->num) node->lchild = __erase(node->lchild, num);
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


Node *erase(Node *root, int num) {
	root = __erase(root, num);
	root->color = BLACK;
	return root;

}


void output(Node *node) {
	if(node == NIL) return ;
//	output(node->lchild);
	printf("%d [%d %d] %s\n", 
		node->num, 
		node->lchild->num, 
		node->rchild->num, 
		node->color ? "BLACK" : "RED"
		);
	output(node->lchild);
	output(node->rchild);
}

void clear(Node *node) {
	if(node == NIL) return ;
	clear(node->lchild);
	clear(node->rchild);
	free(node);
	return ;
}

int main() {
	int op, val;
	Node *root = NIL;
	while(~scanf("%d%d", &op, &val)) {
		switch(op) {
			case 1: root = insert(root, val); break;
			case 2: root = erase(root, val); break;
		}
		output(root);
	};
	return 0;
}
