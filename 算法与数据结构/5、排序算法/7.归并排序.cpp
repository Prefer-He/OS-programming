/*************************************************************************
	> File Name: 7.归并排序.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Mon 11 Sep 2023 01:46:56 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "0.sort_test.h"

void merge_sort(int *arr,int l,int r){
    if(r - l<= 1) return ;
    int mid = (r + l)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid,r);
    int p1 = l,p2 = mid,k = 0;
    int *temp = (int *)malloc(sizeof(int) * (r - l));
    while(p1 < mid || p2 < r){
        if(p2 == r || (p1 < mid && arr[p1] <= arr[p2])){
            temp[k++] = arr[p1++];
        } else temp[k++] = arr[p2++];
    }
    for(int i = l;i < r;i++) arr[i] = temp[i - l];
    free(temp);
    return ;
}



int main(){
    int *arr_s = getRandData(SMALL_DATA_N);
    int *arr_b = getRandData(BIG_DATA_N);
    TEST(merge_sort,arr_s,SMALL_DATA_N);
    TEST(merge_sort,arr_b,BIG_DATA_N);
    free(arr_s);
    free(arr_b);
    return 0;
}
