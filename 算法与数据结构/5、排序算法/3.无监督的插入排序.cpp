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

void unguarded_insert_sort(int *arr,int l,int r){
    int ind = l;
    for(int i = l + 1;i < r;i++) {
        if(arr[ind] > arr[i]) ind = i;
    }
    
    while(ind > l){
        swap(arr[ind],arr[ind - 1]);
        ind -= 1;
    }

    for(int i = l + 1;i < r;i++){
        int j = i;
        while(arr[j] < arr[j - 1]){ 
            swap(arr[j],arr[j - 1]);
            j -= 1;
        }
    }
    return ;
}




int main(){
    int *arr = getRandData(SMALL_DATA_N);
    TEST(insert_sort,arr,SMALL_DATA_N);
    TEST(unguarded_insert_sort,arr,SMALL_DATA_N);
    free(arr);
    return 0;
}

