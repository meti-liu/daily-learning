#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
};

//双指针删除节点

class Solution {
public:
    ListNode* removeElements(ListNode* head,int val)
    {
        if(head==nullptr) return nullptr;

        while(head!=nullptr&&head->val==val)
        {
            ListNode*q=head;
            head=head->next;
            delete q;
        }
        if(head==nullptr) return nullptr;
        ListNode* pre=head;
        ListNode* cur=head->next;
        while(cur!=nullptr)
        {
            if(cur->val==val)
            {
                ListNode* q=cur;
                pre->next=cur->next;
                cur=cur->next;
                delete q;
            }
            else
            {
                pre=cur;
                cur=cur->next;
            } 
        
        }
        return head;
    }
};