/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 1.构造.c
*       &Created Time: 2020年04月19日 星期日 16时59分57秒
*                      
*       
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

//顺序表的构造 插入 扩容 查找 删除 遍历 复习

typedef struct Node{
	int *data;
	int len, size;
}Node;

Node *init(int len) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = (int *)malloc(sizeof(int) * len);
	node->len = 0;
	node->size = len;
	return node;
}

void expand(Node *node) {

	int *temp = node->data;
	node->size = 2 * node->size;
	node->data = (int *)malloc(sizeof(int) * node->size);
	for(int i = 0; i < node->len; i++) {
		node->data[i] = temp[i];
	}
	//printf("%d**\n", node->data[node->len - 1 ]);
	free(temp);

}



void insert(Node *node, int ind, int num) {
	if(node == NULL) return ;
	if(ind < 0 || ind > node->size)return ;
	if(node->len >= node->size ) expand(node);
	for(int i = ind; i < node->len; i++) {
		node->data[i + 1] = node->data[i]; 
	}
	node->data[ind] = num;
	node->len++;   //len是实际的长度，不是下标
}

int select1(Node *node, int num) {
	int index = 0;
	for(int i = 0; i < node->len; i++) {
		if(node->data[i] == num) {	
			index = i;
			break;
		}
	
	}
	return index;	
}


void delete(Node *node, int num) {
		for(int i = 0; i < node->len; i++) {
			if(node->data[i] == num) {
				for(int j = i; j < node->len - 1; j++) {
					node->data[j] = node->data[j + 1];
				}
			}
		}
}
void output(Node *node) {
	for(int i = 0; i < node->len; i++) {
		printf("%d\n", node->data[i]);
	}
	printf("\n");
}




void clear(Node *node) {
	free(node->data);
	free(node);
}
int main() {
	Node *node = init(5);
	int i = 3;
	int num = 9;
	int j = 0;
	while(num != 0) {
	scanf("%d", &num);
	insert(node, j++, num);
	i--;
	}
	int index = 0;
	if((index = select1(node, 2)) != 0) {
		printf("2的位置是: %d\n", index);
	}else {
		printf("列表中没有2\n");
	}
	
	delete(node, 3);
	
	output(node);
	clear(node);
	return 0;
}
