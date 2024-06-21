/*************************************************************************
	> File Name: 2.链表.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Wed 05 Jul 2023 11:19:22 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define DIGIT_LEN

typedef struct Node{ 
   int data;
   struct Node *next;   //该结点的指针
}Node;


//Node是待插入的新的结点

Node *getNewNode(int val){   //定义一个*p，使用这个*p来改变结点指针的指向，不能直接改变结点间的指针指向
   Node *p=(Node*)malloc(sizeof(Node));  //(Node*)强制类型转换,开辟新结点空间
   p->data=val;  //存放数据
   p->next=NULL;   //NULL为后续插入、删除做准备
   return p;  //返回指针
}
  //insert函数返回的是此时新链表头结点的首地址，*head是在主函数中定义的
   Node *insert(Node *head,int pos,int val){  //链表的插入操作。*head表示头结点，pos表示插入位置，val表示新插入结点
    if(pos==0){                       //判断新结点插入位置是否是第一个位置（首位）
        Node *p=getNewNode(val);  //把val的值变成一个新的结点。前面说过了，使用*p来操作指针的改变，不能结点之间直接操作，可能造成数据丢失
        p->next=head;  //改变头结点
        return p ;  //返回指针  我们此时写的是无头链表，*head并没有数据存储
    }
    Node *p = head;  //*p一开始自head位置，27行表示让p走到待插入位置的前一个元素的位置并指向
    for(int i=1;i<pos;i++)p=p->next;//p->next一开始为NULL
    Node*node=getNewNode(val); //新结点初始化出来  
    node->next=p->next;
    p->next=node;
    return head;
   }


   Node *insert(Node *head,int pos,int val){
    Node new_Node,*p=&new_head,*node=getNewNode(val);
    new_head,next=head;
    for(int i=0;i<pos;i++)p=p->next;
    node->next=p->next;
    p->next=node;
    return new_head.next;
    
   }


void clear(Node*head)[
     if(head == NULL) return ;
     for(Node *p=head,*q;p;p=q){
       q = p->next;
       free(p);
     }
     return ;
]



void output_linklist(Node *head, int flag = 0) {
    int n = 0;
    for (Node *p = head; p; p = p->next) n += 1;
    for (int i = 0; i < n; i++) {
        printf(DIGIT_LEN_STR(DL), i);
        printf("  ");
    }
    printf("\n");
    for (Node *p = head; p; p = p->next) {
        printf(DIGIT_LEN_STR(DL), p->data);
        printf("->");
    }
    printf("\n");
    if (flag == 0) printf("\n\n");
    return ;
}


int find(Node*head,int val){
    Node *p=head;
    while(p1=NULL){
       if(p->data=val)
       output_linklist(head 1)
       int len=n*(DL+2)+2;
       for(int i=0;i<len;i++)printf("");
       printf("^\n");
       for(int i=0;i<len;i++)printf("");
       prinf("|\n");
       return 1;
    }else{
       p=p->next;
    }
    return 0;
    n+=1;
    p=p->next;

}

int main(){
   rand(time(0));
    #define MAX_OP 7
    Node *head = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int pos = rand() % (i + 1), val = rand() % 100;
        printf("insert %d at %d to linklist\n", val, pos);
        head = insert(head, pos, val);
        output_linklist(head);
    }
    int val;
    while (~scanf("%d", &val)) {
        if (!find(head, val)) {
            printf("not found\n");
        }
    }
    clear(head);
    return 0;
}




