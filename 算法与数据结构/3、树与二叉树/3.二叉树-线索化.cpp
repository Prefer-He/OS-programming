/*************************************************************************
	> File Name: 2.二叉树-遍历与线索化.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Thu 13 Jul 2023 03:41:39 PM CST
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <time.h> 
#include <stdlib.h>

typedef struct Node{
    int data;
    int ltag,rtag; //1 : thread , 0 : edge ;:w
    struct Node *lchild,*rchild;
}Node;

Node *init_binary(int key){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = key;
    p->rtag = p->ltag = 0;
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
    if(root->ltag == 0)free(root->lchild);
    if(root->rtag == 0)free(root->rchild);
    free(root);
    return ;
}


void pre_order(Node *root){
    if(root == NULL) return ;
    printf("%d ",root->data);
    if(root->ltag == 0) pre_order(root->lchild);
    if(root->rtag == 0) pre_order(root->rchild);
    return ;
}

void in_order(Node *root){
    if(root == NULL) return ;
    if(root->ltag == 0) in_order(root->lchild); 
    printf("%d ",root->data);
    if(root->rtag == 0) in_order(root->rchild);
    return ;
}

void post_order(Node *root){
    if(root == NULL) return ;
    if(root->ltag == 0) post_order(root->lchild); 
    if(root->rtag == 0) post_order(root->rchild); 
    printf("%d ",root->data);
    return ;
}

Node *pre_node =  NULL;

void __build_inorder_thread(Node *root){
    if(root == NULL) return ;
    if(root->ltag == 0) __build_inorder_thread(root->lchild);
    if(root->lchild == NULL){
        root->lchild = pre_node;
        root->ltag = 1;
    }
    if(pre_node && pre_node->rchild == NULL){
        pre_node->rchild = root;
        pre_node->rtag = 1;
    }
    pre_node = root;
    if(root->rtag == 0) __build_inorder_thread(root->rchild);
    return ;
}

void build_inorder_thread(Node *root){
    __build_inorder_thread(root);
    pre_node->rchild = NULL;
    pre_node->rtag = 1;
    return ;
}

Node *getNext(Node *root){
    

}


int main(){
    srand(time(0)); 
    Node *root = NULL;
    #define MAX_NODE 10
    for(int i=0;i<MAX_NODE;i++){
        root = insert(root,rand() % 100);
    }
    pre_node = NULL;   
    build_inorder_thread(root);
    pre_order(root);   printf("\n");
    in_order(root);    printf("\n");
    post_order(root); printf("\n");
    //like linklist
    Node *node = root;
   while(node){
    printf("%d ",node->data);
    node = getNext(node); 
 }
    printf("\n");
    clear_binary(root);
  return 0;
}
