/*************************************************************************
	> File Name: 2.中序遍历转非递归.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sat 03 Feb 2024 04:18:57 PM CST
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#include <malloc.h>
#include <time.h> 
#include <stack>
#include <stdlib.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
}Node;

Node *init_binary(int key){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root,int key){
    if(root == NULL) return init_binary(key);
    if(rand() % 2) root->lchild = insert(root->lchild,key); 
    else root->rchild = insert(root->rchild,key);
    return root;
}


void clear_binary(Node *root){
   if(root == NULL) return ; 
    free(root->lchild);
    free(root->rchild);
    free(root);
    return ;
}


void pre_order(Node *root){
    if(root == NULL) return ;
    printf("%d ",root->data);
    pre_order(root->lchild);
    pre_order(root->rchild);
    return ;
}

void in_order(Node *root){
    if(root == NULL) return ;
    in_order(root->lchild); 
    printf("%d ",root->data);
    in_order(root->rchild);
    return ;
}

struct Data{
    Data(Node *root) : root(root){};
    Node *root;
    int code;
};

void non_in_order(Node *root){
    stack<Data> s;
    Data d(root);
    s.push(d);
    while(!s.empty()){
        Data &cur = s.top();
        switch(cur.code){
        case 0:{
            if(cur.root == NULL){
                s.pop();
            }else{
                cur.code = 1;
            }
        };
        case 1:{
            Data d(cur.root->lchild);
            cur.code = 2;
            s.push(d);
        };
        case 2:{
            printf("%d ",cur.root->data);
            cur.code = 3;
        };
        case 3:{
            Data d(cur.root->rchild);
            cur.code = 4;
            s.push(d);
        };
        case 4:{
            s.pop();
            };
        }
    }
    return ;
}

void post_order(Node *root){
    if(root == NULL) return ;
    post_order(root->lchild); 
    post_order(root->rchild); 
    printf("%d ",root->data);
    return ;
}


int main(){
    srand(time(0)); 
    Node *root = NULL;
    #define MAX_NODE 10
    for(int i=0;i<MAX_NODE;i++){
        root = insert(root,rand() % 100);
    }
    pre_order(root);   printf("\n");
    in_order(root);    printf("\n");
    post_order(root); printf("\n");
    clear_binary(root);
  return 0;
}

