#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data):data(data),next(nullptr){}
};
class LinkList
{
public:
    Node* head;
    LinkList()
    {
        this->head=nullptr;
    }
    LinkList(Node* h)
    {
        this->head=h;
    }
};

int MaxNode(LinkList& L)
{
    Node* cur=L.head;
    int maxValue=cur->data;
    int maxIndex=0;
    int currentIndex=0;

    while(cur->next!=nullptr)
    {
        if(cur->data>=maxValue)
        {
            maxValue=cur->data;
            maxIndex=currentIndex;
        }
        currentIndex++;
        cur=cur->next;
    }

    return maxIndex;
}


int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(-2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(-4);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    LinkList list(n1);
    cout<<MaxNode(list);
}