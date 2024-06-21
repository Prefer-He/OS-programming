/*************************************************************************
	> File Name: 1.顺序表1.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Mon 04 Sep 2023 07:44:31 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_N 20


//结构定义
typedef struct vector{
    int *data;
    int size,count;
}vector;
//初始化
vector *init_vector(int n){
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
}

int expand(vector *v){
    if(v == NULL) return 0;
    printf("expand v from %d to %d\n",v->size,v->size * 2);
    int *p = (int *)realloc(v->data,sizeof(int) * v->size * 2);
    if(p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    return 1;
}


int insert_vector(vector *v,int pos,int val){
    if(pos < 0 || pos > v->count) return 0; //边界条件
    for(int i =v->count -1;i >= pos;i--){ //逆序遍历，将带插入位置后面元素向后挪一位
        v->data[i + 1] = v->data[i];
    }
    v->count -=1;  //对结构体成员做修改
    v->data[pos] = val;
    return 1;
}

int erase_vector(vector *v,int pos){ //道理和过程跟插入没区别
    if(pos < 0 || pos > v->count) return 0;
    for(int i = pos + 1;i < v->count;i++){
        v->data[i - 1] = v->data[i];
    }
    v->count -=1;
    return 1;
}

void clear_vector(vector *v){
    if(v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}





int main(){
    srand(time(0));
    vector *v = init_vector(MAX_N);
    for(int i= 0;i < MAX_N;i++){
        int ind = rand() % 4,pos,val,ret;
        switch(ind){
            case 0:
            case 1:
            case 2:
                pos = rand() % (v->count + 2);
                val = rand() % 100;
                ret = insert_vector(v, pos, val);
                printf("insert %d at %d to vector = %d\n", 
                    val, pos, ret);
                break;
            case 3:
                pos = rand() % (v->count + 2);
                ret = erase_vector(v, pos);
                printf("erase item at %d in vector = %d\n", 
                    pos, ret);
                break;
        }
        output(v);
    }
    clear_vector(v);
    return 0;
}
