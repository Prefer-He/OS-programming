/*************************************************************************
	> File Name: 3.红黑树-插入调整.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sat 11 Nov 2023 03:12:33 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define black  0
#define red    1
#define dblack 2
#define NIL (&__NIL)
#define R(n) (n->rchild)
#define L(n) (n->lchild)
#define C(n) (n->color)
#define K(n) (n->key)



typedef struct Node{
    int key,color; // 0 black 1 red 2 Double black
    struct Node *lchild,*rchild;
}Node;
Node __NIL;

__attribute__((constructor))
void init_NIL(){
    NIL->key   = -1;
    NIL->color = black;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key){
    Node *p = (Node *)malloc(sizeof(Node));
    p->key   = key;
    p->color = red;
    p->lchild = p->rchild = NIL;
    return p;
}

bool has_red_Node(Node *root){
    return C(L(root)) == red || C(R(root)) == red;
}

Node *left_rotate(Node *root){
    Node *new_root = root->rchild;
    root->rchild = new_root->lchild;
    new_root->lchild = root;
    return new_root;
}

Node *right_rotate(Node *root){
    Node *new_root = root->lchild;
    root->lchild = new_root->rchild;
    new_root->rchild = root;
    return new_root;
}


Node *__maintain(Node *root){
    int flag = 0; //判断冲突方向
    if(C(L(root)) == red && has_red_Node(L(root))) flag = 1;
    if(C(R(root)) == red && has_red_Node(R(root))) flag = 2;
    if(flag == 0) return root;
    if(C(L(root)) == red && C(R(root)) == red) goto red_up_maintain; 
    if(flag == 1){
        if(C(R(L(root))) == red){
            L(root) = left_rotate(L(root));
        }
        root = right_rotate(root);
    }else{
        if(C(L(R(root))) == red){
            R(root) = right_rotate(R(root));
        }
        root = left_rotate(root);
    }

red_up_maintain:
    C(root) = red;
    C(L(root)) == C(R(root)) == black; 
    return root;
}



Node *__insert(Node *root,int key){
    if(root == NIL) return getNewNode(key);
    if(key == root->key) return root;
    else if(key < root->key) root->lchild = __insert(root->lchild,key);
    else root->rchild = __insert(root->rchild,key);
    return __maintain(root);
}

Node *insert(Node *root,int key){
    __insert(root,key);
    root->color = black;
    return root;
}

void clear(Node *root){
    if(root =+ NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}


int main(){
    srand(time(0));    

    return 0;
}
