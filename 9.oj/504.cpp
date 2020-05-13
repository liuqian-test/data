/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 504.cpp
*       &Created Time: 2020年05月13日 星期三 17时20分16秒
*                      
*       
****************************************************************/
#include<iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string str;
	cin >> str >> n;
	for(int i = 1; i <= n; i++) {
		int index = str.size() - 1;
		for(int j = 0; j < str.size() - 1; j++) {
			if(str[j] > str[j + 1]) {
				index = j;
				break;
			}
		}
		str.replace(index, 1, "");
	}
	
	int flag = 0;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] != '0')flag = 1;
		if(flag == 1) cout << str[i];
	}
	return 0;
}

