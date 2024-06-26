/*************************************************************************
	> File Name: 1.优先队列.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Mon 17 Jul 2023 06:55:42 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FATHER(i) ((i) / 2)
#define LEFT(i)   ((i) * 2)
#define RIGHT(i)  ((i) * 2 + 1)
#define ROOT 1
#define CMP >
#define swap(a,b) { \
    __typeof(a) __c = (a); \
    (a) = (b); \
    (b) = __c; \
}



typedef struct PriorityQueue{
    int *__data,*data;
    int size,n;
}PriorityQueue;

PriorityQueue *initPQ(int size){
    PriorityQueue *p = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    p->__data = (int *)malloc(sizeof(int)*size);
    p->data = p->__data -ROOT;
    p->size = size;
    p->n = 0;
    return p;
}

int empty(PriorityQueue *p){
    return p->n == 0;
}

int full(PriorityQueue *p){
    return p->n == p->size;
}

int top(PriorityQueue *p){
    return p->data[ROOT];
}

void up_update(int *data,int i){
    while(i > ROOT && data[i] CMP data[FATHER(i)]){
    swap(data[i],data[FATHER(i)]);
        i = FATHER(i);
    }
    return ;       
}

void down_update(int *data,int i,int n){
    while(LEFT(i) <= n){
        int ind= i ,l = LEFT(i),r = RIGHT(i);
        if(data[l] CMP data[ind]) ind = l;
        if(r <= n && data[r] CMP data[ind]) ind = r;
        if(ind = i) break;
        swap(data[i],data[ind]);
        i = ind;
    }
    return ;
}


int push(PriorityQueue *p,int x){
    if(full(p)) return 0;
    p->n +=1;
    p->data[p->n] = x;
    up_update(p->data,p->n);
    return 1;
}

int pop(PriorityQueue *p){
    if(empty(p)) return 0;
    p->data[ROOT] = p->data[p->n];
    p->n -=1;
    down_update(p->data,ROOT,p->n);
    return 1;
}


void clearPQ(PriorityQueue *p){
    if( p == NULL ) return ;
    free(p->__data);
    free(p);
    return ;
}

void output(PriorityQueue *p){
    printf("PQ(%d) :  ",p->n);
    for(int i =1;i<=p->n;i++){
        printf("%d",p->data[i]);
    }
    printf("\n");
    return ;
}


int main() {
    int op,x;
    #define MAX_OP 100
    PriorityQueue *p = initPQ(MAX_OP);
    while(~scanf("%d",&op)) {
        if(op == 1){
            scanf("%d",&x);
            printf("insert %d to priority_queue : \n",x);
            push(p,x);
            output(p);
        }else {
            printf("top :  %d ",top(p));
            pop(p);
            output(p);
        }
    }
    clearPQ(p);
    return 0;
}
