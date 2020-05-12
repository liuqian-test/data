/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 50_1.cpp
*       &Created Time: 2020年05月12日 星期二 19时02分37秒
*                      
*       
****************************************************************/
#include<iostream>
using namespace std;
#define MAX_N 32
#define MAX_M 65536
long long dp[MAX_N + 5][MAX_M + 5];


int main() {
	//用n个鸡蛋，扔k次，最多可以测试m层楼
	long long n , m;
	cin >> n >> m;
	if(n == 1) {
		cout << m << endl;
		return 0;
	}

	for(long long  k = 1; k <= MAX_M ; k++) {
		dp[1][k] = k;
	}
	for(long long  i = 2; i <= n; i++) {
		for(long long  k = 1; k <= MAX_M; k++) {
			dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;
		}
	}
	long long p = 1;
	while(dp[n][p] < m) p++;
	cout << p << endl;
	
	return 0;
}

