/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: unorderd_map.cpp
*       &Created Time: 2020年05月16日 星期六 19时33分01秒
*                      
*       
****************************************************************/
#include<iostream>
#include  <unordered_map>
using namespace std;

int main() {
	//底层使用哈希表 map , set
	
	unordered_map<double, int> h;
	h[2.3] = 123;
	h[345.6] = 1234;
	cout << h[2.3] << endl;
	return 0;
	
}
