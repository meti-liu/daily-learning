#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node():next(nullptr){}
    Node(int d)
    {
        this->data=d;
        this->next=nullptr;
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

    void insert(int value)
    {
        Node* s=new Node(value);
        s->next=head;
        head=s;
    }

    int length()
    {
        Node* cur=head;
        int l=0;
        while(cur!=nullptr)
        {
            l++;
            cur=cur->next;
        }
        return l;
    }

};



void Split(LinkList& L,int k1,int k2)
{
    Node* cur=L.head;
    LinkList L1,L2,L3;
    while(cur!=nullptr)
    {
        Node* s=cur;
        cur=cur->next;
        if(s->data<k1)
        {
            s->next=L1.head;
            L1.head=s;
        }
        else if(s->data>=k1&&s->data<k2)
        {
            s->next=L2.head;
            L2.head=s;
        }
        else if (s->data>=k2)
        {
            s->next=L3.head;
            L3.head=s; 
        }
    }

    cout<<L1.length()-1<<" "<<L1.length()+L2.length();
    
}



int main()
{
    int k1,k2,n;
    LinkList L;
    cin>>k1>>k2>>n;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        L.insert(temp);
    }

    Split(L,k1,k2);
    return 0;
}