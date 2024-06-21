/*************************************************************************
	> File Name: 7.N叉树的前序遍历-leetcode-589.cpp
	> Author:hepeiyang 
	> Mail:2794273689@qq.com
	> Created Time: Sun 15 Oct 2023 03:48:20 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

class Node{
    int val;
    vector<Node*> children;
    
    Node() {};
    
    Node(int _val){
        val = _val;
    }

    Node(int _val,vector<Node*> _children){
        val = _val;
        children = _children;
    }

};

void __preorder(Node *root,vector<int> &ans){
    if(root == NULL) return ;
    ans.oush_back(root->val);
    for(auto x :root->children)
        __preorder(x,ans);
    return ;
}


vector<int> preorder(Node *root){
        vector<int> ans;
        __preorder(root,ans);
        return ans;
    };

int main(){
    Node *root;
    return 0;
}

