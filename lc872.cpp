#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

struct TreeNode
{   
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};



void dfs(TreeNode* root, vector<int>& leaf)
{
    if(root==nullptr) return;
    if(root->left==nullptr&&root->right==nullptr) leaf.push_back(root->val);
    dfs(root->left,leaf);
    dfs(root->right,leaf);

}


TreeNode* createBtree(string str)//括号表达式来生成树
{
    TreeNode* p=nullptr;
    stack<TreeNode*> st;
    bool flag;//true->left false->right
    int i=0;


    TreeNode* root=nullptr;

    while(i<str.length())
    {
        switch (str[i])
        {
        case '('://左括号前的p节点存在孩子节点，入
            flag=true;
            st.push(p);
            i++;
            break;
        case ')'://p的孩子节点已处理完成，弹
            if(!st.empty())//请注意，这个点很重要
            {
                st.pop();
                i++; 
            }
            break;
        case ','://左进右
            flag=false;
            i++;
            break;

        default://此时str[i]就只可能是数据val了
            int num=0;
            while(isdigit(str[i]))
            {
                num=10*num+(str[i]-'0');
                i++;
            }
            p=new TreeNode(num);
            if(root==nullptr) root=p;
            if(flag==true&&!st.empty()) st.top()->left=p; 
            if(flag==false&&!st.empty()) st.top()->right=p;
            break;
        }

    }
    return root;
}


bool leafSimilar(TreeNode* root1,TreeNode* root2)
{
    vector<int> leaf1;
    vector<int> leaf2;
    dfs(root1,leaf1);
    dfs(root2,leaf2);
    if(leaf1==leaf2) return true;
    else return false;
}

int main()
{
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    TreeNode* root1=createBtree(str1);
    TreeNode* root2=createBtree(str2);
    if(leafSimilar(root1,root2)) cout<<"true";
    else cout<<"false";
    return 0;
}