/*************************************************************************
	> File Name: 2.兔子繁殖.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sun 08 Oct 2023 06:59:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100


int arr[MAX_N + 5] = {0};

int f(int n){
    if(n <= 2) return n;
    return f(n - 1) + f(n - 2);
}

int f_v1(int n){
    if(n <= 2) return n;
    if(arr[n]) return arr[n];
    arr[n] = f(n - 1) + f(n - 2);
    return arr[n];
}

int f_v2(int n){
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3;i < n;i++) arr[i] = arr[i - 1] + arr[i - 2];
    return arr[n];
}

int main(){
    int n;
    cin >> n;
    cout << f_v1(n) << endl;
    cout << f_v2(n) << endl;
    return 0;
}
