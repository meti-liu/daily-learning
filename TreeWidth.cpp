#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):data(x),left(nullptr),right(nullptr){}
};

int maxWidth(TreeNode* root)
{
    if(root==nullptr) return 0;



    queue<TreeNode*> q;//队列即BFS，不需要递归
    q.push(root);
    int MaxW=0;

    while(!q.empty())
    {
        int LevelW=q.size();
        MaxW=max(MaxW,LevelW);
        for(int i=1;i<=LevelW;i++)//关键点在于当前队列有几个元素就进行几次增加子节点的操作
        {
            TreeNode* p=q.front();//备份队首节点
            q.pop();//先出队列再操作
            if(p->left!=nullptr) q.push(p->left);//增加子节点
            if(p->right!=nullptr) q.push(p->right);
        }
    }

    return MaxW;
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
    cout<<maxWidth(root);
}
