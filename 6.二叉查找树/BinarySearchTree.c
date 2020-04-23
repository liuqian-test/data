/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: BinarySearchTree.c
*       &Created Time: 2020年04月23日 星期四 14时00分44秒
*                      
*       
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *lchild, *rchild, *father;
}Node;

Node *init(int data,  Node *father) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = node->rchild = NULL;
	node->father = father;
	return node;
}

Node *insert(Node *node, int data) {
	if(node == NULL) node = init(data, NULL);
	else if(data < node->data) {
		if(node->lchild == NULL) node->lchild = init(data, node);
		else node->lchild = insert(node->lchild, data);
	}else {
		if(node->rchild == NULL) node->rchild = init(data, node);	
		else node->rchild = insert(node->rchild, data);
	}

/*	if (node == NULL) {
        node = init(value, NULL);
    } else if (value > node->data) {
        if (node->rchild == NULL) {
            node->rchild = init(value, node);
        } else {
            node->rchild = insert(node->rchild, value);
        }
    } else if (value < node->data) {
        if (node->lchild == NULL) {
            node->lchild = init(value, node);
        } else {
            node->lchild = insert(node->lchild, value);
        }
    }*/
	return node;
}

Node *search(Node *node, int data) {
	if(node == NULL || node->data == data) return node;
	if(node->data < data) search(node->rchild, data);
	else search(node->lchild, data);


/*	 if(node == NULL || node->data == value) {
        return node;
    }else if(value > node->data) {
        if(node->rchild == NULL) {
            return NULL;
        }else {
            search(node->rchild, value);
        }
    }else {
        if(node->lchild == NULL) {
            return NULL;
        }else {
        search(node->lchild, value);
        }
    }*/

} 

//找到左子树中的最大值
Node *predecessor(Node *node) {
	Node *temp = node->lchild;
	while(temp && temp->rchild) {
		temp = temp->rchild;
	}
	return temp;
}

Node *successor(Node *node) {
	Node *temp = node->rchild;
	while(temp && temp->lchild) {
		temp = temp->lchild;
	}
	return temp;
}

int remove_node(Node *node) {
	Node *temp;
	if(node->lchild) {
		temp = node->lchild;
		temp->father = node->father;
	}
	if(node->rchild) {
		temp = node->rchild;
		temp->father = node->father;
	}

	if(node->father->lchild == node) node->father->lchild = temp;
	else node->father->rchild = temp;

	node->lchild = NULL;
	node->rchild = NULL;
	free(node);
}

int delete_node(Node *node, int value) {
	if(node == NULL) return 0;
	Node *current, *delete_n;
	current = search(node, value);
	if(current == NULL) return 0;
	if(current->lchild) delete_n = predecessor(node);
	else if(current->rchild) delete_n = successor(node);
	else current = delete_n;
	current->data = delete_n->data;
	remove_node(delete_n);
	return 1;
}


void output(Node *node) {
	if(node == NULL) return ;
	output(node->lchild);
	printf("%d ", node->data);
	output(node->rchild);
}

int main() {
    Node *node = NULL;
	int arr[10] = {8, 9, 10, 5, 6, 1, 7, 12, 15, 20};
	for(int i = 0; i < 10; i++) {
		node = insert(node, arr[i]);
	}
		
	output(node);
	printf("\n");
	Node *s = search(node, 10);
	printf("查找结果 ：%d\n", s->data);
	delete_node(node, 12);
	output(node);
	return 0;
}
