#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
};
//三指针
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev=nullptr;
        ListNode* cur=head;
        while(cur!=nullptr)
        {
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;//注意不是null，此时cur指向null
    }