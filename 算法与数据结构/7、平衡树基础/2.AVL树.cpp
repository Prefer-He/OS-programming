/*************************************************************************
	> File Name: 2.AVL树.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sun 29 Oct 2023 03:24:08 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int key,h;
    struct Node *lchild,*rchild;
}Node;

Node __NIT;
#define NIT (&__NIT)
#define K(n) (n->key)
#define H(n) (n->h)
#define L(n) (n->lchild)
#define R(n) (n->rchild)

__attribute((constructor))
void init__NIT(){
    NIT->key = -1;
    NIT->h = 0;
    NIT->lchild = NIT->rchild = NIT;
    return ;
}

Node *getNewNode(int key){
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIT;
    return p;
}

void updata_height(Node *root){
    H(root) = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
    return ;

}

Node *left_rotate(Node *root){
    Node *new_node = root->rchild;
    root->rchild = new_node->lchild;
    new_node->lchild = root;
    updata_height(root);
    updata_height(new_node);
    return new_node;
}

Node *right_rotate(Node *root){
    Node *new_node = root->lchild;
    root->lchild = new_node->rchild;
    new_node->rchild = root;
    updata_height(root);
    updata_height(new_node);
    return new_node; 
}

Node *maintain(Node *root){
    if(abs(H(R(root)) - H(L(root))) <= 1) return root; 
    if(H(R(root)) > H(L(root))){
        if(H(R(L(root))) > H(L(L(root)))) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    }else{ 
        if(H(L(R(root))) > H(R(R(root)))) {
            root->rchild = right_rotate(root->_child);
        }
        root = left_rotate(root); 
    }
    return root;
}


Node *insert(Node *root,int key){
    if(root == NIT) return getNewNode(key);
    if(key == root->key) return root;
    if(key < root->key) root->lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild,key);
    updata_height(root);
    return maintain(root);
}

Node *predecessor(Node *root){
    Node *temp = root->lchild;
    while(temp->rchild != NIT) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root,int key){
    if(root == NIT) return root;
    if(root->key < key) root->rchild = erase(root->rchild,key);
    else if(key < root->key) root->lchild = erase(root->lchild,key);
    else {
        if(root->lchild == NIT || root->rchild == NIT){
            Node *temp = root->lchild == NIT ? root->lchild : root->rchild;
            free(root);
            return temp;
        }else{
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild,temp->key);
        }
    }
    updata_height(root);
    return maintain(root);
}

Node *find(Node *root,int key){
    if(root == NIT) return NIT;
    if(key == root->key) return root;
    else if(key < root->key) return find(root->lchild,key);
    else return find(root->rchild,key);
}

void clear(Node *root){
    if(root == NIT) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}


int main(){
    srand(time(0));

    return 0;
}
