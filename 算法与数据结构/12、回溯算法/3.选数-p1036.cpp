/*************************************************************************
	> File Name: 3.选数-p1036.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 24 Nov 2023 10:29:23 AM CST
 ************************************************************************/

#include <stdio.h>
#define MAX_N 200

int val[MAX_N + 5];
long long sum = 0;
int ans = 0;

bool isprime(int n){
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

void dfs(int k,int ind,int n,int m,int sum){
    if(k == m) {
        if(isprime(sum)) ans += 1;
        return ;
    }
    for(int i = 1;i <= n;i++){
        dfs(k + 1,i + 1,n,m,sum + val[i]);
    }
}


int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) scanf("%d",val + i);
    dfs(0,1,n,k,sum);
    printf("%d\n",ans);
    return 0;
}
