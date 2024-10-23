#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
};


ListNode* deleteNode(ListNode* head,int val)
{
    if(head==nullptr) return nullptr;

    while(head!=nullptr&&head->val==val)
    {
        head=head->next;
    }
    if(head==nullptr) return nullptr;

    ListNode* cur=head;

    while(cur->next!=nullptr)
    {
        if(cur->next->val==val) cur->next=cur->next->next;
        else  cur=cur->next;    
    }
    return head;
}