#include<iostream>
#include<cmath>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):data(x),left(nullptr),right(nullptr){}
};

void preOrder(TreeNode* root)
{
    if(root==nullptr) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//inorder与postorder同理

int height(TreeNode* root)
{
    if(root==nullptr) return 0;
    int leftH=height(root->left);
    int rightH=height(root->right);
    return max(leftH,rightH)+1;
}