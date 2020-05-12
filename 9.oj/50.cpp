/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 50.cpp
*       &Created Time: 2020年05月12日 星期二 18时54分18秒
*                      
*       
****************************************************************/
#include<iostream>
using namespace std;
#define MAX_N 32
#define MAX_M 10000
int dp[MAX_M+ 5][MAX_M + 5];


int main() {
	int n , m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		
		for(int j = 1; j <= m ; j++) {
			if(i == 1) {
				dp[i][j] = j;
				continue;
			}
			
			dp[i][j] = j;
			for(int k = 1; k <= j; k++) {
				dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
			}
		}
	}
	cout << dp[n][m] << endl;

	return 0;
}
