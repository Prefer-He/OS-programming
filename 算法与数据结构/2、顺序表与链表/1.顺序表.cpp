/*************************************************************************
	> File Name: 1.顺序表.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Thu 06 Jul 2023 03:33:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>//数据结构=结构定于+结构操作  3-7行属于结构定义  之后属于结构操作
#include <time.h>

typedef struct vector{  //typedef struct sth{},  sth.A sth.*p .                                                                         
    int size,count;   //定义线性表 size表示一共有多大  count表示现在存储了多少个元素
    int *data;  //定义一个整形指针，等会*data会指向线性表的存储区域。
}vector;    //vector这个类型的结构里面有一个叫 vector

vector *getNewVector(int n){   //得到一个顺序表并初始化 传入一个n表示顺序表多大 
    vector *p=(vector*)malloc(sizeof(vector));   //p->size=*p.size ，vector *p定义了*p这个指针用于存放这个数据表
    p->size=n;                                   //所需要多少空间  （vector*）是强制类型转换 
    p->count=0;
    p->data=(int*)malloc(sizeof(int)*n);     //p->data=*p.data *p自身就是一个vector类型的结构
    return p;                                //所以p->data就存放了线性表中n个int类型的数据 
}

int expand(vector*v){
    if(v==NULL)return 0;
        printf("expand v from %d to %d \n",v->size,2*v->size);    
        int *p=(int *)realloc(v->data,sizeof(int)*2*v->size);  //realloc第一个参数是我们希望重新分配地区的首地址
    if(p==NULL)return 0;
    v->data=p;
    v->size*=2;
    return 1;                                                     //       第二个参数是我们希望分配的内存大小 
}


int insert(vector*v,int pos,int val){   //顺序表的插入操作，插入操作：假设一共有5个数据，在0和1号数据中间插入一个数据 pos表示要插入的这个位置
    if(pos<0||pos>v->count)return 0;    //判断位置的合法性                      
                                        //就必须把2、3、4号数据向后移动一位，在进行插入操作，所以定义了一个*v表示顺序表的首地址，
                                        //pos表示我要在那个位置插入，val表示要插入的数据       
    if(v->size==v->count&& !expand(v))return 0;  //表示顺序表存满了
    for(int i=v->count-1;i>=pos;i--){  //逆序遍历  如果采用正序遍历会丢失一个元素
        v->data[i+1]=v->data[i];   //如果这里是count-1，那么>=就正确，随之count对应>号！！！
    }
    v->data[pos]=val;
    v->count+=1;
    return 1;//表示插入成功
}


int erase(vector*v,int pos){    //顺序表的删除操作  *v表示首地址，pos表示要删除的位置
    if(pos<0||pos>=v->count)return 0;  //  判断位置的合法性
    for(int i=pos+1;i<v->count;i++){   //直接把pos那个位置的元素吞掉，并且让后面的元素向前移动一位
        v->data[i-1]=v->data[i];
    }
v->count-=1;  //count+1
return 0; //表示删除成功
}

void output(vector *v) {
    int len = 0;
    for (int i = 0; i < v->size; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < v->count; i++) {
        printf("%3d", v->data[i]);
    }
    printf("\n");
    printf("\n\n");
    return ;
}






void clear(vector *v){  //有顺序表的创建就一定有销毁  *v表示顺序表的首地址，销毁其实就是销毁顺序表中的那段连续的存储区
    if(v==NULL)return;   
    free(v->data);      //*v.data
    free (v);
    return;
}



int main()
{
   srand(time(0));
    #define MAX_OP 20
    vector *v = getNewVector(20);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, pos, val, ret;
        switch (op) {
            case 0:
            case 1:
            case 2:
                pos = rand() % (v->count + 2);
                val = rand() % 100;
                ret = insert(v, pos, val);
                printf("insert %d at %d to vector = %d\n", 
                    val, pos, ret);
                break;
            case 3:
                pos = rand() % (v->count + 2);
                ret = erase(v, pos);
                printf("erase item at %d in vector = %d\n", 
                    pos, ret);
                break;
        }
        output(v);
    }
    clear(v);
    return 0;
}







