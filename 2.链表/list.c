/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: list.c
*       &Created Time: 2020年04月21日 星期二 13时55分51秒
*                      
*       
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

//链表的创建 插入 遍历 删除 反转


typedef struct Node {
	int data;
	struct Node *next;
}Node;

Node *insert(Node *head, Node *node, int ind) {
	if(head == NULL) {
		if(ind != 0) {
			printf("failed\n");
			return head;
		}
	
		head = node;
		return head;
	}

	if(ind == 0) {
		node->next = head;
		head = node;
		return head;
	}

	Node *current = head;
	int count = 0;
	while( current->next != NULL && count < ind - 1) {
		current = current->next;
		count++;
	}

	if(count == ind - 1) {
		node->next = current->next;
		current->next = node;
	}else{
		printf("failed1\n");
		return head;
	}
	return head;
}

Node *delete_node (Node *head, int index) {
	if(head == NULL) return head;
	if(index == 0) {
		Node *temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	
	Node *temp = head;
	int count = 0;
	while(temp && count < index - 1) {
		temp = temp->next;
		count++;
	}

	if(count == index - 1) {
		Node * del = temp->next;
		temp->next = del->next;
		free(del);
		return head;
	}
}

void output(Node *node) {
	if(node == NULL) return ;
	Node *temp = node;
	while(temp) {  //temp不为空 可以保证输出第一个
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

Node *reverse(Node *head) {
	if(head == NULL) return head;
	Node *next_node ,* current_node;
	current_node = head->next;
	head->next = NULL;
	while(current_node) {
		next_node = current_node->next;
		current_node->next = head;
		head = current_node;
		current_node = next_node;
	}
	return head;
}

void clean(Node *node) {
	Node *temp = node;
	while(temp != NULL) {
		Node *del = temp;
		temp = temp->next;
		free(del);
	}
}

int main() {
	Node *head = NULL;
	int num;
	for(int i = 0; i < 5; i++) {
		scanf("%d", &num);
		Node *node = (Node *)malloc(sizeof(Node));
		node->data = num;
		node->next = NULL;
		head = insert(head, node, i);
	}
	//delete_node(head, 2);
	output(head);
	Node *t = reverse(head);
	output(t);
	clean(head);

	return 0;
}
