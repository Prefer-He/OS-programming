/*************************************************************************
	> File Name: 1.二分算法.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Wed 13 Sep 2023 07:28:32 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_N 10


//输出形式 ：
void output(int *arr, int n, int ind) {  
    int len = 0;
    for (int i = 0; i < n; i++) {
        len += printf("%4d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (i == ind) printf("\033[32m");
        printf("%4d", arr[i]);
        if (i == ind) printf("\033[0m");
    }
    printf("\n");
    return ;
}


int binary_search(int *arr,int n,int x,int result){
    int head = 0,tail = n - 1,mid; //设置头尾指针
    while(head <= tail && (result == -1)){
        mid = (head + tail) / 2;
        if(arr[mid] == x) result = mid;
        if(arr[mid] < x) head = mid + 1; //未找到时的调整两端指针
        else tail = mid - 1;
    }
    return result;
}



void test_binary_search(int n){
    int *arr = (int *)malloc(sizeof(int) * n);
    arr[0] = rand() % 10;
    for(int i = 1;i < MAX_N;i++) arr[i] = arr[i -1] + rand() % 10; //设置随机数字
    output(arr,n,-1);
    int x;
    while(~scanf("%d",&x)){
        if(x < 0) break; //查找结束后返回条件
        int ind = binary_search(arr,n,x,-1);
        if(ind == -1) {
            printf("error 查找失败 \n请重新输入 ：");
        }
        else output(arr,n,ind);
    }
    free(arr);  //回收空间
    return ;
}


int main(){
    srand(time(0));  //设置随机种子
    test_binary_search(MAX_N);
    return 0;
}
