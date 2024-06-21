/*************************************************************************
	> File Name: 4.希尔排序.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Thu 31 Aug 2023 05:50:04 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "0.sort_test.h"

//设计一个步长序列
//按照步长，对序列进行分组，每组采用插入排序
//直到执行步长为 1 为止

void unguarded_insert_sort(int *arr,int l,int r,int step){
    int ind = l;
    for(int i = l + step;i < r;i += step) {
        if(arr[ind] > arr[i]) ind = i;
    }
    
    while(ind > l){
        swap(arr[ind],arr[ind - step]);
        ind -= step;
    }

    for(int i = l + step;i < r;i+= step){
        int j = i;
        while(arr[j] < arr[j - step]){ 
            swap(arr[j],arr[j - step]);
            j -= step;
        }
    }
    return ;
}

void shell_sort(int *arr,int l,int r){
    int k = 2,n = (l - r),step;
    do{
        step = n / k == 0 ? 1 : n / k;
        for(int i = l,I = (l + step);i < I;i++){
            unguarded_insert_sort(arr,l,r,step); 
        }
    }while(step != 1);
    return ;
}





int main(){
    int *arr = getRandData(SMALL_DATA_N);  
    TEST(shell_sort,arr,SMALL_DATA_N);
    free(arr);
    return 0;
}

