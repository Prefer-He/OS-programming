/*************************************************************************
	> File Name: 12.验证栈序列-leetcode-946.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sun 15 Oct 2023 03:26:01 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool is_valid(vector<int> &a, vector<int> &b) {
    int x = 0, n = a.size();
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (s.empty() || s.top() != b[i]) {
            while (x < n && a[x] != b[i]) {
                s.push(a[x]);
                x += 1;
            }
            if (x == n) return false;
            s.push(a[x]), x += 1;
        }
        s.pop();
    }
    return true;
}

int main() {
    vector<int> a, b;
    for (int i = 1; i <= 5; i++) a.push_back(i);
    for (int i = 5; i >= 0; i--) b.push_back(i);
    if (is_valid(a, b)) cout << "yes" << a[1] << endl;
    else cout << "no" << endl;
    return 0;
}

