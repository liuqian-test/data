/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 242.cpp
*       &Created Time: 2020年05月17日 星期日 16时33分59秒
*                      
*       
****************************************************************/
#include<iostream>
using namespace std;
#define MAX_N 100000
#define INF 0x3f3f3f3f
int a[MAX_N + 5];
int b[MAX_N + 5];
int sum[MAX_N + 5];
int n, m;

bool check(int A) {
	for(int i = 1; i <= n; i++) {
		b[i] = a[i] - A;
		sum[i] = b[i] + sum[i - 1];
	}
	int Y = 0;
	for(int j = m; j <= n; j++) {
		Y = min(Y, sum[j - m]);
		if(sum[j] - Y >= 0) return true;
	}


}


int bs(int l, int r) {
	if(l == r) return l;
	int mid = (l + r + 1) >> 1;
	if(check(mid)) return bs(mid ,  r);
	return bs(l, mid - 1);
}


int main() {
	cin >> n >> m;
	int l = INF, r = -INF;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] *= 1000;
		l = min(l, a[i]);
		r = max(r, a[i]);

	}
	cout << bs(l, r) << endl;
	return 0;
}
