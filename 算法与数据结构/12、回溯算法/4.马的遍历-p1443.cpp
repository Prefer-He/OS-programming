/*************************************************************************
	> File Name: 4.马的遍历-p1443.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 24 Nov 2023 10:46:26 AM CST
 ************************************************************************/

#include <stdio.h>
#define MAX_N 400

int dis[MAX_N + 5][MAX_N + 5];
int dir[8][2] = {
    {2,1},{-2,1},{2,-1},{-2,-1},
    {1,2},{1,-2},{-1,2},{-1,-2}
}

void dfs(int step,int x,int y){
    if(dis[x][y] != -1 && dis[x][y] <= step){
        return ;
    }
    dis[x][y] = step;
    for(int i = 0;i < 8;i++){
        dx = x + dir[i][0];
        dy = y + dir[i][1];
        if(dx < 1 || dx > n) continue;
        if(dy < 1 || dy > m) continue;
        dfs(step + 1,dx,dy);
    } 
}

int main(){
    int n,m,x,y; 
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < m;j++){
            dis[i][j] = -1;
        }
    } 
    dfs(0,x,y);
    return 0;
}
