#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):data(x),left(nullptr),right(nullptr){}
};
stack<char> s;
void Leaf1(TreeNode* root)//前序遍历
{
    if(root==nullptr) return;
    if(root->left==nullptr&&root->right==nullptr) s.push(root->data);
    Leaf1(root->left);
    Leaf1(root->right);
}

void reversePrint()
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{

    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');
    root->right->left = new TreeNode('F');
    root->right->right = new TreeNode('G');

    // 调用 Leaf1 函数，遍历并存储叶子节点
    Leaf1(root);

    reversePrint();
    return 0;
}