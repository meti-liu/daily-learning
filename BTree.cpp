#include<string>
#include<stack>
#include<iostream>
using namespace std;
//二叉链表
struct BTNode
{
    char data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode():lchild(nullptr),rchild(nullptr){}
    BTNode(char d)
    {
        data=d;
        lchild=rchild=nullptr;
    }
};

class BTree
{
    BTNode* r;//根节点r
public:
    BTree(){r=nullptr;}

};

void CreatBTree(string str)
{
    stack<BTNode*> st;
    BTNode* p;
    bool flag;
    int i=0;
}