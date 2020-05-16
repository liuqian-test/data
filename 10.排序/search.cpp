/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: search.cpp
*       &Created Time: 2020年05月16日 星期六 19时26分57秒
*                      
*       
****************************************************************/
#include<iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int a[8] = {10, 8, 2, 6, 99, 1, 56, 16};
	sort(a + 0, a + 8, cmp);
	for(int i = 0; i < 8; i++) {
		cout << a[i] << endl;
	}
	return 0;
}

