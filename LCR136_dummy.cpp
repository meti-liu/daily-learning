#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//dummy优势，无需讨论头节点
ListNode* deleteNode(ListNode* head, int val)
{
    ListNode* dummy=new ListNode(0,head);
    ListNode* cur=dummy;
    while(cur->next!=nullptr)
    {
        if(cur->next->val==val)
        {
            cur->next=cur->next->next;
        }
        else cur=cur->next;
    }
    return dummy->next;
}