/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: 600.cpp
*       &Created Time: 2020年05月20日 星期三 20时32分09秒
*                      
*       
****************************************************************/
#include<iostream>
using namespace std;

int n, m, t, num[3005][3005];

int main() {
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &num[i][j]);
		}
	}

	int x = n, y = 1;
	while(x > 0 && y <= m) {
		if(num[x][y] == t) {
			printf("%d %d\n", x, y);
			return 0;
		}
		if(num[x][y] > t) {
		x--;
	} else {
		y++;
	}
	}
	

	return 0;
}

