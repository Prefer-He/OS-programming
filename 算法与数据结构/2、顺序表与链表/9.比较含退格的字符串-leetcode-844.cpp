/*************************************************************************
	> File Name: 9.比较含退格的字符串-leetcode-844.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Tue 10 Oct 2023 05:09:45 PM CST
 ************************************************************************/
#include <iostream>
#include <stack>
using namespace std;

void pushStack(string &s,stack<char> &t){
    for(int i = 0;s[i];i++){
        if(s[i] == '#') t.pop();
        else t.push(s[i]);
    }   
    return ;
}

bool test(string &s,string &t,stack<char> &s1,stack<char> &t1){
    pushStack(s,s1);
    pushStack(t,t1);
    if(s1.size() != t1.size()) return false;
    while(!s1.empty()){
        if(s1.top() != t1.top()) return false; 
        s1.pop(),t1.pop();
    }
    return true;
}

int main(){
    string s,t; 
    cin >> s >> t;
    stack<char> s1,t1;
    if(test(s,t,s1,t1)){
        cout << "数组一致 :" << s << "\t" << t << endl;
    }else {
        cout << "数组不一致" << endl;
    }
    return 0;
}
