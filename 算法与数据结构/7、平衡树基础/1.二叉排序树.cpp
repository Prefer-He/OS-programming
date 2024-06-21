/*************************************************************************
	> File Name: 1.二叉排序树.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 27 Oct 2023 10:47:08 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int key;
    struct Node *lchild,*rchild;
}Node;

Node *getNewNode(int key){
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root,int key){
    if(root == NULL) return getNewNode(key);
    if(key < root->key) root->lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild,key);
    return root;
}

Node *predecessor(Node *root){
    Node *temp = root->lchild;
    while(temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root,int key){
    if(root == NULL) return NULL;
    if(key < root->key) root->lchild = erase(root->lchild,key);
    else if(key > root->key) root->rchild = erase(root->rchild,key);
    else {
        if(root->lchild == NULL && root->rchild == NULL){
            free(root);
            return NULL;
        }else if(root->lchild == NULL || root->rchild == NULL){
            Node *temp = (root->lchild == NULL? root->lchild : root->rchild);
            free(root);
            return temp;
        }else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild,temp->key);
        }
    }
    return root;
}

void clear(Node *root){
    if(root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}



int main(){
    srand(time(0));


    return 0;
}
