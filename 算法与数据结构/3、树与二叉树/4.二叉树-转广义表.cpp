/*************************************************************************
	> File Name: 4.二叉树-广义表与二叉树的相互转化.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 14 Jul 2023 05:25:00 PM CST
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define KEY(n) (n ? n->data : -1)

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


Node *getRandemBinarytree(int n){
    Node *root = NULL;
    for(int i = 0;i<n;i++){
    root = insert(root,rand()%100);
    }
    return root; 
}    
    



void clear(Node *root){
    if(root == NULL) return ;    
    free(root->lchild);
    free(root->rchild);
    free(root);
    return ;
}

char buff[1000];
int len;

void __serialize(Node *root){
    if(root == NULL) return ;
    len +=sprintf(buff + len,"%d",root->data);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    len +=sprintf(buff + len,"(");
    __serialize(root->lchild);
    if(root->rchild){
     len +=sprintf(buff + len,",");
    __serialize(root->rchild);
    }
     len +=sprintf(buff + len,")");
    return ;
}


void serialize(Node *root){
    memset(buff,0,sizeof(buff));
    len = 0;
    __serialize(root);
    return ; 
}

void printf(Node *node){
    printf("%d(%d, %d)\n",KEY(node),
           KEY(node->lchild),
           KEY(node->rchild));
    return ;
}

void output(Node *root){
    if(root == NULL) return ;
    printf(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}



int main(){
    srand(time(0));
    #define MAX_NODE 10
    Node *root = getRandemBinarytree(MAX_NODE);
    serialize(root);
    output(root);    
    printf("Buff[] : %s\n",buff);
    return 0;
}
