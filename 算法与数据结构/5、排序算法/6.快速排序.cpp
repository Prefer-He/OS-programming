/*************************************************************************
	> File Name: 6.快速排序.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Wed 06 Sep 2023 08:57:21 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "0.sort_test.h"

void quick_sort(int *arr,int l,int r){
    if(r - l <= 2 ){
        if(r - l <= 1) return ;
        if(arr[l] > arr[l + 1]) swap(arr[l],arr[r]);
        return ;
    }
    //partition
    int x = l,y = r - 1,ind = arr[l];
    while(x < y){
        while(x < y && ind < arr[y]) --y;
        if(x < y) arr[x++] = arr[y];
        while(x < y && arr[x] <= ind) ++x;
        if(x < y) arr[y--] = arr[x];
    }
    arr[x] = ind;
    quick_sort(arr,l,x);
    quick_sort(arr,x + 1,r);
    return ;
}



int main(){
    int *arr_s = getRandData(SMALL_DATA_N); 
    int *arr_b = getRandData(BIG_DATA_N);
    TEST(quick_sort,arr_s,SMALL_DATA_N);
    TEST(quick_sort,arr_b,BIG_DATA_N);
    free(arr_s);
    free(arr_b);
    return 0;
}
