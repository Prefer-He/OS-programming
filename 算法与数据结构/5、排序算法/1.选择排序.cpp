/*************************************************************************
	> File Name: 1.选择排序.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sun 30 Jul 2023 02:26:46 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "0.sort_test.h"

//1、将数组分为已排序区和待排序区
//2、每一轮从待排序区选择一个最小值放到已排序区的尾部
//3、直到待排序区没有元素为止
//时间复杂度：n*n

void selection_sort(int *arr, int l, int r) { //待排序区间范围从 l 到 r
    for (int i = l, I = r - 1; i < I; i++) {
        int ind = i;
        for (int j = i + 1; j < r; j++) {
            if (arr[j] < arr[ind]) ind = j;
        }
        swap(arr[i], arr[ind]);
    }
    return ;
}

int main() {
    int *arr = getRandData(SMALL_DATA_N);
    TEST(selection_sort, arr, SMALL_DATA_N);
    free(arr);
    return 0;
}
