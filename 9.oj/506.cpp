/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 506.cpp
*       &Created Time: 2020年05月13日 星期三 18时03分14秒
*                      
*       
****************************************************************/
#include<iostream>
#include <algorithm>
using namespace std;

//带着编号排序

struct node{
	int num, time;
};

int n;
node s[35];

bool cmp(node a, node b) {
	return a.time < b.time;
}
	
int main() {
	cin >> n ;
	for(int i = 0; i < n; i++) {
		cin >> s[i].time;
		s[i].num = i + 1;
	}
	 sort(s, s+ n, cmp);
	int ans = 0, now = 0;
	 for(int i = 0; i < n; i++) {
		
		if(i) cout << " ";
		cout << s[i].num;
		 ans+= now;
		 now += s[i].time;
	 }
		
	 printf("\n%.2f\n", (double)ans / n);
	return 0;
}

