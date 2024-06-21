/*************************************************************************
	> File Name: 6.哈夫曼编码-代码演示.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 14 Jul 2023 10:58:04 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{  
    char ch;
    int freq;
    struct Node *lchild,*rchild;
}Node;

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
    if(root->lchild == NULL && root->rchild == NULL){
        printf("%c : %s\n",root->ch,buff);
        return ;
    }
    buff[k] = '0';
    extractHaffmanCode(root->lchild,buff,k + 1);
    k = '1';

    extractHaffmanCode(root->rchild,buff,k + 1);
    return ;
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
