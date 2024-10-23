#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode* dummy=new ListNode(0);
    ListNode* cur=dummy;
    ListNode* cur1=list1;
    ListNode* cur2=list2;

    while(cur1!=nullptr&&cur2!=nullptr)
    {
        if(cur1->val<=cur2->val)
        {
            cur->next=cur1;
            cur1=cur1->next;
        } 
        else
        {
            cur->next=cur2;
            cur2=cur2->next;
        }
        cur=cur->next;  
    }
    if(cur1!=nullptr) cur->next=cur1;
    else if(cur2!=nullptr) cur->next=cur2;
    return dummy->next;
}