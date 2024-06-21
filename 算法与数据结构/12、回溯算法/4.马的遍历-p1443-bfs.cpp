/*************************************************************************
	> File Name: 4.马的遍历-p1443-bfs.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 24 Nov 2023 02:30:31 PM CST
 ************************************************************************/
#include <stdio.h>
#define MAX_N 400
int dis[MAX_N + 5][MAX_N + 5];


int main(){
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            dis[i][j] = -1;
        }
    }


    return 0;
}
