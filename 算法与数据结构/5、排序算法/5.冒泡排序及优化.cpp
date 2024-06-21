/*************************************************************************
	> File Name: 5.冒泡排序及优化.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Wed 06 Sep 2023 08:25:29 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "0.sort_test.h"

//1、将数组分为已排序区和待排序区
//2、从头到尾扫描待排序区，若前面的元素比后面的元素大，就交换位置
//3、每一轮都会将待排序区中最大的元素放到已排序区的末尾
//4、直到待排序区没有元素为止

void bubble_sort(int *arr,int l,int r){
    for(int i = r - 1,I = l + 1;i >= I;i--){
        for(int j = l;j < i;j++ ){
            if(arr[j] > arr[j + 1]) swap(arr[j],arr[j + 1]);
        }
    }
    return ; 
}

void bubble_sort_supper(int *arr,int l,int r){
    for(int i = r - 1,I = l + 1,ind;i >= I;i--){
        ind = 0;
        for(int j = l;j < i;j++ ){
            if(arr[j] <= arr[j + 1]) continue;
            swap(arr[j],arr[j + 1]);
            ind += 1;
        }
        if(ind == 0) break;
    }
    return ; 
}

int main(){
    int *arr = getRandData(SMALL_DATA_N);    
    TEST(bubble_sort,arr,SMALL_DATA_N);
    TEST(bubble_sort_supper,arr,SMALL_DATA_N);
    free(arr);
    return 0;
}

