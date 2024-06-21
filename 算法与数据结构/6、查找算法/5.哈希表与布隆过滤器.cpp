/*************************************************************************
	> File Name: 5.哈希表与布隆过滤器.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sat 21 Oct 2023 04:21:22 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a,b){\
    __typeof(a) __c = a;\
    a = b,b = __c;\
}

typedef struct Node{
    char *s;
    struct Node *next;
}Node;

typedef struct HashTable{
    Node *data;
    int cnt,size;
}HashTable; 

void expand(HashTable *h);
void clearHashTable(HashTable *h);

Node *getNewNode(const char *s){
    Node *p = (Node *)malloc(sizeof(Node));
    p->s = strdup(s);
    p->next = NULL;
    return p;
}

HashTable *getNewHashTable(int n){
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (Node *)malloc(sizeof(Node));
    h->size = n;
    h->cnt  = 0;
    return h;
}

void clearNode(Node *p){
    if(p == NULL) return ;
    if(p->s) free(p->s);
    free(p);
    return ;
}

void freeHashTable(HashTable *h){
    if(h == NULL) return ;
    for(int i = 0;i < h->size;i++){
        Node *p = h->data[i].next,*q;
        while(p){
            q = p->next;
            clearNode(p);
            p = q;
        }
    }
    free(h->data);
    free(h);
    return ;
}

int hash_func(const char *s){
    int seed = 131,h = 0;
    for(int i = 0;s[i];i++){
        h = h * seed + s[i];
    }
    return h & 0x7fffffff;
}

bool find(HashTable *h,const char *s){
    int hcode = hash_func(s),ind = hcode % h->size;
    Node *p = h->data[ind].next;
    while(p){
        if(strcmp(p->s,s) == 0) return true;
        p = p->next;
    }
    return false;
}

bool insert(HashTable *h,const char *s){
    if(h->cnt >= h->size * 2){
        expand(h);
    }
    int hcode = hash_func(s),ind = hcode % h->size;
    Node *p = getNewNode(s);
    p->next = h->data[ind].next;
    h->data[ind].next = p;
    h->cnt += 1;
    return true;
}

void swapHashTable(HashTable *h1,HashTable *h2){
    swap(h1->data,h2->data);
    swap(h1->cnt, h2->cnt);
    swap(h1->size, h2->size);
}

void expand(HashTable *h){
    HashTable *new_h = getNewHashTable(h->size * 2);
    for(int i = 0;i < h->size;i++){
        Node *p = h->data[i].next;
        while(p){
            insert(new_h,p->s);
            p = p->next;
        }
    }
    swapHashTable(h,new_h);
    clearHashTable(new_h); 
    return ;
}

int main(){
    srand(time(0));    


    return 0;
}
