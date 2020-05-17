/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 250.cpp
*       &Created Time: 2020年05月17日 星期日 20时11分23秒
*                      
*       
****************************************************************/
#include<iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
int a[MAX_N + 5];
int s[MAX_N + 5];
int g[MAX_N + 5];
int n, sum, c, ans;


int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		sum += a[i];
	}
	c = sum / n;
	for(int i = 1; i <= n; i++) {
		g[i] = s[i] - i * c;
	}
	sort(g + 1, g + 1 +  n);
	c = g[n / 2];
	for(long long i = 1; i <= n; i++) {
		ans += abs(g[i] - c);
	}
	cout << ans << endl;
	return 0;
}
