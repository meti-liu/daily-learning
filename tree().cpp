#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct TreeNode
{   
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


void createBtree(string str)
{
    TreeNode* p;
    stack<TreeNode*> st;
    bool flag;//true->left false->right
    int i=0;
    // int root_num=0;
    // while(str[i]<='9'&&i<str.length())
    // {

    //     i++;
    // }
    while(i<str.length())
    {
        switch (str[i])
        {
        case '('://左括号前的p节点存在孩子节点，入
            flag=true;
            st.push(p);
            break;
        case ')'://p的孩子节点已处理完成，弹
            st.pop();
            break;
        case ','://左进右
            flag=false;
            break;

        default://此时str[i]就只可能是数据val了
            int num=str[i]-'0';//并不严谨，如果num有两位呢
            p=new TreeNode(num);

            break;
        }


        i++;
    }
}