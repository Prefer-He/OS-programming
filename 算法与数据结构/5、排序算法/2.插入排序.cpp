/*************************************************************************
	> File Name: 2.插入排序.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sat 05 Aug 2023 03:54:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "0.sort_test.h"


//1、将数组分为已排序区和待排序区
//2、将已排序区后面一个元素插入到已排序去中去
//3、直到待排序区没有元素

void insert_sort(int *arr,int l,int r){ //从 l 到 r 为待排序区范围 l是已排序区的最后一个元素
    for(int i = l + 1;i < r;i++){
        int j = i;
        while(j > l && arr[j] < arr[j - 1]){ 
            swap(arr[j],arr[j - 1]);
            j -= 1;
        }
    }
    return ;
}



int main(){
    int *arr = getRandData(SMALL_DATA_N);
    TEST(insert_sort,arr,SMALL_DATA_N);
    free(arr);
    return 0;
}
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
