/*************************************************************************
	> File Name: 3.队列-顺序表实现.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 07 Jul 2023 02:49:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct vector{  //定义顺序表
    int *data;  //顺序表的整型变量存储区
    int size;  //顺序表大小
}vector;

vector *init_vector(int n){   //传入顺序表大小并返回 指针
    vector *v=(vector *)malloc(sizeof(vector)); //获取顺序表的空间
    v->size=n;  //  size大小为n
    v->data=(int *)malloc(sizeof(int)*n);  //开辟data指针存储的空间
    return v;  //*v所指的空间就是顺序表的地址，也就是顺序表
}

void clearVector(vector *v){  //传入顺序表的指针
    if(v==NULL)return ;  //判空
    free(v->data);   //先释放数据存储区 否则这段数据会存留在内存中 造成内存浪费
    free(v);  //再销毁顺序表本身
    return ;  //void没有返回值
}

int vectorSeek(vector *v,int pos){   //查找操作传入顺序表、要插入的位置
    if(pos<0||pos>=v->size)return -1;  //判断是否可以插入
    return v->data[pos];  //返回数据存储区要插入（pos）的位置
}


int insert_vector(vector *v,int pos,int val){ //  传入顺序表指针、要插入的位置、要插入的元素
    if(pos<0||pos>=v->size)return 0;  //判空  经典操作
    v->data[pos]=val;  //把要插入的元素插入顺序表数据存区的pos位置
    return 1;
}




//假设我们已经有一个顺序表了，然后使用这个顺序表操作
typedef struct Queue{  //数据结构= 结构定义 + 结构操作 9行以前为结构定义
    vector *data;  //数据存储区  vector是一个结构变量，后跟一个 *data表示与vector同属一个类型
    int count,head,tail;
}Queue;


//队列初始化
Queue *init_Queue(int n){  //传入队列大小并返回该队列
    Queue *q=(Queue *)malloc(sizeof(Queue));  //开辟队列空间
    q->data = init_vector(n);   // 该队列的数据存储区就是上述顺序表也就是 *v
    q->size = n;  // 此时队列大小为n
    q->head = q->tail = q -> count= 0;  //一开始head、tail重叠也就是空的
    return q;
}

int empty(Queue *q){  //判空操作
    return q->count==0;//返回队列内有多少元素
}

int push(Queue *q,int val){  //入队操作
    if(q->count==q->size)return 0;  //count、size指针重叠表示没有位置，入队失败
    insert_vector(q->data,q->tail,val);  //
    q->tail +=1;  //尾指针加一
    if(q->tail==q->size)q->tail=0;  //防止尾指针越界
    q->count+=1;  //元素加一
    return 1; //入队成功
}

int pop(Queue *q){  //出队操作传入队列q
    if(empty(q))return 0;  
    q->head +=1;  //出队头指针
    q->count- =1;  //count少一个
    return 1;  //成功出队
}

int front(Queue *q){  //查看队首元素
    return vector_seek(q->data,q->head);
}

 

void *clearQueue(Queue *q){
    if(q== NULL)return 0;
    clearVctor(q->data);
    free(q);
    return ;
}



int main()
{




    return 0;
}






