/***************************************************************
*       &Author: liuqian     
*       &E-mail: *******.com
*       &Motto: dudududu.
*       &File Name: test.c
*       &Created Time: 2020年03月29日 星期日 15时58分54秒
*                      
*       
****************************************************************/
#include "../common/head.h"
#include "../common/common.h"

char ans[50] = {0};
int main() {
	get_value("./a.conf", "SERVERIP");
	printf("%s\n", ans);
	printf("%s\n", get_value("./a.conf", "SERVERIP"));
	
	return 0;


}
