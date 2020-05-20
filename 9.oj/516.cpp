/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 516.cpp
*       &Created Time: 2020年05月20日 星期三 20时32分31秒
*                      
*       
****************************************************************/
#include<iostream>
using namespace std;

string str;
long long n, ans, numc[100005], numw[100005], nc, nw;


int main() {
	cin  >> n >> str;
	//n = str.size();
	for(int i = 0; i < n; i++) {
		if(str[i] == 'C') nc++;
		numc[i] = nc;
	}
	for(int i = n - 1; i >= 0; i--) {
		if(str[i] == 'W') nw++;
		numw[i] = nw;
	}

	for(int i = 0; i < n; i++) {
		if(str[i] == 'O') {
			ans += numc[i] + numw[i];
		}
	}
	cout << ans << endl;
	return 0;
}
