/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: stack.c
*       &Created Time: 2020年04月22日 星期三 15时06分22秒
*                      
*       
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
	int *data;
	int size, top;
}Stack;

void init(Stack *s, int size) {
	s->data = (int *)malloc(sizeof(int) * size);
	s->size = size;
	s->top = -1;
}

void expand(Stack *s) {
	int *temp = s->data;
	s->size = 2 * s->size;
	s->data = (int *)malloc(sizeof(int) * s->size);
	for(int i = 0; i <= s->top; i++) {
		s->data[i] = temp[i];
	}
	free(temp); //释放原来malloc出来的空间
	printf("expand success!\n");
}

void push(Stack *s, int num) {
	if(s == NULL) return ;
	if(s->size <= s->top) {
		expand(s); //扩容
	}
	s->top++;
	s->data[s->top] = num;
}

void pop(Stack *s) {
	s->top--;
	return ;
}

int top(Stack *s) {
	return s->data[s->top];
}

void output(Stack *s) {
	for(int i = 0; i <= s->top; i++) {
		printf("%d ", s->data[i]);
	}
	printf("\n");
}

void clear (Stack * s) {
	free(s->data);
	free(s);
}

int main() {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	init(s, 5);
	
	for(int i = 0;  i < 8; i++) {
		push(s, i);
	}
	output(s);
	int num = top(s);
	printf("%d\n", num);
	pop(s);
	output(s);
	return 0;
}
