/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: queue.c
*       &Created Time: 2020年04月21日 星期二 16时10分19秒
*                      
*       
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

//循环队列的入队 出队 遍历

typedef struct Queue {
	int *data;
	int length, head, tail;
	int count;
}Queue;

void init(Queue *q, int len) {
	q->data = (int *)malloc(sizeof(int) * len);
	q->head = 0;
	q->tail = -1;
	q->length = len;
	q->count = 0;
}

void push(Queue *q, int num) {
	if(q == NULL) return ;
	if(q->count >= q->length) {
		return;
	}

	q->tail++;
	q->data[(q->tail) % (q->length)] = num;
	q->count++;
}

void pop(Queue *q) {
	if(q == NULL) return ;
	q->head++;
	q->count--;
}

void output(Queue *q) {
	for(int i = q->head; i <= q->tail; i++) {
		printf("%d ", q->data[i % q->length]);
	}
	printf("\n");
}

void clean(Queue*q) {
	free(q->data);
	free(q);
}

int main() {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	init(q, 5);
	for(int i = 0; i < 5; i++) {
		push(q, i);
	}

	output(q);
	pop(q);
	push(q, 8);
	push(q, 9);
	output(q);
	clean(q);
	return 0;
}
