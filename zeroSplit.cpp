#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


class LinkList
{
public:
    Node* head;
    LinkList()
    {
        this->head=nullptr;
    }
    LinkList(Node* head)
    {
        this->head=head;
    }
};

LinkList merge(LinkList& L1,LinkList& L2)
{
    Node* cur=L1.head;
    while(cur->next!=nullptr)
    {
        cur=cur->next;
    }
    cur->next=L2.head;
    return L1;
}

LinkList move(LinkList& L)
{
    Node* cur=L.head;
    LinkList L1,L2;
    while(cur!=nullptr)
    {
        if(cur->data<0)//小于0的数据放进链表L1
        {
            Node* s=cur;
            s->next=L1.head;
            L1.head=s;
        }
        else if(cur->data>=0)
        {
            Node* s=cur;
            s->next=L2.head;
            L2.head=s;
        }
        cur=cur->next;
    }
    return merge(L1,L2);
}


int main()
{

}