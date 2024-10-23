#include<iostream>
#include<cmath>
using namespace std;
struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):data(x),left(nullptr),right(nullptr){}
};

int MinD(TreeNode* root)
{
    if(root==nullptr) return 0;//
    if(root->left==nullptr&&root->right==nullptr) return 1;
    else if(root->left==nullptr) return MinD(root->right)+1;
    else if(root->right==nullptr) return MinD(root->left)+1;
    else return min(MinD(root->left),MinD(root->right))+1;
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
    root->left->left->left = new TreeNode('H');
    root->right->left->right = new TreeNode('I');
    // 求最小枝长
    cout<<MinD(root);

    return 0;
}
