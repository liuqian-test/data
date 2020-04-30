/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 44.cpp
*       &Created Time: 2020年04月30日 星期四 19时30分24秒
*                      
*       
****************************************************************/
#include<iostream>
using namespace std;
#define MAX_N 1000000
int dp[MAX_N + 5];
int a[MAX_N + 5];  //最长上升子序列第i位的值

//未优化
int main() {
	int n, ans = 0;;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			if(a[j] >= a[i]) continue;
			 dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}


//优化正确的
/*#include<iostream>
using namespace std;
#define MAX_N 1000000
int dp[MAX_N + 5];
int len[MAX_N + 5], ans = 0;  //
int a[MAX_N + 5];  //最长上升子序列第i位的值


int bs(int *arr, int l, int r, int x){
	if( l == r) return l;
	int mid = (l + r) / 2;
	if(arr[mid] < x) return bs(arr, mid + 1, r, x);
	return bs(arr, l, mid, x);
}

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
		len[i] = 0x3F3F3F3F;  //极大值;
	}
	len[++ans] = a[1];
	for(int i = 2; i <= n; i++) {
			 dp[i] = bs(len, 1, ans + 1, a[i]);
			 len[dp[i]] = a[i];
			ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
*/
