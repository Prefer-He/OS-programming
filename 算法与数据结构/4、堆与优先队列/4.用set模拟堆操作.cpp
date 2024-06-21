/*************************************************************************
	> File Name: 4.用set模拟堆操作.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Thu 27 Jul 2023 09:41:43 PM CST
 ************************************************************************/

#include<iostream>
#include <set>
using namespace std;

void test1(){
    cout << "set base usage" << endl;
    set<int> s;
    s.insert(3);
    s.insert(4);
    s.insert(5);
    cout << s.size() << endl;
    return ;
}

void test2(){
    cout << "set replace  heap :" << endl;
    typedef pair<int,int> PII;
    set<PII> s;
    int tot = 0;
    for(int i = 0;i < 4;i++){
        s.insert(PII(rand() % 20,tot++));
        cout << s.begin()->first << endl;
        s.erase(s.begin());
    }
    for(auto x : s){
        cout << x.first <<endl; 
    }
    return ;
}


int main(){
    test1();
    test2();

    return 0;
}
