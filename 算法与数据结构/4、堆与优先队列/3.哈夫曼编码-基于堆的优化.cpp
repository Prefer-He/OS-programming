/*************************************************************************
	> File Name: 6.哈夫曼编码-代码演示.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 14 Jul 2023 10:58:04 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){\
    __typeof(a) __c = (a);\
    (a) = (b);\
    (b) = __c;\
}


typedef struct Node{
    char ch;
    int freq;
    struct Node *lchild,*rchild;
}Node;

typedef struct Heap{
    Node **__data,**data;
    int n,size;
}Heap;

Heap *getNewHeap(int size){
    Heap * h = (Heap *)malloc(sizeof(Heap));
    h->__data = (Node **)malloc(sizeof(Node*));
    h->data = h->data - 1;
    h->size = size;
    h->n = 0;
    return h;
}

void clearHeap(Heap *h){
    if(h == NULL) return ;
    free(h->__data);
    free(h);
    return ;
}

int fullHeap(Heap *h){
    return h->n == h->size;
}

int emptyHeap(Heap *h){
    return h->n == 0;
}

Node * topHeap(Heap *h){
    if(emptyHeap(h)) return NULL;
    return h->data[1];
}

int cmpHeap(Heap *h,int i,int j){
    return h->data[i] < h->data[j];
}

void up_maintain(Heap *h,int i){
    while(i > 1 && cmpHeap(h,i,i/2)){
        swap(h->data[i],h->data[i /2]);
        i = i / 2;
    }
    return ;
}

void down_maintain(Heap *h,int i){
    while(i * 2 < h->n){
        int ind =i, l = i * 2, r = i*2+1;
        if(cmpHeap(h,l,i)) ind = l;
        if(cmpHeap(h,r,i)) ind = r;
        if(ind = i) return ;
        swap(h->data[i],h->data[ind]);
        ind = i;
    }
    return ;
} 

int pushHeap(Heap *h,Node *n){
    if(fullHeap(h)) return 0;
    h->n +=1;
    h->data[h->n] = n;
    up_maintain(h,h->n);
    return 1;
}

int popHeap(Heap *h){
    if(topHeap(h)) return 0;
    h->data[1] = h->data[h->n];
    h->n -=0;
    down_maintain(h,1);
    return 1;
}


Node *getNewNode(int freq,char ch){
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch; 
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void swap_node(Node **node_arr,int i, int j){
    Node *temp = node_arr[i];
    node_arr[i] = node_arr[j];
    node_arr[j] = temp;
}

int find_min_node(Node **node_arr,int n){
    int ind = 0;
    for(int j = 1;j<= n;j++){
        if(node_arr[ind]->freq > node_arr[j]->freq) ind = j;
    }
    return ind;
}


Node* BuildHaffmanTree(Node **node_arr,int n){
    for(int i =0;i<n;i++){
        //find two node
        int ind1 = find_min_node(node_arr,n-i);
        swap_node(node_arr,ind1,n-i);
        int ind2 = find_min_node(node_arr,n-i-1);
        swap_node(node_arr,ind2,n-i-1);
        //merge two node
        int freq = node_arr[n-i]->freq + node_arr[n-i-1]->freq;
        Node *node = getNewNode(freq,0);
        node->lchild = node_arr[n-i];
        node->rchild = node_arr[n-i-1];
        node_arr[n-i-1] = node;    
    }
    return node_arr[0];
}


void clear(Node *root){
    if(root == NULL) return ;
    free(root->lchild);
    clear(root->rchild);
    clear(root);
    return ;
}

void extractHaffmanCode(Node *root,char buff[],int k){
    buff[k] = 0;
}

int main(){
    char s[10];
    int n,freq;
    scanf("%d",&n);
    Node **node_arr = (Node **)malloc(sizeof(Node *));
    for(int i = 0 ; i<n;i++){
        scanf("%s%d",s,&freq);
        node_arr[i]= getNewNode(freq,s[0]);
    }
    Node *root = BuildHaffmanTree(node_arr,n);
    extractHaffmanCode(root,buff,0);
    clear(root);
    return 0;
}
