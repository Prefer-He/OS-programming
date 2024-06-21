/*************************************************************************
	> File Name: 4.拓朴排序.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Tue 16 Apr 2024 04:47:19 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 2000

vector<int> indeg(MAX_N + 5); //入读数
vector<vector<int>> g(MAX_N + 5);



int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0,a,b;i < m;i++){
        cin >> a >> b;
        indeg[b] += 1;
        g[a].push_back(b);     
    }
    for(int i = 0;i <= n;i++){
        



    }

    return 0;
}
