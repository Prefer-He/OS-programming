/*************************************************************************
	> File Name: 2.递归法练习整数划分.c
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sat 23 Sep 2023 10:30:43 AM CST
 ************************************************************************/
#include <stdio.h>

void partition(int n, int ind, int x) {
    if (n == 0)  // 边界条件 ：如果向下拆解不了，就代表本轮结束
    printf("\n");
    else for (int i = ind; i >= 1; i--) {
            if (i <= n) {
                printf("%d",i);
                partition(n - i, i, x + 1); //递归调用
        }
    }
}

int main() {
    int n;
    printf("请输入：");
    scanf("%d", &n);
    partition(n, n, 0); // 传入三个参数 ：最大可拆分数、最大可用数、拆分深度 
    return 0;
}

