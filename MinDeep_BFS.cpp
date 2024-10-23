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

int MinD(TreeNode* root)
{
     if (root == nullptr) return 0; // 空树，深度为0
    queue<TreeNode*> q;
    q.push(root);
    int depth=0;

    while(!q.empty())
    {
        int L=q.size();
        depth++;
        for(int i=1;i<L;i++)
        {
            TreeNode* p=q.front();
            q.pop();
            if(p->left!=nullptr) q.push(p->left);
            if(p->right!=nullptr) q.push(p->right);
            if(p->left==nullptr&&p->right==nullptr) return depth;
        }
        
    }
    return depth;
}

int main() {
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');

    // 求最小枝长
    cout<<MinD(root);

    return 0;
}