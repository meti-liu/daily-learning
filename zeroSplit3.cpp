#include<iostream>
using namespace std;
//尾插法
struct Node
{
    int data;
    Node* next;
    Node():next(nullptr){}
    Node(int data,Node* next)
    {
        this->data=data;
        this->next=next;
    }

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
    Node* Empty=new Node(0,nullptr);//虚拟头节点，避免空链表判断
    LinkList L1(Empty),L2(Empty);

    Node* tail1 = L1.head; // L1 的尾指针
    Node* tail2 = L2.head; // L2 的尾指针

    while(cur!=nullptr)
    {
        Node* s=cur;
        cur=cur->next;

        s->next=nullptr;

        if(s->data<0)
        {
            if(L1.head==nullptr)
            {
                L1.head=s;
                tail1=s;
            }
            else
            {
            tail1->next=s;
            tail1=s;
            }

        }

        else if(s->data>=0)
        {
            if(L2.head==nullptr)
            {
                L2.head=s;
                tail2=s;
            }
            else
            {
                tail2->next=s;
                tail2=s;
            }

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