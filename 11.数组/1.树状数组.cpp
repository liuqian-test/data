/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 1.树状数组.cpp
*       &Created Time: 2020年05月24日 星期日 15时58分11秒
*                      
*       
****************************************************************/
#include<iostream>
using namespace std;
#define MAX_N 1000
#define lowbit(x) ((x) & (-x))
int c[MAX_N + 5] = {0};

//改进版本的前缀和

void add(int i, int val, int n) {
	while(i <= n) c[i] += val, i += lowbit(i);
	return ;
}


//原来的前缀和数组
int S(int i) {
	int sum = 0;
	while(i) sum += c[i], i -= lowbit(i);
	return sum;
	}

int main() {
	int n, a;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a;
		add(i, a, n);
	}
	for(int i = 1; i <= n; i++) {
		cout << i << " : " << c[i] << " " << S(i) - S(i - 1) << endl;
	}
	return 0;
}

