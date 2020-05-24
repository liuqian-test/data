/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 1.has_ring.c
*       &Created Time: 2020年05月24日 星期日 01时14分56秒
*                      
*       
****************************************************************/
#include<stdio.h>

typedef struct Node {
	int val;
	struct Node *next;
}Node;

//判断链表是否有环；

int has_ring(Node *head) {
	
	//head为链表头节点；
	while(head != NULL) {
		Node *temp = head->next;
		while(temp != head && temp != NULL) temp = temp->next;
		if(temp == head) return 1;
		head = head->next;
	
	}
	return 0;
}



int main() {
	
	return 0;
}
