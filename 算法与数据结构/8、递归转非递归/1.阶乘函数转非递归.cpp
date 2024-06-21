/*************************************************************************
	> File Name: 1.阶乘函数转非递归.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Thu 01 Feb 2024 04:10:39 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

int f(int n){
    if(n == 1) return 1;
    return n * f(n- 1);
}

struct Data{
    Data(int n,int *pre_ret) : n(n),pre_ret(pre_ret){
        int code = 0;
    }
    int n;
    int code,ret,*pre_ret;
};

int non_f(int n){
    stack<Data> s;
    int ans;
    Data d(n,&ans); 
    s.push(d);
    while(!s.empty()){
        Data cur = s.top(); 
        switch(cur.code){
            case 0:{
                if(cur.n == 1){
                   *(cur.pre_ret) = 1;
                    s.pop();
                }else{
                    cur.code = 1;
                }
            }break;
            case 1:{
                Data d(cur.n - 1,&(cur.ret));
                cur.code = 2;
                s.push(d);
            }break;
            case 2:{
                *(cur.pre_ret) = cur.ret * cur.n;
                s.pop();
            }
        }
    }
    return ans;
}


int main(){
    int n;
    while(cin >> n){
        cout << f(n) << endl;
        cout << non_f(n) << endl;
    }
    return 0;
}
