/*************************************************************************
	> File Name: 7.程序调用关系.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 07 Jul 2023 10:08:29 PM CST
 ************************************************************************/
using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int flag = 0,n;
    cin >> n;
    vector<string> ops(n),s;
    string target;
    for(int i=0;i<n;i++) {
        cin >> target;
        if(target ==ops[i]){
            s.push_back(ops[i]);
            break;
        }
        if(ops[i]=='return')s.pop_back();
        else s.push_back(ops[i]);
    }
    if(flag){
        for(int i=0;i<s.size();i++){
            if(i)cout<<"->"
        }
    printf("%d",s[i]);
    } else {
        printf("NOT REFERENCED");
    }
    return 0;
}

