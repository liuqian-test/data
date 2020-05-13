/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 503.cpp
*       &Created Time: 2020年05月13日 星期三 16时51分49秒
*                      
*       
****************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int w, n, num[30005], ans = 0;
	cin >> w >> n;
	for(int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	for(int i = n - 1; i >= 0; i--) {
		if(num[i] == 0) continue;
		ans++;  //船数
		for(int j = i - 1; j >= 0; j--) {
			if(num[i] + num[j] <= w && num[j] != 0) {
				num[j] = 0;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
