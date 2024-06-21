/*************************************************************************
	> File Name: 6.leetcode-20：括号匹配.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Fri 07 Jul 2023 02:53:35 PM CST
 ************************************************************************/

//  用栈模拟括号匹配过程
//1.遇到左括号就进栈
//2.遇到右括号就与栈顶的左括号做匹配，如果成功，栈顶元素出栈，
//如果失败，说明括号匹配不合法。

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Stack{
    char *data;
    int size,top;
}stack;

Stack *init_Stack(int n){
    Stack *s =(Stack *)malloc(sizeof(Stack));
    s->data =(char *)malloc(sizeof(char)*n);
    s->size = n;
    s->top= -1;
    return s;
}    

int empty(Stack *s){
    return s->top==-1;
}

char top(Stack *s){
    if(empty(s)) return 0;
    return s->data[s->top];
}

int pushStack(Stack *s,char val){
    if(s->top+1 == s->size) return 0;    
    s->top +=1; 
    s->data[s->top]=val;
    return 1;
}

int pop(Stack *s){
    if(empty(s))return 0;
    s->top-=1;
    return 1;
}

void clearStack(Stack *s){
    if(s == NULL)return ;
    free(s->data);
    free(s);
    return ;
}

void solve(char str[]){
    int flag=0;
    Stack *s = init_Stack(100);
    for(int i=0;i<str[i];i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='}'){
            pushStack(s,str[i]);
        }else{
            switch(str[i]){
                case '(':{
                    if(!empty(s)&&top(s)==')')pop(s);
                    else flag =0;
                }break;
                case '{':{
                    if(!empty(s)&&top(s)=='}')pop(s);
                    else flag =0;
                }break;
                case '[':{
                    if(!empty(s)&&top(s)==']')pop(s);
                    else flag=0;
                }break;
            }   
        }
        if(flag=0)break;    
    }   
        if(flag ==0||!empty(s)){
        printf("error :%s\n",str);
        }else{
            printf("success :%s\n",str);
        }        
    clearStack(s);
    return ;
    
  }



int main(){
    char str[100];
    while(~scanf("%s",str)){
        solve(str);
    }
    return 0;
}
