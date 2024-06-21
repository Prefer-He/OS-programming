/*************************************************************************
	> File Name: 4.跳跃表.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sat 07 Oct 2023 04:36:20 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#define min(a,b) ((a) < (b) ? (a) : (b));

typedef struct Node{
    int key,level;
    struct Node *next,*down,*up; 
}Node;

typedef struct Skiplist{
    Node *head,*tail;
    int max_level;
}Skiplist;

#define MAX_level 32;

Node *getNewNode(int key,int n){
    Node *nodes = (Node *)malloc(sizeof(Node) * n);
    for(int i = 0;i < n;i++){
        nodes[i].next  = NULL;
        nodes[i].level = i;
        nodes[i].down  = (i ? nodes + (i - 1) : NULL);  //29、30行防止指针越界
        nodes[i].up    = (i + 1 < n ? NULL : nodes + (i + 1));  
    }
    return nodes + n - 1; //n - 1代表指针偏移量，返回值是最上层节点
}

Skiplist *getNewSkiplist(int n){
    Skiplist *s = (Skiplist *)malloc(sizeof(Skiplist));
    s->head = getNewNode(INT32_MIN,n);
    s->tail = getNewNode(INT32_MAX,n);
    s->max_level = n;
    Node *p = s->head,*q = s->tail;
    while(p){
        p->next = q;
        p = p->down;
        q = q->down;
    }
    return s;
}

Node *find(Skiplist *s,int x){
    Node *p = s->head;
    while(p && p->key != x){
        if(p->next->key <= x)p = p->next;
        else p = p->down;
    }
    return p;
}

int randDouble(){
    #define MAX_RAND_N 1000000
    return (rand() % MAX_RAND_N * 1.0 / MAX_RAND_N);
    #undef MAX_RAND_N
}

int randlevel(Skiplist *s){
    int level = 1;
    double p = 1.0 / 2.0;
    if(randDouble() < p) level += 1;
    return min(s->max_level,level);
}

void insert(Skiplist *s,int x){
    int level = randlevel(s);
    Node *node = getNewNode(x,level);


}


void clearNode(Node *p){
    if(p == NULL) return ;
    free(p);
    return ;
}


void clearSkiplist(Skiplist *s){
    Node *p = s->head,*q;
    while(p->level != 0) p = p->down;
    while(p){
        q = p->next;
        clearNode(p);
        p = q;
    }
    free(s);
    return ;
}




int main(){
    srand(time(0));


    return 0;
}

