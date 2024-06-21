/*************************************************************************
	> File Name: 4.队列-链表实现.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 07 Jul 2023 02:49:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int data;
    Node *next;
}Node;

typedef struct LinkList{
    Node head,*tail;
}LinkList;

LinkList *initLinkList(){
    LinkList *l=(LinkList *)malloc(sizeof(LinkList));
    l->head.next=NULL;
    l->tail=&(l->head);
    return l;
}

void clearLinkList(LinkList *l){
    Node *p=l->head.next,*q;
    while(p){
        q=p->next;
        free(p);
        p=q
    }
}

int frontLinkList(linklist){
    if(emptyList(l))return 0;
    return l->head.next->data;
}

emptyList(LiskList *l){
    return l->head.next==NULL; 
}

int insertTail(LinklIst *l,int val){
    Node *node = getNewNode(val);
    l->tail->next = node;
    l->tail = node;
    return 1;
}

Node *getNewNode(int val){
     Node *q = (Node *)malloc(sizeof(Node));
     p->data=val;
     p->next = NULL;
     return p;
}

int erasehead(LinkList *l){
    if(emptyList(l))return 0;
    Node *p = l->head.next;
    l->head.next=l->head.next->next;
     if(p==l->tail) l->tail = %(l->head);
     free(p);
     return 1;
}

typedef struct Queue{
   LinkList *l;
   int count;
}Queue;

Queue *init_Queue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->l=initLinkList();
    q->count=0;
    return q;
}
int empty(Queue *q){
    return q->count==0;
}

int push(Queue *q,int val){
    insertTail(q->l,val);
    return 1;    
}


int pop(Queue *q){
    erasehead(q->l);
    return 1;


}



int front(Queue *q){
    if(empty(q))return 0;
    return frontLinkList(q->data)
}





Queue clearQueue(Queue *q){
    if(q==NULL)return;
    clearLinkList(q->l);
    free(q);
    return ;
}



















int main(){







    return 0;
}













