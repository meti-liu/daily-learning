#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* Middle1(ListNode* head)//向下取整，课本
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=nullptr)
    {
        if(fast->next==nullptr||fast->next->next==nullptr)
        {
            return slow;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
}

ListNode* Middle2(ListNode* head)//向上取整
{
    ListNode* slow=head;
    ListNode* fast=head;

}