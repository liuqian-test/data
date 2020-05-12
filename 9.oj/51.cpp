/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 51.cpp
*       &Created Time: 2020年05月12日 星期二 20时10分14秒
*                      
*       
****************************************************************/
#include<iostream>
using namespace std;
#define MAX_N 1000
int f[MAX_N + 5]; //像向下数白色格子的数量
int a[MAX_N + 5];  //刚开始记录最后一行数据，后来更新
int s[MAX_N + 5], top = -1;

//信息整合，记录每个点向下数的白色格子数量，实现将4次方降到3次，使用单调栈再次降低到2次方
int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	a[m + 1] = -1;
	f[m + 1] = 0;
	for(int i = 1; i <=n; i++) {
		for(int j = 1, val; j <= m; j++) {
			cin >> val;
			if(val == 1) a[j] += 1;
			else a[j] = 0;
		}
		top = -1;
		s[++top] = m + 1;
		for(int j = m; j >= 1; j--) {
			while(a[s[top]] > a[j]) top--;
			f[j] = (s[top] - j) * a[j] + f[s[top]];
			f[j] %= 100007;
			s[++top] = j;
			ans += f[j];
			ans %= 100007;
			
		}
	}
	
	return 0;
}

