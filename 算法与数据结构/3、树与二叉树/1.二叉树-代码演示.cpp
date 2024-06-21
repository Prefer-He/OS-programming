/*************************************************************************
	> File Name: 1.二叉树-代码演示.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Tue 11 Jul 2023 02:35:47 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
}Node;
    
Node *init_binarytree(int key){
    Node *p =(Node *)malloc(sizeof(Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root){
    if(root == NULL)return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

Node *insert(Node *root,int key){
    if(root == NULL) return init_binarytree(key);
    if(rand() % 2) root->lchild = insert(root->lchild,key);
    else insert(root->rchild,key);
    return root;
}

#define MAX_NODE 10
Node * queue[MAX_NODE + 5];
int head,tail;

void bfs(Node *root){
    head = tail =0;
    queue[tail++] = root;
    while(head<tail){
    Node *node = queue[head];
    printf("\nnode: %d ",node->data);
    if(node->lchild) {
        queue[tail++] = node->lchild;
        printf("\t%d->%d(left)\n",node->data,node->lchild->data);
    }
    if(node->rchild) {
        queue[tail++] = node->rchild;
        printf("\t%d->%d(right)\n",node->data,node->rchild->data);
    }
    head++;
    return ;
    
    }
}

int tot = 0;
void dfs(Node *root){
    if(root ==NULL) return ;
    int start,end;
    tot += 1; 
    start=tot;
    if(root->lchild) dfs(root->lchild);
    if(root->rchild) dfs(root->rchild);
    tot += 1;
    end = tot;
    printf("%d : [%d,%d]\n",root->data,start,end);
}

int main()
{
    srand(time(0));
    Node *root = NULL;
    for(int i = 0 ; i<MAX_NODE;i++){
    root = insert(root,rand() % 100);
    }
    bfs(root);
    dfs(root);
    return 0;
}

