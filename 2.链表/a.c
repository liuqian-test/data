/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: a.c
*       &Created Time: 2020年04月21日 星期二 14时52分58秒
*                      
*       
****************************************************************/
#include<stdio.h>
#include <stdlib.h>

int main() {
	int a = 1;
	int *k;
	int *p = (int *)malloc(sizeof(int));
	int *q = (int *)malloc(sizeof(int));
	p = &a;
	q = &a;
	printf("p : %p, q : &p", p, q);
	free(p);
	printf("p : %p, q : &p", p, q);

	return 0;
}




