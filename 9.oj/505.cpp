/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 505.cpp
*       &Created Time: 2020年05月13日 星期三 17时46分02秒
*                      
*       
****************************************************************/
#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	int n;
	string num[100005];
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n, cmp);
	
	for(int i = 0; i < n; i++) {
		cout << num[i];
	}
	return 0;
}
