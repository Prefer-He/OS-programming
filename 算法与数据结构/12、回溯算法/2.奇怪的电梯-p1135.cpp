/*************************************************************************
	> File Name: 2.奇怪的电梯-p1135.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Thu 23 Nov 2023 07:05:21 PM CST
 ************************************************************************/

#include <stdio.h>

int to[200];
int dis[200] = {0};

void dfs(int k,int a,int n){
    if(dis[a] < k) return ; 
    dis[a] = k;
    if(a + to[a] <= n) dfs(k + 1,a + to[a],n);
    if(a - to[a] >= n) dfs(k + 1,a - to[a],n);
}

int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i = 0;i < n;i++) scanf("%d",to + i); 
    for(int i = 0;i < n;i++) dis[i] = n + 1;
    dfs(0,a,n);
    return 0;
}
