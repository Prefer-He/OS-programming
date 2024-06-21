/*************************************************************************
	> File Name: 11.火车进站-HZOJ-263.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Tue 10 Oct 2023 06:53:26 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool is_Valid(int a[],int n){
    stack<int> s;
    int x = 1; //当前可以入栈的最小元素的值
    for(int i = 0;i < n;i++){
        if(s.empty() || s.top() < a[i]){
            while(x < a[i]) s.push(x),x += 1;
        }
        if(s.empty() || s.top() != a[i]) return false;
        s.pop();
    }
    return true;
}



int main(){
    int n,a[25],cnt = 20;
    cin >> n;
    for(int i = 0;i < n;i++) a[i] = i + 1;
    do{
        if(is_Valid(a,n)){
            for(int i = 0;i < n;i++) cout << a[i] ;
        }
        cout  << endl;
        cnt--;
    }while(next_permutation(a,a +n) && cnt);
    return 0;
}
