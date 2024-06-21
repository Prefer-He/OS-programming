/*************************************************************************
	> File Name: 8.基数排序.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Mon 11 Sep 2023 01:47:16 PM CST
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "0.sort_test.h" 

void radix_sort(int *arr,int l,int r){
    #define k 65536
    int *cnt  = (int *)malloc(sizeof(int) * k);
    int *temp = (int *)malloc(sizeof(int) * (r - l));
    // round 1
    memset(cnt,0,sizeof(int) * k);
    for(int i = l;i < r;i++) cnt[arr[i] % k] += 1;
    for(int i = 1;i < k;i++) cnt[i] += cnt[i - 1];
    for(int i = r - 1;i >= l;i--) temp[--cnt[arr[i] % k]] = arr[i];
    memcpy(arr + l,temp,sizeof(int) * (r - l));
    // round 2
    memset(cnt,0,sizeof(int) * k);
    for(int i = l;i < r;i++) cnt[arr[i] / k] += 1;
    for(int i = 1;i < k;i++) cnt[i] += cnt[i - 1];
    for(int i = r - 1;i >= l;i--) temp[--cnt[arr[i] / k]] = arr[i];
    memcpy(arr + l,temp,sizeof(int) * (r - l));
    return ;
}
int main(){
    int *arr_s = getRandData(SMALL_DATA_N);
    int *arr_b = getRandData(BIG_DATA_N);
    TEST(radix_sort,arr_s,SMALL_DATA_N);
    TEST(radix_sort,arr_b,BIG_DATA_N);
    free(arr_s);
    free(arr_b);   

    return 0;
}
