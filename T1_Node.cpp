#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
};

// int size(ListNode* head)
// {
//     int num=0;
//     ListNode* cur=head;
//     while(cur!=nullptr)
//     {
//         num++;
//         cur=cur->next;
//     }
//     return num;
// }

// ListNode* rear(ListNode* head)
// {
//     ListNode* cur=head;
//     while(cur!=nullptr) cur=cur->next;
//     return cur;
// }

ListNode* Middle(ListNode* head)//向下取整，课本
{
    ListNode* slow=head->next;
    ListNode* fast=head->next;
    while(fast!=nullptr&&slow!=nullptr)
    {
        if(fast->next==nullptr||fast->next->next==nullptr)
        {
            return slow;
        }
        slow=slow->next;
        fast=fast->next->next;
        return slow;
    }
}

ListNode* Middle1(ListNode* head) 
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* ReverseList(ListNode* head)
{
    ListNode* cur=head;
    ListNode* prev=nullptr;
    while(cur!=nullptr)
    {
        ListNode* next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}


ListNode* Merge(ListNode* head)
{
    ListNode* dummy=new ListNode(0);
    ListNode* cur=dummy;
    ListNode* mid=Middle1(head);
    ListNode* head1=head;
    ListNode* head2=ReverseList(mid->next);
    mid->next=nullptr;//切割链表
    while(head1!=nullptr&&head2!=nullptr)
    {
        cur->next=head2;
        head2=head2->next;
        cur=cur->next;
        cur->next=head1;
        head1=head1->next;
        cur=cur->next;
    }
    if (head1 != nullptr) 
    {
    cur->next = head1;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() 
{
    // 构造一个示例链表
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);


    cout << "Original list: ";
    printList(head);

    ListNode* newHead = Merge(head);

    cout << "Merged list: ";
    printList(newHead);

    return 0;
}