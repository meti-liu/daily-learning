#include<iostream>
using namespace std;
//头插法
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
        Node* s=cur;
        cur=cur->next;
        if(s->data<0)
        {
            s->next=L1.head;
            L1.head=s;
        }
        else if(s->data>=0)
        {
            s->next=L2.head;
            L2.head=s;
        }
    }
    return merge(L1,L2);
}

void printList(LinkList& L) 
{
    Node* cur = L.head;
    while (cur != nullptr) 
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}


int main()
{
    Node* n1 = new Node{1, nullptr};
    Node* n2 = new Node{-2, nullptr};
    Node* n3 = new Node{3, nullptr};
    Node* n4 = new Node{-4, nullptr};


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    LinkList list(n1);

    cout << "origin: ";
    printList(list);

    list = move(list);

    cout << "adjusted: ";
    printList(list);

    return 0;
}